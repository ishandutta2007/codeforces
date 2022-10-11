#include <iostream>

int main() {
	int a, b, c;
	std::cin >> a >> b >> c;
	for(int i = 1; i <= b + 10; i++) {
		a *= 10;
		if(a / b == c) {
			std::cout << i << '\n';
			return 0;
		}
		a %= b;
	}
	std::cout << "-1\n";
}