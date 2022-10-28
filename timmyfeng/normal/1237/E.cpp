#include <bits/stdc++.h> 
using namespace std;

const int MX = 1e6 + 1;

int dp[MX][2];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	dp[0][0] = 1;
	dp[0][1] = 1;
	int lo = 1;
	int hi = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = (lo + hi) / 2; j <= (lo + hi + 1) / 2; ++j) {
			dp[i][j % 2] += dp[j - 1][!(j % 2)] * dp[i - j][0];
		}
		if (lo == hi || (hi & (hi - 1))) {
			++hi;
		} else {
			++lo;
		}
	}

	cout << dp[n][0] + dp[n][1] << "\n";
}