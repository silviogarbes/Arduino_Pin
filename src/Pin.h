#ifndef Pin_h // Se não definido o Pin_h
#define Pin_h // Define o PushButton_h
#include <Arduino.h> // Usa alguns recursos padrão do arduino ex. pinMode

class Pin {
  private:
    int number;
    bool isDigital; // (0) analog, (1) digital
    byte mode = INPUT; // (0) INPUT, (1) OUTPUT, (2) INPUT_PULLUP
    int level = LOW; // (0) LOW, (1) HIGH [DIGITAL] | 0 - 500 [DIGITAL PWM] | 0 - 500 [ANALOG]
    unsigned long lastDebounceTime = 0; // [DEBOUNCE] Variável utilizada na temporização
    unsigned long debounceDelay = 50; // [DEBOUNCE] tempo para estabilizar e minimizar o efeito bouncing
    bool lastLevel = LOW; // [DEBOUNCE] variável para identificar mudança de estado

  public:
    Pin(int);
    void setToDigital(); // Somente se quiser usar uma porta analogica como digital
    void setMode(byte); // (0) INPUT, (1) OUTPUT, (2) INPUT_PULLUP
    void setDebounceDelay(unsigned long); // Tempo de debounce. O padrão é 50 ms
    int read(); // digitalRead 0 - 1 ou analogRead 0 - 500
    bool readWithDebounce(); // digitalRead com debounce
    void write(bool); // digitalWrite 0 ou 1
    void writePwm(int); // analogWrite 0 - 500
};
 
#endif
