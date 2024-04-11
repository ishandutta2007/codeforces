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
		int a[3];
		for(int i = 0; i < 3; i++) {
			std::cin >> a[i];
		}
		long long ans = 1e18;
		for(int i = -1; i <= 1; i++) {
			for(int j = -1; j <= 1; j++) {
				for(int k = -1; k <= 1; k++) {
					ans = std::min(ans, (long long) abs(a[0] + i - a[1] - j) + abs(a[0] + i - a[2] - k) + abs(a[1] + j - a[2] - k));
				}
			}
		}
		std::cout << ans << '\n';
	}
}