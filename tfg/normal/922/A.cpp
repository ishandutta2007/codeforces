#include <iostream>

int main() {
	long long x, y;
	std::cin >> x >> y;
	if(x >= y - 1 && (y + x) % 2 == 1 && y > 0 && !(y == 1 && x != 0)) {
		std::cout << "Yes\n";
	} else {
		std::cout << "No\n";
	}
}