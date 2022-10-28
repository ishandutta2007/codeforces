#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MX = 400;

vector<tuple<int, int, int>> req[MX];
int dp[MX][MX], a[MX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	while (m--) {
		int s, f, c, r;
		cin >> s >> f >> c >> r;
		r = min(n - 1, r);
		--s;
		--f;
		req[s].emplace_back(r, f, c);
	}

	auto calc = [&](int pre, int cur, int cnt) {
		return max(dp[cnt - 1][pre], a[cur] - a[pre]);
	};

	ll ans = 0;
	for (int l = 0; l < n; ++l) {
		for (int r = l + 1; r < n; ++r) {
			dp[0][r] = a[r] - a[l];
		}
		for (int k = 1; k < n; ++k) {
			int opt = l;
			for (int r = l + 1; r < n; ++r) {
				while (opt < r && calc(opt, r, k) >= calc(opt + 1, r, k)) {
					++opt;
				}
				dp[k][r] = calc(opt, r, k);
			}
		}
		for (auto [r, f, c] : req[l]) {
			ans = max(ans, (ll)c * dp[r][f]);
		}
	}
	cout << ans << '\n';
}