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
		int n;
		std::cin >> n;
		std::vector<int> a(n);
		for(int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		std::vector<int> h(n, 0);
		for(int l = 1, r = 1, i = 0; l < n; l = r, i++) {
			r++;
			while(r < n && a[r] > a[r-1]) r++;
			for(int j = l; j < r; j++) {
				h[j] = h[i]+1;
			}
		}
		std::cout << h.back() << '\n';
	}
}