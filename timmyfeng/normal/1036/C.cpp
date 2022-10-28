#include <bits/stdc++.h> 
using namespace std;

using ll = long long;

ll dp[20][4][2];

ll calc(const string& s) {
	memset(dp, 0, sizeof dp);
	int n = s.size();
	dp[0][0][1] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= 3; ++j) {
			for (int k = 0; k < 10 && j + !!k <= 3; ++k) {
				dp[i + 1][j + !!k][0] += dp[i][j][0];
				if (k < s[i] - '0') {
					dp[i + 1][j + !!k][0] += dp[i][j][1];
				} else if (k == s[i] - '0') {
					dp[i + 1][j + !!k][1] += dp[i][j][1];
				}
			}
		}
	}
	ll res = 0;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 2; ++j) {
			res += dp[n][i][j];
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		ll l, r;
		cin >> l >> r;
		cout << calc(to_string(r)) - calc(to_string(l - 1)) << '\n';
	}
}