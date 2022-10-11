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
		long long n, m, k;
		std::cin >> n >> m >> k;
		if(k < std::max(n, m)) {
			std::cout << "-1\n";
			continue;
		}
		long long ans = k;
		if((n + m) % 2 == 0) {
			// is in the same color
			long long rest = k - std::max(n, m);
			if(rest & 1) {
				ans -= 2;
			}
		} else {
			ans--;
		}
		std::cout << ans << '\n';
	}
}