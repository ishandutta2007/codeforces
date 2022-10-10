#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <cstring>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 5050;
int dp[ms][ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::string s, t;
	std::cin >> n >> m >> s >> t;
	int ans = 0;
	for(int i = n-1; i >= 0; i--) {
		for(int j = m-1; j >= 0; j--) {
			dp[i][j] = std::max(dp[i+1][j], dp[i][j+1]) - 1;
			if(s[i] == t[j]) {
				dp[i][j] = std::max(dp[i][j], dp[i+1][j+1] + 2);
			}
			dp[i][j] = std::max(dp[i][j], 0);
			ans = std::max(dp[i][j], ans);
		}
	}
	std::cout << ans << '\n';
}