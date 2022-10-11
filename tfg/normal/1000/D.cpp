#include <iostream>
#include <vector>

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<long long> dp(n + 1, 0);
	dp[0] = 1;
	const int MOD = 998244353;
	for(int i = 0; i < n; i++) {
		auto other = dp;
		int val;
		std::cin >> val;
		if(val > 0 && val <= n) {
			other[val] = (other[val] + dp[0]) % MOD;
		}
		for(int j = 1; j <= n; j++) {
			other[j - 1] = (other[j - 1] + dp[j]) % MOD;
		}
		other.swap(dp);
	}
	std::cout << (dp[0] + MOD - 1) % MOD << std::endl;
}