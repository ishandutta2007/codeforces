#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	std::vector<int> dp[2];
	dp[0].assign(n, 1);
	dp[1].assign(n, 1);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		if(i == 0) continue;
		if(i == 1) {
			if(a[1] > a[0]) {
				dp[0][i]++;
			}
			continue;
		}
		if(a[i] > a[i-1]) {
			dp[0][i] = 1 + dp[0][i-1];
			dp[1][i] = std::max(dp[1][i], dp[1][i-1] + 1);
		}
		if(a[i] > a[i-2]) {
			dp[1][i] = std::max(dp[1][i], dp[0][i-2] + 1);
		}
	}
	int ans = 1;
	for(int i = 0; i < n; i++) {
		ans = std::max(ans, std::max(dp[0][i], dp[1][i]));
	}
	ans = std::min(ans, n);
	std::cout << ans << '\n';
}