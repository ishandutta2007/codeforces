#include <bits/stdc++.h>
using namespace std;

const int N = 2e3 + 5;
const int mod = 1e9 + 7;
const int I2 = (mod + 1) / 2;

int n, m, k, dp[N][N], t;

void rmain() {
	cin >> n >> m >> k;
	m = n - m;
	printf("%lld\n", 1LL * dp[n][m] * k % mod);
}

int main() {
	ios::sync_with_stdio(false);
	n = 2000;
	dp[0][0] = 0;
	for(int i = 1; i <= n; ++ i) {
		dp[i][0] = i;
		for(int j = 1; j <= n; ++ j) {
			if(j >= i) {
				dp[i][j] = 0; continue;
			}
			dp[i][j] = 1LL * I2 * (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
		}
	}
	for(cin >> t; t --;) {
		rmain();
	}
}