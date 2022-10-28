#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<vector<int>> adj;

void bfs(vector<int>& dist, int src) {
	queue<int> q;
	dist[src] = 0;
	q.push(src);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto c : adj[u]) {
			if (dist[c] == -1) {
				dist[c] = dist[u] + 1;
				q.push(c);
			}
		}
	}
}

void solve() {
	int n, m, a, b, c;
	cin >> n >> m >> a >> b >> c;
	vector<ll> p(m + 1);
	for (int i = 1; i <= m; ++i) {
		cin >> p[i];
	}
	adj.assign(n + 1, vector<int>());
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> dista(n + 1, -1), distb(n + 1, -1), distc(n + 1, -1);
	bfs(dista, a);
	bfs(distb, b);
	bfs(distc, c);

	sort(p.begin() + 1, p.end());
	for (int i = 1; i <= m; ++i) {
		p[i] += p[i - 1];
	}

	ll ans = 1e18;
	for (int i = 1; i <= n; ++i) {
		if (dista[i] + distc[i] + distb[i] > m) continue;
		ll res = p[distb[i]] + p[dista[i] + distb[i] + distc[i]];
		ans = min(ans, res);
	}
	cout << ans << '\n';
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