#include <bits/stdc++.h>
using namespace std;

const int MX = 500 + 1;

vector<array<int, 2>> adj[MX];
int col[MX], stop, cur;
vector<int> cyc;

bool dfs_find(int u) {
	bool res = false;
	col[u] = 1;
	for (auto e : adj[u]) {
		if (col[e[0]] == 1 && !stop) {
			cyc.push_back(e[1]);
			stop = e[0];
			res = true;
		} else if (!col[e[0]]) {
			if (dfs_find(e[0])) {
				cyc.push_back(e[1]);
				res = true;
			}
		}
	}
	res &= (u != stop);
	col[u] = 2;
	return res;
}

bool dfs(int u) {
	bool res = true;
	col[u] = 1;
	for (auto e : adj[u]) {
		if (e[1] == cur)
			continue;
		if (col[e[0]] == 1) {
			return false;
		} else if (!col[e[0]]) {
			res &= dfs(e[0]);
		}
	}
	col[u] = 2;
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back({v, i});
	}

	for (int i = 1; i <= n; ++i) {
		if (!col[i]) {
			dfs_find(i);
		}
	}

	if (cyc.empty()) {
		cout << "YES" << '\n';
		return 0;
	}

	for (auto i : cyc) {
		cur = i;
		bool ok = true;
		memset(col, 0, sizeof col);
		for (int j = 1; j <= n; ++j) {
			if (!col[j]) {
				ok &= dfs(j);
			}
		}
		if (ok) {
			cout << "YES" << '\n';
			return 0;
		}
	}
	cout << "NO" << '\n';
}