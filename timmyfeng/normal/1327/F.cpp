#include <bits/stdc++.h>
using namespace std;
const int MOD = (119 << 23) + 1;
const int MX = 5e5;
int l[MX], r[MX], x[MX], one[MX + 2], dp[MX + 2], zer[MX + 2], ps[MX + 2];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k, m;
	cin >> n >> k >> m;
	for (int i = 0; i < m; ++i) {
		cin >> l[i] >> r[i] >> x[i];
	}
	long long ans = 1;
	for (int i = 1; i < (1 << k); i *= 2) {
		memset(ps, 0, sizeof ps);
		memset(dp, 0, sizeof dp);
		for (int j = 0; j < m; ++j) {
			if (x[j] & i) {
				++one[l[j]];
				--one[r[j] + 1];
			} else {
				zer[r[j] + 1] = max(zer[r[j] + 1], l[j]);
			}
		}
		for (int i = 1; i <= n + 1; ++i) {
			one[i] += one[i - 1];
			zer[i] = max(zer[i], zer[i - 1]);
		}

		dp[0] = ps[0] = 1;
		for (int i = 1; i <= n + 1; ++i) {
			dp[i] = ps[i - 1];
			if (zer[i]) {
				((dp[i] -= ps[zer[i] - 1]) += MOD) %= MOD;
				zer[i] = 0;
			}
			if (one[i]) {
				dp[i] = 0;
				one[i] = 0;
			}
			ps[i] = (dp[i] + ps[i - 1]) % MOD;
		}
		(ans *= dp[n + 1]) %= MOD;
	}
	cout << ans << '\n';
}