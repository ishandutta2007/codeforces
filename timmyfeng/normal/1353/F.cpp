#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
const int MX = 100;

map<ll, ll> dp[2][MX];
ll a[MX][MX];

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < n; ++i) {
		int ci = i % 2;
		for (int j = 0; j < m; ++j) {
			vector<pair<ll, ll>> ent;
			if (!i && !j) {
				ent.emplace_back(a[i][j], 0);
			}

			if (i) {
				for (auto [h, c] : dp[!ci][j]) {
					if (h < a[i][j]) {
						ent.emplace_back(h + 1, a[i][j] - (h + 1) + c);
					} else {
						ent.emplace_back(a[i][j], (i + j) * (h - (a[i][j] - 1)) + c);
					}
				}
			}
			if (j) {
				for (auto [h, c] : dp[ci][j - 1]) {
					if (h < a[i][j]) {
						ent.emplace_back(h + 1, a[i][j] - (h + 1) + c);
					} else {
						ent.emplace_back(a[i][j], (i + j) * (h - (a[i][j] - 1)) + c);
					}
				}
			}

			dp[ci][j].clear();
			for (auto [h, c] : ent) {
				if (dp[ci][j].count(h)) {
					dp[ci][j][h] = min(dp[ci][j][h], c);
				} else {
					dp[ci][j][h] = c;
				}
			}
		}
	}

	ll ans = 1e18;
	for (auto [h, c] : dp[(n - 1) % 2][m - 1]) {
		ans = min(ans, c);
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}