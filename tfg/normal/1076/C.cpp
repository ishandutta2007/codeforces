#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>
#include <cmath>
#include <iomanip>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	std::cout << std::setprecision(10) << std::fixed;
	while(t--) {
		long long d;
		std::cin >> d;
		if(d == 1 || d == 2 || d == 3) {
			std::cout << "N\n";
			continue;
		}
		std::cout << "Y ";
		long double x = (d - sqrtl(d * d - 4 * d)) / 2;
		long double y = d - x;
		std::cout << x << ' ' << y << '\n';
	}
}