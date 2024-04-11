#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using ii = pair<int, int>;

const int INF = 1e18;

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m, k; cin >> n >> m >> k;

	vector<ii> g[n], h;
	int d[n], ans {};
	bool bad[n] {};
	fill(d, d + n, INF);
	d[0] = 0;

	while(m--) {
		int u, v, w; cin >> u >> v >> w;
		--u, --v;
		g[u].emplace_back(v, w);
		g[v].emplace_back(u, w);
	}

	for(int i = k; i--; ) {
		int u, w; cin >> u >> w;
		ans += d[--u] < INF;
		d[u] = min(d[u], w);
	}

	priority_queue<ii> q;
	for(int u = n; u--; ) if(d[u] < INF) {
		q.emplace(-d[u], u);
		h.emplace_back(u, d[u]);
	}

	while(!empty(q)) {
		auto [dist, u] = q.top(); q.pop();
		if((dist *= -1) != d[u]) continue;
		for(const auto &[v, w] : g[u]) if(d[v] > d[u] + w)
			q.emplace(-(d[v] = d[u] + w), v);
		for(const auto &[v, w] : g[u]) if(d[v] == d[u] + w)
			bad[v] = 1;
	}

	for(const auto &[u, w] : h) ans += d[u] < INF && bad[u];
	cout << ans;
}