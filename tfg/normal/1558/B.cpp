#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int MOD;

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n >> MOD;
	std::vector<int> dp(n+1, 0);
	dp[1] = 1;
	dp[2] = MOD-1;
	int sum = 0;
	for(int i = 1; i <= n; i++) {
		dp[i] = (dp[i] + dp[i-1]) % MOD;
		int val = (dp[i] + sum) % MOD;
		for(int j = 2; i * j <= n; j++) {
			// i <= x / j < i+1
			// i * j <= x
			// x < (i + 1) * j
			dp[i*j] = (dp[i*j] + val) % MOD;
			if((i+1)*j <= n) {
				dp[(i+1)*j] = (dp[(i+1)*j] - val + MOD) % MOD;
			}
		}
		if(i == n) {
			dp[i] = val;
		}
		sum = (sum + val) % MOD;
	}
	std::cout << dp[n] << '\n';
}