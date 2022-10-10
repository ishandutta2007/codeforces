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
		int n, x, y;
		std::cin >> n >> x >> y;
		std::cout << std::max(1, std::min(n, x + y - n + 1)) << ' ' << std::min(n, x + y - 1) << '\n';
	}
}