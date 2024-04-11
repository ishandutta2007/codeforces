#include <bits/stdc++.h>
using namespace std;
const int MX = 1e5;

int par[MX + 1], sz[MX + 1];
long long ans[3 * MX], dist[MX + 1];
vector<int> token[MX + 1];
vector<pair<int, long long>> adj[MX + 1];
pair<int, int> query[3 * MX];
tuple<long long, int, int> edge[3 * MX];

int find(int a) {
	if (par[a] == a) return a;
	return par[a] = find(par[a]);
}

void unite(int a, int b, long long c) {
	a = find(a);
	b = find(b);
	if (a != b) {
		if (sz[a] > sz[b]) {
			swap(a, b);
		}
		par[a] = b;
		sz[b] += sz[a];
		for (auto i : token[a]) {
			if (query[i].first == query[i].second) continue;
			if (query[i].first != a) {
				swap(query[i].first, query[i].second);
			}
			query[i].first = b;
			if (query[i].second == b) {
				ans[i] = c;
			} else {
				token[b].push_back(i);
			}
		}
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int n, m, k, q;
	cin >> n >> m >> k >> q;
	for (int i = 0; i < m; ++i) {
		int u, v;
		long long w;
		cin >> u >> v >> w;
		edge[i] = make_tuple(w, u, v);
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	
	memset(dist, 0x3F3F3F3F, sizeof dist);
	priority_queue<pair<long long, int>> dijkstra;
	for (int i = 1; i <= k; ++i) {
		dist[i] = 0;
		dijkstra.emplace(0, i);
	}
	while (!dijkstra.empty()) {
		int u;
		long long d;
		tie(d, u) = dijkstra.top();
		dijkstra.pop();
		if (-d > dist[u]) continue;
		for (auto e : adj[u]) {
			if (-d + e.second < dist[e.first]) {
				dist[e.first] = -d + e.second;
				dijkstra.emplace(-dist[e.first], e.first);
			}
		}
	}
	for (int i = 0; i < m; ++i) {
		int u, v;
		tie(ignore, u, v) = edge[i];
		get<0>(edge[i]) += dist[u] + dist[v];
	}
	sort(edge, edge + m);
	
	for (int i = 0; i < q; ++i) {
		int a, b;
		cin >> a >> b;
		query[i] = {a, b};
		token[a].push_back(i);
		token[b].push_back(i);
	}
	iota(par + 1, par + 1 + n, 1);
	fill(sz + 1, sz + 1 + n, 1);
	for (int i = 0; i < m; ++i) {
		int u, v;
		long long w;
		tie(w, u, v) = edge[i];
		unite(u, v, w);
	}
	for (int i = 0; i < q; ++i) {
		cout << ans[i] << '\n';
	}
}