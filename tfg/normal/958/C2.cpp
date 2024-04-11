#include <iostream>
#include <cstring>

const int ms = 20200;

int to[ms][101];
int dp[ms][53];
int a[ms], b[ms];

int main() {
	int n, k, p;
	std::cin >> n >> k >> p;
	for(int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		b[i] = (a[i] + b[i - 1]) % p;
	}
	for(int i = 0; i < p; i++) {
		to[n][i] = n + 1;
	}
	for(int i = n - 1; i >= 0; i--) {
		for(int j = 0; j < p; j++) {
			to[i][j] = to[i + 1][j];
		}
		to[i][b[i + 1]] = i + 1;
	}
	memset(dp, -1, sizeof dp);
	dp[0][0] = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < k; j++) {
			if(dp[i][j] == -1) {
				continue;
			}
			//std::cout << "answer for " << i << ", " << j << " is " << dp[i][j] << std::endl;
			for(int o = 0; o < p; o++) {
				dp[to[i][o]][j + 1] = std::max(dp[to[i][o]][j + 1], dp[i][j] + (o - b[i] + p) % p);
			}
			dp[n][j + 1] = std::max(dp[n][j + 1], dp[i][j] + (b[n] - b[i] + p) % p);
		}
	}
	std::cout << dp[n][k] << std::endl;
}