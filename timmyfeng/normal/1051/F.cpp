#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
const int MX = 1e5 + 1;
const int LOGN = 18;

int par[LOGN][MX], tin[MX], tout[MX], t, n, logn;
vector<pair<int, int>> adj[MX];
vector<vector<ll>> chk;
bool vstd[MX];
ll dist[MX];

vector<ll> dijkstra(int src) {
	vector<ll> dist(n + 1, 1e18);
	dist[src] = 0;
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	pq.emplace(0, src);
	while (!pq.empty()) {
		int u;
		ll d;
		tie(d, u) = pq.top();
		pq.pop();
		if (d > dist[u]) {
			continue;
		}
		for (auto i : adj[u]) {
			int v;
			ll w;
			tie(v, w) = i;
			if (d + w < dist[v]) {
				dist[v] = d + w;
				pq.emplace(d + w, v);
			}
		}
	}
	return dist;
}

void initlift() {
	for (int i = 1; i < logn; ++i) {
		for (int j = 1; j <= n; ++j) {
			par[i][j] = par[i - 1][par[i - 1][j]];
		}
	}
}

bool isanc(int u, int v) {
	return tin[u] <= tin[v] && tout[v] <= tout[u];
}

int lca(int u, int v) {
	if (isanc(u, v)) {
		return u;
	} else if (isanc(v, u)) {
		return v;
	}
	for (int i = logn - 1; i >= 0; --i) {
		if (!isanc(par[i][u], v)) {
			u = par[i][u];
		}
	}
	return par[0][u];
}

void dfs(int u) {
	tin[u] = ++t;
	vstd[u] = true;
	for (auto i : adj[u]) {
		int c, w;
		tie(c, w) = i;
		if (c == par[0][u]) {
			continue;
		} else if (vstd[c]) {
			chk.emplace_back(dijkstra(u));
		} else {
			par[0][c] = u;
			dist[c] = dist[u] + w;
			dfs(c);	
		}
	}
	tout[u] = t;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int m;
	cin >> n >> m;
	logn = 32 - __builtin_clz(n);
	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	
	dfs(1);
	tout[0] = t;
	initlift();

	int q;
	cin >> q;
	while (q--) {
		int u, v;
		cin >> u >> v;
		ll ans = dist[u] + dist[v] - 2 * dist[lca(u, v)];
		for (auto& i : chk) {
			ans = min(ans, i[u] + i[v]);
		}
		cout << ans << '\n';
	}
}