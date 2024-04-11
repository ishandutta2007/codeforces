#include <iostream>

int main() {
	int k, d;
	std::cin >> k >> d;
	if(k > 1 && d == 0) {
		std::cout << "No solution\n";
		return 0;
	}
	std::cout << d;
	for(int i = 1; i < k; i++) {
		std::cout << 0;
	}
	std::cout << std::endl;
}