#include <bits/stdc++.h>
using namespace std;

const int MX = 1e3 + 1;
const int M = (119 << 23) + 1;

int a[MX], dp[MX][MX];

int add(int a, int b) {
	a += b;
	return a < M ? a : a - M;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	dp[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (j && a[i] == j) {
				dp[i][j] = add(dp[i - 1][0], dp[i][j]);
			}
			dp[i][j] = add(dp[i][j], dp[i - 1][j]);
			dp[i][j] = add(dp[i][j], dp[i - 1][j + 1]);
		}
	}
	cout << dp[n][0] - 1 << '\n';
}