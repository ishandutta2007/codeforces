#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
const int MX = 3e5 + 1;
const int INF = 1e9;

ll dp[MX][2], a[MX][2];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	ll n, k;
	cin >> n >> k;
	for (int j = 0; j < 2; ++j) {
		for (int i = 1; i <= n; ++i) {
			cin >> a[i][j];
		}
	}

	dp[0][0] = dp[0][1] = 0;
	for (int i = 1; i <= n; ++i) {
		dp[i][0] = dp[i][1] = INF;
		for (int j = 0; j < 2; ++j) {
			if (dp[i - 1][j] == INF)
				continue;
			int x = a[i][j];
			int y = a[i][!j];
			ll pX = dp[i - 1][j];

			ll mnY = (x + pX - 1) / k;
			ll mxY = x * k;
			if (y >= mnY && y <= mxY) {
				if (y == mnY) {
					dp[i][j] = min(dp[i][j], x + pX - k * y);
				} else {
					dp[i][j] = 1;
				}
			}

			ll mnX = (y - 1) / k;
			ll mxX = y * k - pX;
			if (x >= mnX && x <= mxX) {
				if (x == mnX) {
					dp[i][!j] = min(dp[i][!j], y - k * x);
				} else {
					dp[i][!j] = 1;
				}
			}
		}
	}
	cout << (min(dp[n][0], dp[n][1]) < INF ? "YES" : "NO") << '\n';
}