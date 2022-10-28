#include <bits/stdc++.h>
using namespace std;
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	int n, m;
	cin >> n >> m;
 
	int ans = n - 1;
	vector<set<int>> towers(m + 1);
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		towers[a].insert(i);
		ans -= towers[a].count(i - 1);
	}
 
	cout << ans << "\n";
	for (int i = 0; i < m - 1; ++i) {
		int a, b;
		cin >> a >> b;
		if (towers[a].size() < towers[b].size()) {
			swap(towers[a], towers[b]);
		}
		for (auto i : towers[b]) {
			ans -= towers[a].count(i - 1);
			ans -= towers[a].count(i + 1);
		}
		towers[a].insert(towers[b].begin(), towers[b].end());
		towers[b].clear();
		cout << ans << "\n";
	}
}