#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	t = 1;
	while(t--) {
		int n, q, k;
		std::cin >> n >> q >> k;
		std::vector<int> a(n);
		for(int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		while(q--) {
			int l, r;
			std::cin >> l >> r;
			std::cout << 2 * (k - (r - l + 1)) - (a[l-1] - 1) - (k - a[r-1]) << '\n';
		}
	}
}