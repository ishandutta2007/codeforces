#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<std::pair<int, int>> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i].first >> a[i].second;
		int l = a[i].first - a[i].second - 1;
		int r = a[i].first + a[i].second;
		l = std::max(l, 0);
		r = std::min(r, m);
		a[i] = std::pair<int, int>(l, r);
	}
	std::sort(a.begin(), a.end());
	const int INF = 1e9;
	std::vector<int> dp(m + 1, INF);
	dp[0] = 0;
	for(auto range : a) {
		for(int i = 0; i <= m; i++) {
			int l = std::max(range.first - i, 0);
			int r = std::min(range.second + i, m);
			dp[r] = std::min(dp[r], dp[l] + i);
		}
		for(int i = m-1; i >= 0; i--) {
			dp[i] = std::min(dp[i], dp[i+1]);
		}
	}
	std::cout << dp.back() << '\n';
}