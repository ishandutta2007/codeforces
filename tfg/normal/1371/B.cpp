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
		long long n, r;
		std::cin >> n >> r;
		if(n > r) {
			std::cout << r * (r + 1) / 2 << '\n';
		} else {
			long long ans = (n - 1) * n / 2;
			std::cout << ans + 1 << "\n";
		}
	}
}