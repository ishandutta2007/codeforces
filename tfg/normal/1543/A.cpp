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
		long long x, y;
		std::cin >> x >> y;
		if(x < y) std::swap(x, y);
		std::cout << x - y << ' ' << (x - y == 0 ? 0LL : std::min(x % (x - y), (x - y) - x % (x - y))) << '\n';
	}
}