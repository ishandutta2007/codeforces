#include <iostream>

int main() {
	int n, k;
	std::cin >> n >> k;
	if(n == 1) {
		if(k == 0) {
			std::cout << "1\n";
		} else {
			std::cout << "-1\n";
		}
	} else if(k < n / 2) {
		std::cout << "-1\n";
	} else {
		k -= n / 2;
		k++;
		std::cout << k << ' ' << k + k;
		for(int i = 2; i < n; i++) {
			std::cout << ' ' << (k <= 1e6 ? int(1e8) : 0) + i;
		}
		std::cout << std::endl;
	}
}