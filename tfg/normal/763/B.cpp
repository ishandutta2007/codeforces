#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::cout << "YES\n";
	while(n--) {
		int x, y, a, b;
		std::cin >> x >> y >> a >> b;
		std::cout << (x & 1) + (y & 1) * 2 + 1 << '\n';
	}
}