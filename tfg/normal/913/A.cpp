#include <iostream>

int main() {
	long long n, m;
	std::cin >> n >> m;
	if(n > 30) {
		std::cout << m << '\n';
	} else {
		std::cout << m % (1 << n) << '\n';
	}
}