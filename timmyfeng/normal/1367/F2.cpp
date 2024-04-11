#include <bits/stdc++.h> 
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), vals;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		vals.push_back(a[i]);
	}

	sort(vals.begin(), vals.end());
	vals.erase(unique(vals.begin(), vals.end()), vals.end());
	map<int, int> ndx;
	for (int i = 0; i < int(vals.size()); ++i) {
		ndx[vals[i]] = i;
	}

	vector<int> cnt(vals.size());
	for (auto& i : a) {
		i = ndx[i];
		++cnt[i];
	}

	vector<int> dp(vals.size()), dp_pre(vals.size()), vstd(vals.size());
	for (auto i : a) {
		++dp[i];
		if (i) {
			dp[i] = max(dp[i], (vstd[i - 1] == cnt[i - 1] ? dp_pre[i - 1] : vstd[i - 1]) + 1);
		}

		dp_pre[i] = vstd[i] ? dp_pre[i] + 1 : dp[i];
		++vstd[i];
	}

	cout << n - *max_element(dp.begin(), dp.end()) << "\n";
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