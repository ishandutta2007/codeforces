#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;

		vector<vector<pair<int, int>>> g(n);
		for (int i = 0; i < n - 1; i++) {
			int x, y;
			cin >> x >> y;
			--x; --y;
			g[x].push_back({y, i});
			g[y].push_back({x, i});
		}
		bool bad = false;
		int start;
		for (int i = 0; i < n; i++) {
			if (g[i].size() > 2) {
				bad = true;
				break;
			}
			if (g[i].size() == 1) {
				start = i;
			}
		}
		if (bad) {
			cout << "-1\n";
			continue;
		}
		vector<int> ans(n - 1);
		for (int i = 0, x = start, px = -1; i < n - 1; i++) {
			for (const auto& [y, idx] : g[x]) {
				if (y != px) {
					ans[idx] = 2 + (i % 2);
					px = x;
					x = y;
					break;
				}
			}
		}
		for (int i : ans) cout << i << " ";
		cout << "\n";
	}
}