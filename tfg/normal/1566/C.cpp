#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int tt;
	std::cin >> tt;
	int cost[4] = {0, 1, 0, 2};
	while(tt--) {
		int n;
		std::string s, t;
		std::cin >> n >> s >> t;
		const int INF = 1e9;
		std::vector<int> dp(4, -INF);
		dp[0] = 0;
		for(int i = 0; i < n; i++) {
			int x = (1 << (s[i] - '0')) | (1 << (t[i] - '0'));
			std::vector<int> nxt(4, -INF);
			for(int j = 0; j < 4; j++) {
				nxt[j|x] = std::max(nxt[j|x], dp[j]);
				nxt[x] = std::max(nxt[x], dp[j] + cost[j]);
			}
			dp = nxt;
		}
		int ans = 0;
		for(int i = 0; i < 4; i++) {
			ans = std::max(ans, dp[i] + cost[i]);
		}
		std::cout << ans << '\n';
	}
}