#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MX = 20;

int ct[MX][MX];
ll dp[1 << MX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	string s;
	cin >> n >> m >> s;
	for (int i = 1; i < n; ++i) {
		++ct[s[i] - 'a'][s[i - 1] - 'a'];
	}

	for (int i = 1; i < (1 << m); ++i) {
		dp[i] = 1e18;
		int len = __builtin_popcount(i);
		for (int j = 0; j < m; ++j) {
			if (i & (1 << j)) {
				ll res = dp[i ^ (1 << j)];
				for (int k = 0; k < m; ++k) {
					if (k == j) continue;
					if (i & (1 << k)) {
						res += len * (ct[k][j] + ct[j][k]);
					} else {
						res -= len * (ct[k][j] + ct[j][k]);
					}
				}
				dp[i] = min(dp[i], res);
			}
		}
	}
	cout << dp[(1 << m) - 1] << '\n';
}