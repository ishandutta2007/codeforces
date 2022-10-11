#include <iostream>

const int ms = 18;

long long dp[ms][11];

int main() {
	dp[0][0] = 1;
	for(int i = 1; i < ms; i++) {
		for(int j = 1; j <= 10; j++) {
			dp[i - 1][j] += dp[i - 1][j - 1];
		}

		for(int j = 0; j <= 10; j++) {
			dp[i][j] = dp[i - 1][j];
		}
		dp[i][10]--;

		for(int j = 10; j > 0; j--) {
			dp[i - 1][j] -= dp[i - 1][j - 1];
		}
	}
	long long k;
	std::cin >> k;
	long long ans = 0;
	for(int i = ms - 1, s = 10; i > 0; i--) {
		int j = 0;
		while(dp[i - 1][s - j] < k) {
			k -= dp[i - 1][s - j++];
		}
		s -= j;
		ans = j + ans * 10;
	}
	std::cout << ans << '\n';
}