#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <cmath>
#include <iomanip>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	std::cout << std::fixed << std::setprecision(10);
	while(t--) {
		int n;
		std::cin >> n;
		n *= 2;
		std::cout << (1.0 / tan(acos(-1) / n)) << '\n';
	}
}