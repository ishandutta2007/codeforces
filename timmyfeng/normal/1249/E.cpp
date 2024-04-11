#include <bits/stdc++.h>
using namespace std;

const int MX = 2e5 + 1;

int a[MX], b[MX], dp[MX][2];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, c;
	cin >> n >> c;
	for (int i = 2; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 2; i <= n; ++i) {
		cin >> b[i];
	}

	dp[1][1] = c;
	cout << dp[1][0];
	for (int i = 2; i <= n; ++i) {
		dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + a[i];
		dp[i][1] = min(dp[i - 1][0] + c, dp[i - 1][1]) + b[i];
		cout << ' ' << min(dp[i][0], dp[i][1]);
	}
	cout << '\n';
}