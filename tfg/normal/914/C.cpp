#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int solve(int x) { return x > 0 ? 1 + solve(x - (x & -x)) : 0; }

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::string str;
	std::cin >> str;
	int k;
	std::cin >> k;
	if(k == 0) {
		std::cout << "1\n";
		return 0;
	}
	const int MOD = 1e9 + 7;
	const int ms = 1010;
	std::vector<int> dp(ms, 0);
	int sum = 0;
	for(auto ch : str) {
		for(int i = ms-1; i > 0; i--) {
			dp[i] = (dp[i] + dp[i-1]) % MOD;
		}
		if(ch == '1') {
			dp[sum++]++;
		}
	}
	dp[sum]++;
	std::vector<int> to(ms, 0);
	for(int i = 2; i < ms; i++) {
		to[i] = solve(i);
	}
	dp[1]--;
	k--;
	while(k--) {
		std::vector<int> got(ms, 0);
		for(int i = 2; i < ms; i++) {
			got[to[i]] = (got[to[i]] + dp[i]) % MOD;
		}
		dp = got;
	}
	std::cout << dp[1] << '\n';
}