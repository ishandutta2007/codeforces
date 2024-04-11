#include <iostream>

const int MOD = 1e9 + 7;
const int ms = 2020;

#define add(a, b) (a + b >= MOD ? a + b - MOD : a + b)

int dp[ms][ms];

int main() {
	int n, k;
	std::cin >> k >> n;
	for(int i = 1; i <= k; i++) {
		dp[1][i] = 1;
	}
	for(int i = 2; i <= n; i++) {
		for(int j = 1; j <= k; j++) {
			for(int kk = j; kk <= k; kk += j) {
				dp[i][kk] = add(dp[i][kk], dp[i - 1][j]);
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= k; i++) {
		ans = add(ans, dp[n][i]);
	}
	std::cout << ans << std::endl;
}