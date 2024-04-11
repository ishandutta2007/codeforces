#include <bits/stdc++.h>
using namespace std;
 
const int MX = 2e5 + 1;

set<int> adj[MX], not_vstd;

int dfs(int u) {
	not_vstd.erase(u);
	int res = 1;
	int i = 0;
	for (auto it = not_vstd.begin(); it != not_vstd.end(); it = not_vstd.upper_bound(i)) {
		i = *it;
		if (!adj[u].count(i)) {
			res += dfs(i);
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	while (m--) {
		int u, v;
		cin >> u >> v;
		adj[u].insert(v);
		adj[v].insert(u);
	}

	for (int i = 1; i <= n; ++i) {
		not_vstd.insert(i);
	}
	
	vector<int> ans;
	for (int i = 1; i <= n; ++i) {
		if (not_vstd.count(i)) {
			ans.push_back(dfs(i));
		}
	}

	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';	
	for (auto i : ans) {
		cout << i << ' ';
	}
	cout << '\n';
}