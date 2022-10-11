#include <iostream>

int main() {
	int a, b;
	std::cin >> a >> b;
	std::cout << std::min(a, b) << ' ' << (a + b) / 2 - std::min(a, b) << std::endl;
}