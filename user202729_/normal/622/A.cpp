#include <iostream>
#include <cmath>

int main() {
	long long n, k;
	std::cin >> n;
	k = (long long int) ceill(sqrtl(2. * n + 0.25) - 1.5);
	n -= (k * (k + 1)) / 2;
	std::cout << n;
}