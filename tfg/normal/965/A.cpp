#include <iostream>

int main() {
	long long k, n, s, p;
	std::cin >> k >> n >> s >> p;
	n = (n + s - 1) / s * k;
	std::cout << (p + n - 1) / p << std::endl;
}