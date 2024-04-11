#include <bits/stdc++.h>
using namespace std;

int r[200001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<tuple<int, int, int>> pt;
	for (int i = 1; i <= n; ++i) {
		int l;
		cin >> l >> r[i];
		pt.emplace_back(l, 0, i);
		pt.emplace_back(r[i], 1, i);
	}
	sort(pt.begin(), pt.end());

	int cur = 0;
	vector<int> ans;
	set<pair<int, int>> right;
	for (auto [x, t, i] : pt) {
		if (t) {
			if (right.count({x, i})) {
				right.erase({x, i});
				--cur;
			}
		} else {
			++cur;
			right.emplace(r[i], i);
			if (cur > k) {
				auto [x1, j] = *right.rbegin();
				right.erase(--right.end());
				ans.push_back(j);
				--cur;
			}
		}
	}
	cout << ans.size() << '\n';
	for (auto i : ans) {
		cout <<i << ' ';
	}
	cout << '\n';
}