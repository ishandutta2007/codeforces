#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		int n, k1, k2;
		std::cin >> n >> k1 >> k2;
		int mx1 = 0, mx2 = 0;
		while(k1--) {
			int x;
			std::cin >> x;
			mx1 = std::max(mx1, x);
		}
		while(k2--) {
			int x;
			std::cin >> x;
			mx2 = std::max(mx2, x);
		}
		std::cout << (mx1 > mx2 ? "YES\n" : "NO\n");
	}
}