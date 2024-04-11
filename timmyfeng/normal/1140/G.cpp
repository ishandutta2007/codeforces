#include <bits/stdc++.h> 
using namespace std;
 
using ll = long long;
const int MX = 3e5 + 1;
const int LOG = 19;
const ll INF = 1e18;
 
int par[LOG][MX], tin[MX], tout[MX], logn, t;
vector<pair<int, ll>> adj[3][MX];
vector<vector<ll>> dp[LOG][MX];
ll cross[MX];
 
vector<vector<ll>> merge(const vector<vector<ll>>& a, const vector<vector<ll>>& b) {
	vector<vector<ll>> res(2, vector<ll>(2, INF));
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			for (int k = 0; k < 2; ++k) {
				res[i][j] = min(res[i][j], a[i][k] + b[k][j]);
			}
		}
	}
	return move(res);
}
 
void dfs(int u) {
	tin[u] = ++t;
	ll up0 = INF, up1 = INF;
	for (auto [c, w] : adj[0][u]) {
		if (c == par[0][u]) {
			up0 = w;
			continue;
		}
		par[0][c] = u;
		dfs(c);
	}
	for (auto [c, w] : adj[1][u]) {
		if (c == par[0][u]) {
			up1 = w;
		}
	}
 
	dp[0][u] = merge({{0, cross[u]}, {cross[u], 0}}, {
			{up0, up0 + cross[par[0][u]]},
			{up1 + cross[par[0][u]], up1}
	});
	tout[u] = ++t;
}
 
bool isanc(int u, int v) {
	return tin[u] <= tin[v] && tout[v] <= tout[u];
}
 
int lca(int u, int v) {
	if (isanc(u, v))
		return u;
	if (isanc(v, u))
		return v;
	for (int i = logn - 1; i >= 0; --i) {
		if (!isanc(par[i][v], u)) {
			v = par[i][v];
		}
	}
	return par[0][v];
}
 
vector<vector<ll>> qry(int u, int v) {
	vector<vector<ll>> res = {{0, cross[v]}, {cross[v], 0}};
	if (!isanc(v, u)) {
		for (int i = logn - 1; i >= 0; --i) {
			if (!isanc(par[i][v], u)) {
				res = merge(res, dp[i][v]);
				v = par[i][v];
			}
		}
		res = merge(res, dp[0][v]);
	}
	return move(res);
}
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	int n;
	cin >> n;
	auto addedge = [&](int i, int u, int v, ll w) {
		adj[i][u].emplace_back(v, w);
		adj[i][v].emplace_back(u, w);
	};
	for (int i = 1; i <= n; ++i) {
		ll w;
		cin >> w;
		addedge(2, 0, i, w);
	}
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		ll w1, w2;
		cin >> u >> v >> w1 >> w2;
		addedge(0, u, v, w2);
		addedge(1, u, v, w1);
		addedge(2, u, v, w1 + w2);
	}
 
	fill_n(cross, n + 1, INF);
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	pq.emplace(0, 0);
	cross[0] = 0;
	while (!pq.empty()) {
		auto [d, u] = pq.top();
		pq.pop();
		if (d > cross[u])
			continue;
		for (auto [c, w] : adj[2][u]) {
			if (d + w < cross[c]) {
				cross[c] = d + w;
				pq.emplace(cross[c], c);
			}
		}
	}
 
	dfs(1);
	tout[0] = ++t;
	logn = 32 - __builtin_clz(n);
	for (int i = 1; i < logn; ++i) {
		for (int j = 1; j <= n; ++j) {
			int mi = par[i - 1][j];
			par[i][j] = par[i - 1][mi];
			if (par[i][j]) {
				dp[i][j] = merge(dp[i - 1][j], dp[i - 1][mi]);
			}
		}
	}
 
	int q;
	cin >> q;
	while (q--) {
		int u, v;
		cin >> u >> v;
		int s = u % 2;
		int t = v % 2;
		u = (u + 1) / 2;
		v = (v + 1) / 2;
		int m = lca(u, v);
		vector<vector<ll>> resr = qry(m, v);
		swap(resr[0][1], resr[1][0]);
		cout << merge(qry(m, u), resr)[s][t] << '\n';
	}
}