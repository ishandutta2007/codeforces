#include <iostream>
#include <vector>
#include <bitset>

const int ms = 1e6;

int solve(int lim, std::vector<int> coins, int n) {
	std::vector<int> dp(n + 1, lim + 1);
	dp[0] = 0;
	for(auto c : coins) {
		std::vector<int> trans(c, lim + 1);
		for(int i = 0; i <= n; i++) {
			trans[i % c] = std::min(trans[i % c], dp[i] - (i / c));
			dp[i] = trans[i % c] + i / c;
		}
	}
	int ans = 0;
	for(int i = 0; i <= n; i++) {
		ans += dp[i] <= lim ? 1 : 0;
		//std::cout << (dp[i] <= lim ? 1 : 0);
	}
	//std::cout << std::endl;
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	long long n;
	std::cin >> n;
	std::vector<int> left = std::vector<int>{4, 9, 49};
	std::vector<int> right = std::vector<int>{40, 45, 49};
	/*if(1) {
		solve(n, left, (50LL * n + 1) - (1LL * n) + 10);
		return 0;
	}*/
	if((50LL * n + 1) - (1LL * n) <= 3 * ms) {
		//std::cout << "first\n";
		std::cout << solve(n, left, (50LL * n + 1) - (1LL * n) + 10);
	} else {
		//std::cout << "second\n";
		std::cout << (50LL * n + 1) - (1LL * n) - 2 * ms - 2 + (long long)(solve(n, left, ms) + solve(n, right, ms));
	}
	std::cout << std::endl;
	//std::cout << solve(n, left, (50LL * n + 1) - (1LL * n) + 10) << ", " << (50LL * n + 1) - (1LL * n) - 2 * ms - 2 + (long long)(solve(n, left, ms) + solve(n, right, ms)) << std::endl;
}