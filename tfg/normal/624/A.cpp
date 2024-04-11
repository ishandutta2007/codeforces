#include <iostream>
#include <iomanip>

int main() {
	long long d, l, v[2];
	std::cin >> d >> l >> v[0] >> v[1];
	std::cout << std::fixed << std::setprecision(12) << (l - d) / (double) (v[0] + v[1]) << '\n';	
}