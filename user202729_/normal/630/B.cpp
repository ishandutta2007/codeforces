#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
	int n;
	long t;
	std::cin >> n;
	std::cin >> t;
	std::cout << std::setprecision(20) << (long double) n * powl(1.000000011l, t);
}