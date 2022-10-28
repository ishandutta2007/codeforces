#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> cols(m, vector<int>(n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> cols[j][i];
		}
	}
 
	vector<pair<int, int>> best(m);
	for (int i = 0; i < m; ++i) {
		best[i].first = *max_element(cols[i].begin(), cols[i].end());
		best[i].second = i;
	}
	sort(best.rbegin(), best.rend());
	int sz = min(n, m);
 
	vector<vector<int>> dp(sz + 1, vector<int>(1 << n));
	for (int i = 1; i <= sz; ++i) {
		vector<int> val(1 << n);
		for (int mask = 0; mask < (1 << n); ++mask) {
			for (int j = 0; j < n; ++j) {
				int sum = 0;
				for (int k = 0; k < n; ++k) {
					if (mask & (1 << k)) {
						sum += cols[best[i - 1].second][(j + k) % n];
					}
				}
				val[mask] = max(val[mask], sum);
			}
 
			dp[i][mask] = dp[i - 1][mask];
			for (int add = mask; add; add = mask & (add - 1)) {
				dp[i][mask] = max(dp[i][mask], dp[i - 1][mask ^ add] + val[add]);
			}
		}
	}
 
	cout << dp[sz][(1 << n) - 1] << "\n";
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