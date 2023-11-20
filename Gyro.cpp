#include <Wire.h>

void start_gyro() {
    if (type == 2 || type == 3) {
        // Configuration for gyroscope with type 2 or 3
        Wire.beginTransmission(address);
        Wire.write(0x20);
        Wire.write(0x0F);
        Wire.endTransmission();

        Wire.beginTransmission(address);
        Wire.write(0x20);
        Wire.endTransmission();
        Wire.requestFrom(address, 1);
        while (!Wire.available());

        Serial.print(F("Register 0x20 is set to:"));
        Serial.println(Wire.read(), BIN);

        Wire.beginTransmission(address);
        Wire.write(0x23);
        Wire.write(0x90);
        Wire.endTransmission();

        Wire.beginTransmission(address);
        Wire.write(0x23);
        Wire.endTransmission();
        Wire.requestFrom(address, 1);
        while (!Wire.available());

        Serial.print(F("Register 0x23 is set to:"));
        Serial.println(Wire.read(), BIN);
    }

    if (type == 1) {
        // Configuration for gyroscope with type 1
        Wire.beginTransmission(address);
        Wire.write(0x6B);
        Wire.write(0x00);
        Wire.endTransmission();

        Wire.beginTransmission(address);
        Wire.write(0x6B);
        Wire.endTransmission();
        Wire.requestFrom(address, 1);
        while (!Wire.available());

        Serial.print(F("Register 0x6B is set to:"));
        Serial.println(Wire.read(), BIN);

        Wire.beginTransmission(address);
        Wire.write(0x1B);
        Wire.write(0x08);
        Wire.endTransmission();

        Wire.beginTransmission(address);
        Wire.write(0x1B);
        Wire.endTransmission();
        Wire.requestFrom(address, 1);
        while (!Wire.available());

        Serial.print(F("Register 0x1B is set to:"));
        Serial.println(Wire.read(), BIN);
    }
}
