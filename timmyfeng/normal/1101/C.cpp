#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<pair<int, int>> pt;
		vector<int> ans(n, 2);
		for (int i = 0; i < n; ++i) {
			int l, r;
			cin >> l >> r;
			pt.emplace_back(l, i);
			pt.emplace_back(r, n);
		}
		sort(pt.begin(), pt.end());
		int cnt = 0;
		for (auto [x, i] : pt) {
			if (i == n) {
				--cnt;
				if (!cnt)
					break;
			} else {
				--ans[i];
				++cnt;
			}
		}
		if (count(ans.begin(), ans.end(), 2)) {
			for (auto i : ans) {
				cout << i << ' ';
			}
			cout << '\n';
		} else {
			cout << -1 << '\n';
		}
	}
}