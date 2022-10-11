#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1e9 + 7;

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> to(n);
	std::vector<int> dp(n, 0);
	for(int i = 0; i < n; i++) {
		std::cin >> to[i];
		to[i]--;
	}
	for(int i = 0; i < n; i++) {
		dp[i] = 2;
		for(int j = to[i]; j < i; j++) {
			dp[i] = (dp[i] + dp[j]) % MOD;
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++) {
		ans = (ans + dp[i]) % MOD;
	}
	std::cout << ans << std::endl;
}