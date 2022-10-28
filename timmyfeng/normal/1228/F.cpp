#include <bits/stdc++.h>
using namespace std;

const int MX = 1 << 17;

vector<int> adj[MX + 1];
int dist[MX + 1], hei[MX + 1], par[MX + 1];
int ans = 0;

void dfs1(int u) {
	for (auto c : adj[u]) {
		if (c == par[u]) continue;
		par[c] = u;
		dist[c] = dist[u] + 1;
		dfs1(c);
	}
}

void dfs2(int u, int p) {
	if (adj[u].size() == 2) {
		if (adj[adj[u][0] + adj[u][1] - p].size() != 1) {
			cout << 0 << '\n';
			exit(0);
		} else {
			if (ans) {
				cout << 0 << '\n';
				exit(0);
			}
			ans = u;
		}
		hei[u] = 2;
		return;
	} else if (adj[u].size() == 4) {
		if (ans) {
			cout << 0 << '\n';
			exit(0);
		}
		ans = u;
	} else if (adj[u].size() == 1) {
		hei[u] = 1;
		return;
	} else if (adj[u].size() != 3) {
		cout << 0 << '\n';
		exit(0);
	}
	vector<int> chd;
	for (auto c : adj[u]) {
		if (c == p) continue;
		dfs2(c, u);
		chd.push_back(hei[c]);
	}
	if (chd.size() == 2) {
		if (chd[0] == chd[1]) {
			hei[u] = chd[0] + 1;
		} else {
			cout << 0 << '\n';
			exit(0);
		}
	} else {
		sort(chd.begin(), chd.end());
		if (chd[0] == chd[1] && chd[0] + 1 == chd[2]) {
			hei[u] = chd[2] + 1;
		} else {
			cout << 0 << '\n';
			exit(0);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int m = (1 << n) - 2;
	for (int i = 0; i < m - 1; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs1(1);
	int rt = max_element(dist + 1, dist + 1 + m) - dist;
	dist[rt] = par[rt] = 0;
	dfs1(rt);
	rt = max_element(dist + 1, dist + 1 + m) - dist;
	int dia = dist[rt];
	for (int i = 0; i < dia / 2; ++i) {
		rt = par[rt];
	}

	if (dia % 2) {
		dfs2(rt, par[rt]);
		dfs2(par[rt], rt);
		if (hei[rt] != hei[par[rt]] || ans) {
			cout << 0 << '\n';
		} else {
			cout << 2 << '\n';
			cout << min(rt, par[rt]) << ' ' << max(rt, par[rt]) << '\n';
		}
		return 0;
	}

	if (adj[rt].size() != 2) {
		cout << 0 << '\n';
		return 0;
	}
	dfs2(adj[rt][0], rt);
	dfs2(adj[rt][1], rt);
	if (hei[adj[rt][0]] != n - 1 || hei[adj[rt][1]] != n - 1) {
		cout << 0 << '\n';
	} else {
		cout << 1 << '\n';
		cout << ans << '\n';
	}
}