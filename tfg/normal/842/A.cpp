#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int l, r, x, y, k;
	std::cin >> l >> r >> x >> y >> k;
	for(int i = x; i <= y && (long long) i * k <= r; i++) {
		if(i * k >= l) {
			std::cout << "YES\n";
			return 0;
		}
	}
	std::cout << "NO\n";
}