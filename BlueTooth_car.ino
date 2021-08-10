    

char state;


class Motor {
  int positiveWire;
  int negativeWire;
public:
  Motor(int positiveWire , int negativeWire) {
    this->positiveWire = positiveWire;
    this->negativeWire = negativeWire;
  }

  void setIdlePosition() {
    digitalWrite(positiveWire, LOW);
    digitalWrite(negativeWire, LOW);
  }

  void rotateForward() {
    digitalWrite(positiveWire, HIGH);
    digitalWrite(negativeWire, LOW);
  }

  void rotateBackward() {
    digitalWrite(negativeWire, HIGH);
    digitalWrite(positiveWire, LOW);
  }

};



class Car {
  Motor* rightWheel;
  Motor* leftWheel;
public:

  Car() {
    rightWheel = new Motor(7, 6);
    leftWheel = new Motor(4, 5);
  }

  void moveForward() {
    rightWheel->rotateForward();
    leftWheel->rotateForward();
  }

  void moveBackward() {
    rightWheel->rotateBackward();
    leftWheel->rotateBackward();
  }

  void _stop() {
    rightWheel->setIdlePosition();
    leftWheel->setIdlePosition();
  }

  void turnLeft() {
    rightWheel->rotateForward();
  }

  void turnRight() {
    leftWheel->rotateForward();
  }

  void turnBackRight() {
    leftWheel->rotateBackward();
  }

  void turnBackLeft() {
    rightWheel->rotateBackward();
  }


}C;


void setup() {
  // put your setup code here, to run once:
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0){
    state = Serial.read(); // Reads the data from the serial port
   //state = 72;
    Serial.println(state);
    switch(state)
    {
      case 'S' : C._stop();
      break;
      
      case 'F' : C.moveForward();
      break;
      
      case 'B' : C.moveBackward();
      break;
      
      case 'G' : C.turnLeft();
      break;

      case 'L' : C.turnLeft();
      break;
      
      case 'I' : C.turnRight();
      break;

      case 'R' : C.turnRight();
      break;
      
      case 'H' : C.turnBackLeft();
      break;

      case 'J' : C.turnBackRight();
      break;

      default : C._stop();
      break;
    }
    delay(10);
    //state = 83;
  }
}

//83 : stop
    //76 : left
    //82 : right      //no
    //70 : forward      //no
    //66 : back
    //71 : forard left
    //73 : forward right
    //72 : back left
    //74 : back right
    //118 : horn
    //87 : front light
    //85 : back light
