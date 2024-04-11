#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	if(n % 2 == 0) {
		std::cout << "-1\n";
		return 0;
	}
	std::vector<int> a(n+1);
	for(int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	std::vector<std::vector<int>> dp(n+1);
	for(int i = n; i > 0; i--) {
		std::vector<int> curDp(a[i] + 1, 1e9);
		if(2 * i + 1 > n) {
			dp[i] = curDp;
			if(2 * i > n || a[2*i] == 0) dp[i][0] = 0;
			continue;
		}
		for(int used = 0; used <= 1000; used++) {
			int j = std::min(a[i], used);
			curDp[j] = std::min(curDp[j], used + dp[2 * i][std::max(0, a[2*i] - used)] + dp[2 * i + 1][std::max(0, a[2 * i + 1] - used)]);
		}
		for(int j = a[i]; j > 0; j--) {
			curDp[j-1] = std::min(curDp[j-1], curDp[j]);
		}
		dp[i] = curDp;
	}
	int ans = dp[1][a[1]];
	if(ans >= (int) 1e9) {
		ans = -1;
	}
	std::cout << ans << std::endl;
}