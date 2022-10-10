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
		long long money;
		std::cin >> money;
		long long ans = 0;
		while(money > 9) {
			long long use = money / 10 * 10;
			ans += use;
			money += use / 10 - use;
		}
		ans += money;
		std::cout << ans << std::endl;
	}
}