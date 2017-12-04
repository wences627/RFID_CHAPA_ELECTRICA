#include<string.h>
#include<Keyboard.h>
String codigo_rfid="";
char car;

void setup() {
  // put your setup code here, to run once:
  pinMode(4, OUTPUT);
  Keyboard.begin();
  Serial1.begin(9600);
  while(!Serial){
    ;
    }
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial1.available()>0){
      car = Serial1.read(); 
      codigo_rfid += String(car);
      if(car == '\n'){
        procesarCodigo();
      }                                               
    }
    
      
}

void procesarCodigo(){
   Serial.print(codigo_rfid);
   Serial.println(codigo_rfid.length());
   if(codigo_rfid =="10115522582\r\n"){
      Serial.println("Hola Ernesto");
      abrirPuerta();
   }
   if(codigo_rfid.equals("24542120185\r\n")){
      Serial.println("Hola Hugo");
      abrirPuerta();
   }
   if(codigo_rfid == "11712417446\r\n"){
      Serial.println("Hola Rafo");
      abrirPuerta();
   }
   codigo_rfid="";
}

void abrirPuerta(){
      digitalWrite(4, HIGH);
      delay(10);
      digitalWrite(4, LOW);  
}
