#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int solveMin(int got, int n) {
	if(n == 0) {
		return 0;
	} else {
		int use = std::min(2 * got, n);
		return n + solveMin(use, n - use);
	}
}

int solveMax(int got, int n) {
	return n * (n + 1) / 2;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		int n, d;
		std::cin >> n >> d;
		int l = 0, r = 1;
		if(d < solveMin(1, n - 1) || solveMax(1, n - 1) < d) {
			std::cout << "NO\n";
			continue;
		}
		std::cout << "YES\n";
		while(r < n) {
			int want = 1;
			d -= n - r;
			while(d < solveMin(want, n - r - want) || solveMax(want, n - r - want) < d) {
				want++;
			}
			assert(want <= 2 * (r - l));
			for(int i = 0; i < want; i++) {
				std::cout << l + i / 2 + 1 << (i + r + 1 == n ? '\n' : ' ');
			}
			l = r;
			r += want;
		}
	}
}