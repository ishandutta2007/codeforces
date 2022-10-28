#include <bits/stdc++.h>
using namespace std;
const int MX = 5000;

vector<int> adj[MX + 1];
int par[32 - __builtin_clz(MX)][MX + 1], f[MX + 1], tin[MX + 1], tout[MX + 1], id[MX + 1][MX + 1], timer, logn;
tuple<int, int, int> query[MX];

void dfs(int u) {
	tin[u] = ++timer;
	for (auto c : adj[u]) {
		if (c != par[0][u]) {
			par[0][c] = u;
			dfs(c);
		}
	}
	tout[u] = ++timer;
}

bool anc(int u, int v) {
	return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
	int tmp = u;
	if (anc(u, v)) return u;
	if (anc(v, u)) return v;
	for (int i = logn - 1; ~i; --i) {
		if (!anc(par[i][u], v)) {
			u = par[i][u];
		}
	}
	return par[0][u];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		cin >> x >> y;
		id[x][y] = i;
		id[y][x] = i;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	
	dfs(1);
	tout[0] = ++timer;
	logn = 32 - __builtin_clz(n);
	for (int i = 1; i < logn; ++i) {
		for (int j = 1; j <= n; ++j) {
			par[i][j] = par[i - 1][par[i - 1][j]];
		}
	}
	fill(f, f + n - 1, 1);

	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int a, b, g;
		cin >> a >> b >> g;
		int u = lca(a, b);
		for (auto k : {a, b}) {
			for (int j = k; j != u; j = par[0][j]) {
				int sec = id[j][par[0][j]];
				f[sec] = max(f[sec], g);
			}
		}
		query[i] = make_tuple(a, b, g);
	}

	for (int i = 0; i < q; ++i) {
		int a, b, g;
		tie(a, b, g) = query[i];
		int mn = 1e9;
		int u = lca(a, b);
		for (auto k : {a, b}) {
			for (int j = k; j != u; j = par[0][j]) {
				int sec = id[j][par[0][j]];
				mn = min(mn, f[sec]);
			}
		}
		if (mn != g) {
			cout << -1 << '\n';
			return 0;
		}
	}
	for (int i = 0; i < n - 1; ++i) {
		cout << f[i] << ' ';
	}
	cout << '\n';
}