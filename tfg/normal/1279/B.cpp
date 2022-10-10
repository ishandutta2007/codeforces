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
		int n, s;
		std::cin >> n >> s;
		int mx = 0;
		long long sum = 0;
		int ans = 0;
		for(int i = 0; i < n; i++) {
			int x;
			std::cin >> x;
			sum += x;
			if(mx < x && sum - x <= s) {
				mx = x;
				ans = i + 1;
			}
		}
		if(sum <= s) ans = 0;
		std::cout << ans << '\n';
	}
}