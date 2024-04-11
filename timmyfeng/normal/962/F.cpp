#include <bits/stdc++.h> 
using namespace std;

const int MX = 1e5 + 1;

int down[MX], col[MX], nxt[MX], par[MX], sz[MX], cnt[MX], edge[MX];
vector<pair<int, int>> adj[MX];

int find(int a) {
	if (par[a] != a) {
		par[a] = find(par[a]);
	}
	return par[a];
}

void unite(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) {
		if (sz[a] > sz[b]) {
			swap(a, b);
		}
		par[a] = b;
		sz[b] += sz[a];
		cnt[b] += cnt[a];
	}
}

int dfs(int u, int p) {
	col[u] = 1;
	int res = 0;
	for (auto e : adj[u]) {
		int c, i;
		tie(c, i) = e;
		if (c == p)
			continue;

		if (col[c] == 1) {
			++cnt[i];
			unite(i, edge[u]);
			++down[nxt[c]];
			++res;
		} else if (!col[c]) {
			nxt[u] = c;
			edge[c] = i;
			int chd = dfs(c, u);
			res += chd;
			if (chd) {
				unite(edge[u], edge[c]);
			}
		}
	}
	col[u] = 2;
	return res - down[u];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].emplace_back(v, i);
		adj[v].emplace_back(u, i);
	}

	iota(par, par + 1 + m, 0);
	fill(sz + 1, sz + 1 + m, 1);
	for (int i = 1; i <= n; ++i) {
		if (!col[i]) {
			dfs(i, 0);
		}
	}

	vector<int> ans;
	for (int i = 1; i <= m; ++i) {
		if (cnt[find(i)] == 1) {
			ans.push_back(i);
		}
	}

	cout << ans.size() << '\n';
	for (auto i : ans) {
		cout << i << ' ';
	}
	cout << '\n';
}