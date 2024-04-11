#include <iostream>

int main() {
	int n;
	std::cin >> n;
	if(n % 2 == 1) {
		std::cout << "0\n";
	} else {
		std::cout << (n + 3) / 4 - 1 << '\n';
	}
}