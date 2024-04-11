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
		long long a, b;
		std::cin >> a >> b;
		long long ans = 1e18;
		for(int rep = 0; rep < 35; rep++) {
			if(b+rep <= 1) continue;
			long long cur = rep;
			long long x = a;
			while(x > 0) {
				cur++;
				x /= b+rep;
			}
			ans = std::min(ans, cur);
		}
		std::cout << ans << '\n';
	}
}