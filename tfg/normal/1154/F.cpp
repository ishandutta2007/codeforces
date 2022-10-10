#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m, k;
	std::cin >> n >> m >> k;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::sort(a.begin(), a.end());
	a.resize(k);
	n = k;
	std::vector<long long> sum(n + 1, 0);
	for(int i = 1; i <= n; i++) {
		sum[i] = sum[i-1] + a[i-1];
	}
	std::vector<int> discount(n + 1, 0);
	while(m--) {
		int x, y;
		std::cin >> x >> y;
		if(x > n) continue;
		discount[x] = std::max(discount[x], y);
	}
	std::vector<long long> dp(n + 1, 1e18);
	dp[0] = 0;
	for(int i = 0; i < n; i++) {
		for(int j = i+1; j <= n; j++) {
			dp[j] = std::min(dp[j], dp[i] + sum[j] - sum[i+discount[j-i]]);
		}
	}
	std::cout << dp.back() << '\n';
}