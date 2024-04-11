#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int tt;
	std::cin >> tt;
	while(tt--) {
		int n;
		std::cin >> n;
		std::string s, t;
		std::cin >> s >> t;
		std::vector<std::vector<bool>> dp(n+1, std::vector<bool>(2, false));
		dp[0][0] = true;
		for(int i = 0; i < n; i++) {
			if(s[i] <= '2') {
				dp[i+1][0] = dp[i+1][0] || dp[i][0];
			}
			if(t[i] <= '2') {
				dp[i+1][1] = dp[i+1][1] || dp[i][1];
			}
			if(s[i] > '2' && t[i] > '2') {
				bool v0 = dp[i][0];
				bool v1 = dp[i][1];
				dp[i+1][0] = dp[i+1][0] || v1;
				dp[i+1][1] = dp[i+1][1] || v0;
			}
		}
		std::cout << (dp[n][1] ? "YES\n" : "NO\n");
	}
}