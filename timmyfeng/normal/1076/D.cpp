#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
const int MX = 3e5 + 1;
const int INF = 0x3f3f3f3f;

vector<tuple<int, int, int>> adj[MX];
int pre[MX];
ll dist[MX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;
	k = min(n - 1, k);
	for (int i = 1; i <= m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w, i);
		adj[v].emplace_back(u, w, i);
	}

	cout << k << '\n';
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	memset(dist, INF, sizeof dist);
	pq.emplace(0, 1);
	dist[1] = 0;
	while (!pq.empty()) {
		auto [d, u] = pq.top();
		pq.pop();
		if (d > dist[u])
			continue;
		if (d) {
			if (!k)
				break;
			cout << pre[u] << ' ';
			--k;
		}
		for (auto [v, w, i] : adj[u]) {
			if (d + w < dist[v]) {
				pre[v] = i;
				dist[v] = d + w;
				pq.emplace(d + w, v);
			}
		}
	}
	cout << '\n';
}