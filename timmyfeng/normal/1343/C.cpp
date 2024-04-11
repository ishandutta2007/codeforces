#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto& i : a) {
		cin >> i;
	}

	vector<pair<int, ll>> dpp(n + 1), dpn(n + 1);
	for (int i = 1; i <= n; ++i) {
		dpp[i] = dpp[i - 1];
		dpn[i] = dpn[i - 1];
		if (a[i - 1] > 0) {
			dpp[i] = max(dpp[i], {dpn[i].first + 1, dpn[i].second + a[i - 1]});
		} else {
			dpn[i] = max(dpn[i], {dpp[i].first + 1, dpp[i].second + a[i - 1]});
		}
	}
	cout << max(dpp[n], dpn[n]).second << '\n';
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