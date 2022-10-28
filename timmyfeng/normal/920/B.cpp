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

		vector<array<int, 3>> que;
		for (int i = 0; i < n; ++i) {
			int l, r;
			cin >> l >> r;
			que.push_back({l, i, r});
		}
		sort(que.begin(), que.end());

		int cur = 0;
		vector<int> ans(n);
		for (auto e : que) {
			cur = max(cur, e[0]);
			if (cur > e[2]) {
				ans[e[1]] = 0;
			} else {
				ans[e[1]] = cur++;
			}
		}

		for (auto i : ans) {
			cout << i << ' ';
		}
		cout << '\n';
	}
}