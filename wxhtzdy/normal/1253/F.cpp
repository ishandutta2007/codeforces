#include <bits/stdc++.h>

using namespace std;

#define pb push_back

using ll = long long;

const int N = 3e5 + 5;
const int L = 25;
vector<pair<int, int>> G[N];
int n, m, k, q;
int u[N];
int v[N];
int w[N];

vector<pair<int, ll>> g[N];

ll up[N][L];
int par[N][L];
int dep[N];

ll dis[N];

int LCA(int u, int v) {
	if (dep[u] < dep[v]) swap(u, v);
	for (int i = L - 1; i >= 0; i--) {
		if (dep[par[u][i]] >= dep[v]) {
			u = par[u][i];
		}
	}
	if (u == v) return u;
	for (int i = L - 1; i >= 0; i--) {
		if (par[u][i] != par[v][i]) {
			u = par[u][i];
			v = par[v][i];
		}
	}
	return par[u][0];
}

void dfs(int u, int p) {
	dep[u] = dep[p] + 1;
	par[u][0] = p;
	for (int i = 1; i < L; i++) {
		par[u][i] = par[par[u][i - 1]][i - 1];
	}
	for (auto e : g[u]) if (e.first != p) {
		int to = e.first;
		ll wei = e.second;
		up[to][0] = wei;
		dfs(to, u);
	}
}

ll maxOnPath(int u, int v) {
	int lca = LCA(u, v);
	ll res = 0;
	for (int i = L - 1; i >= 0; i--) {
		if (dep[par[u][i]] > dep[lca]) {
			res = max(res, up[u][i]);
			u = par[u][i];
		}
		if (dep[par[v][i]] > dep[lca]) {
			res = max(res, up[v][i]);
			v = par[v][i];
		}
	}
	if (u != lca) res = max(res, up[u][0]);
	if (v != lca) res = max(res, up[v][0]);
//	while (u != lca) res = max(res, up[u][0]), u = par[u][0];
//	while (v != lca) res = max(res, up[v][0]), v = par[v][0];
	return res;
}

int r[N];
int sz[N];

int root(int u) {
	return r[u] == u ? u : r[u] = root(r[u]);
}

bool unite(int u, int v) {
	u = root(u);
	v = root(v);
	if (u == v) {
		return false;
	}
	if (sz[u] > sz[v]) swap(u, v);
	sz[v] += sz[u];
	r[u] = v;
	return true;
}

int main()
{
	scanf("%d%d%d%d", &n, &m, &k, &q);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", u + i, v + i, w + i);
		G[u[i]].pb({v[i], w[i]});
		G[v[i]].pb({u[i], w[i]});
	}
	set<pair<ll, int>> setik;
	for (int i = 1; i <= n; i++) {
		if (i <= k) setik.insert({0, i});
		else dis[i] = (ll)1e18;
	}
	while (!setik.empty()) {
		auto it = setik.begin();
		int u = it -> second;
		setik.erase(it);
		for (auto e : G[u]) {
			int to = e.first;
			int wei = e.second;
			if (dis[u] + wei < dis[to]) {
				if (dis[to] != (ll)1e18) setik.erase(setik.find({dis[to], to}));
				dis[to] = dis[u] + wei;
				setik.insert({dis[to], to});
			}
		}
	}
	vector<tuple<ll, int, int>> edges;
	for (int i = 1; i <= m; i++) {
		edges.push_back({dis[u[i]] + dis[v[i]] + w[i], u[i], v[i]});
	}
	sort(edges.begin(), edges.end());
	for (int i = 1; i <= n; i++) {
		r[i] = i;
		sz[i] = 1;
	}
	for (int i = 0; i < edges.size(); i++) {
		int x = get<1>(edges[i]);
		int y = get<2>(edges[i]);
		ll ww = get<0>(edges[i]);
		if (unite(x, y)) {
			fflush(stdout);
			g[x].pb({y, ww});
			g[y].pb({x, ww});
		}
	}
	dfs(1, 0);
	for (int j = 1; j < L; j++) {
		for (int i = 1; i <= n; i++) {
			up[i][j] = max(up[i][j - 1], up[par[i][j - 1]][j - 1]);
		}
	}
	while (q--) {
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%lld\n", maxOnPath(a, b));
	}
	return 0;
}