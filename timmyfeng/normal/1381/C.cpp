#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n, x, y;
		cin >> n >> x >> y;

		vector<int> b(n);
		vector<vector<int>> pos(n + 2);
		for (int i = 0; i < n; ++i) {
			cin >> b[i];
			pos[b[i]].push_back(i);
		}

		int bad = 0;
		priority_queue<pair<int, int>> pq;
		for (int i = 1; i <= n + 1; ++i) {
			pq.emplace(pos[i].size(), i);
			if (pos[i].empty()) {
				bad = i;
			}
		}

		vector<int> a(n);
		for (int i = 0; i < x; ++i) {
			int u = pq.top().second;
			pq.pop();
			a[pos[u].back()] = u;
			pos[u].pop_back();
			pq.emplace(pos[u].size(), u);
		}

		vector<int> ndx;
		for (int i = 1; i <= n + 1; ++i) {
			for (auto j : pos[i]) {
				ndx.push_back(j);
			}
		}

		int cur = (n - x) / 2;
		for (int i = 1; i <= n + 1; ++i) {
			for (int j = 0; j < int(pos[i].size()); ++j) {
				a[ndx[cur]] = (b[ndx[cur]] == i) ? bad : i;
				cur = (cur + 1) % (n - x);
			}
		}

		y += count(a.begin(), a.end(), bad);
		for (int i = 0; i < n && y < n; ++i) {
			if (a[i] != b[i]) {
				y += (a[i] != bad);
				a[i] = bad;
			}
		}

		if (y > n) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
			for (auto i : a) {
				cout << i << " ";
			}
			cout << "\n";
		}
	}
}