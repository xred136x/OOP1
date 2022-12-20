#include<iostream>


class Vehicle {
public:
	// конструктор (параметризованный)
	Vehicle(int newMaxSpeed, const std::string& newColor, const std::string& newType) {
		std::cout << "Construcnor Vehicle()" << '\n';
		maxSpeed = newMaxSpeed;
		color = newColor;
		type = newType;
		s = new char[50];
	}
	//
	//Vehicle() = default;//= Vehicle() {}
	Vehicle(int newMaxSpeed) {
		maxSpeed = newMaxSpeed;
		color = "yellow";
		type = "bus";
	}
	Vehicle() = delete;

	// конструктор копирования
	Vehicle(Vehicle& obj) {
		maxSpeed = obj.getMaxSpeed();
		color = obj.getColor();
		type = obj.getType();
	}
	// деструктор	
	~Vehicle() {
		std::cout << "Distructor Vehicle()" << '\n';
		delete[] s;
	}


	const std::string getType() {
		return type;
	}
	void setType(const std::string& newType) {
		color = newType;
	}


	std::string getColor() {
		return color;
	}
	void setColor(const std::string& newColor) {
		color = newColor;
	}
	// геттер
	int getMaxSpeed() {
		return maxSpeed;
	}
	// сеттер
	void setMaxSpeed(int newSpeed) {
		maxSpeed = newSpeed;
	}
	// перегрузка оператора == (эквивалентности)
	bool operator == (Vehicle& other) {
		if (maxSpeed == other.maxSpeed && color == other.color && type == other.type) {
			return true;
		}
		return false;
	}
private:
	
	int counter;
	int maxSpeed;
	std::string color;
	std::string type;
	char* s;
};


int main() {
	int x = 5;
	int y = 5;


	//Vehicle car(20, "black", "van");
	Vehicle originalCar(15, "White", "bus");
	Vehicle newCar(originalCar);
	Vehicle foreignCar(15, "White", "asd");

	std::cout << (originalCar == newCar) << '\n';
	std::cout << "=====\n";
	std::cout << (originalCar == foreignCar) << '\n';
	//std::cout << originalCar.getMaxSpeed() << " " << originalCar.getColor() <<
	//	' ' << originalCar.getType() << '\n';
	//std::cout << "========================================\n";
	//std::cout << originalCar.getMaxSpeed() << " " << originalCar.getColor() <<
	//	' ' << originalCar.getType() << '\n';
	//std::string carColor = car.getColor();
	//std::cout << "carColor: " << carColor << " car.getColor() " << car.getColor() << '\n';
	//carColor = "green";
	//std::cout << "carColor: " << carColor << " car.getColor() " << car.getColor() << '\n';
	//std::cout << "Max speed is: " << car.getMaxSpeed() << '\n';
	//std::cout << "End of main()" << '\n';

	//const std::string& carType = car.getType();
	//std::cout << "carType: " << carType << " car.getColor() " << car.getType() << '\n';
}

