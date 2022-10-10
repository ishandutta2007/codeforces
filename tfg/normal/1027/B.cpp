#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	long long n;
	int q;
	std::cin >> n >> q;
	while(q--) {
		long long x, y;
		std::cin >> x >> y;
		x--;y--;
		std::cout << ((x + y) % 2 == 1 ? (n * n + 1) / 2 : 0LL) + ((x + y) % 2 == 1 ? n / 2 : (n + 1) / 2) * (x % 2) + n * (x / 2) + y / 2 + 1 << '\n';
	}
}