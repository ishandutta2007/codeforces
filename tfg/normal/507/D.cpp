#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int dp[1002][101][2];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k;
	int MOD;
	std::cin >> n >> k >> MOD;
	int p = 1;
	for(int i = 0; i < n; i++) {
		// do transition
		//std::cout << "for " << i << " got p " << p << std::endl;
		for(int j = 0; j < k; j++) {
			//std::cout << "on position " << j << " got " << dp[i][j][0] << ", " << dp[i][j][1] << "\n";
			for(int d = (i + 1 == n ? 1 : 0); d < 10; d++) {
				int toJ = (d * p + j) % k;
				dp[i+1][toJ][1] = (dp[i+1][toJ][1] + dp[i][j][1]) % MOD;
				int o = toJ == 0 ? 1 : 0;
				dp[i+1][toJ][o] = (dp[i+1][toJ][o] + dp[i][j][0]) % MOD;
			}
		}
		for(int d = 1; d < 10; d++) {
			int toJ = (d * p) % k;
			int o = toJ == 0 ? 1 : 0;
			dp[i+1][toJ][o] = (dp[i+1][toJ][o] + 1) % MOD;
		}
		p = p * 10 % k;
	}
	long long ans = 0;
	for(int i = 0; i < k; i++) {
		ans += dp[n][i][1];
	}
	std::cout << ans % MOD << '\n';
}