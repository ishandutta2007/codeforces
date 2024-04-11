#include <bits/stdc++.h>
using namespace std;

const int M = (119 << 23) + 1;
const int MX = 500 + 1;

int dp[2][MX][MX], dp_sum[MX];

int add(int a, int b) {
	a += b;
	return a < M ? a : a - M;
}

int mul(int a, int b) {
	return (long long)a * b % M;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	dp[1][1][1] = 2;
	for (int i = 1; i < n; ++i) {
		int ii = i % 2;
		memset(dp[!ii], 0, sizeof dp[!ii]);
		for (int j = 1; j < n; ++j) {
			for (int k = 1; k < n; ++k) {
				int nk = max(k, j + 1);
				dp[!ii][j + 1][nk] = add(dp[!ii][j + 1][nk], dp[ii][j][k]);
				dp[!ii][1][k] = add(dp[!ii][1][k], dp[ii][j][k]);
			}
		}
	}

	for (int j = 1; j <= n; ++j) {
		for (int k = 1; k <= n; ++k) {
			dp_sum[k] = add(dp_sum[k], dp[n % 2][j][k]);
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i * j < k) {
				ans = add(ans, mul(dp_sum[i], dp_sum[j]));
			}
		}
	}
	cout << mul(ans, (M + 1) / 2) << '\n';
}