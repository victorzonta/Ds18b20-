#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 16, 2);
OneWire onewire (2);
DallasTemperature sensor (&onewire);
float temperatura;

void setup() {
lcd.init();
Serial.begin(9600);
sensor.begin();
}

void loop() {
lcd.backlight();
sensor.requestTemperatures();
temperatura =  sensor.getTempCByIndex(0);
Serial.println(temperatura);
lcd.setCursor(0,0);
lcd.print(F("Temperatura:"));
lcd.setCursor(5,1);
lcd.print(temperatura);
lcd.write(223); // Caracter °
lcd.print(F("C"));
delay(100);
}