#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		int x[2], y[2];
		std::cin >> x[0] >> y[0] >> x[1] >> y[1];
		std::cout << abs(x[0] - x[1]) + abs(y[0] - y[1]) + (x[0] == x[1] || y[0] == y[1] ? 0 : 2) << '\n';
	}
}