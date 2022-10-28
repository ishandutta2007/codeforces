#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<set<int>> adj(n + 1);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].insert(v);
		adj[v].insert(u);
	}

	if (k == 1) {
		cout << n - 1 << "\n";
		return;
	}

	vector<vector<int>> leaves(n + 1);
	vector<bool> in_que(n + 1);
	queue<int> que;

	auto update = [&](int u) {
		int p = *adj[u].begin();
		leaves[p].push_back(u);
		if (int(leaves[p].size()) >= k && !in_que[p]) {
			in_que[p] = true;
			que.push(p);
		}
	};

	for (int i = 1; i <= n; ++i) {
		if (int(adj[i].size()) == 1) {
			update(i);
		}
	}

	int ans = 0;
	while (!que.empty()) {
		int u = que.front();
		in_que[u] = false;
		que.pop();
		++ans;

		for (int i = 0; i < k; ++i) {
			int v = leaves[u].back();
			leaves[u].pop_back();
			adj[v].erase(u);
			adj[u].erase(v);
		}

		if (int(leaves[u].size()) >= k) {
			in_que[u] = true;
			que.push(u);
		}

		if (int(adj[u].size()) == 1) {
			update(u);
		}
	}
	cout << ans << "\n";
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