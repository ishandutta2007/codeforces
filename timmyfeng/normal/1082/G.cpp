#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
const int MX = 2500;
const int S = 0;
const int T = MX - 1;
const int INF = 2e9;

vector<pair<int, int>> edge;
vector<int> adj[MX];
bool vstd[MX];
ll ans;

void addEdge(int u, int v, int w) {
	adj[u].push_back(edge.size());
	edge.emplace_back(v, w);
	adj[v].push_back(edge.size());
	edge.emplace_back(u, 0);
}

bool dfs(int u, int thr) {
	if (u == T) {
		ans -= thr;
		return true;
	}
	vstd[u] = true;
	for (auto e : adj[u]) {
		auto& [v, w] = edge[e];
		if (w < thr || vstd[v])
			continue;
		if (dfs(v, thr)) {
			w -= thr;
			edge[e ^ 1].second += thr;
			return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		int a;
		cin >> a;
		addEdge(i, T, a);
	}
	for (int i = n + 1; i <= n + m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		ans += w;
		addEdge(S, i, w);
		addEdge(i, u, INF);
		addEdge(i, v, INF);
	}

	for (int i = INF; i; i /= 2) {
		while (true) {
			memset(vstd, false, sizeof vstd);
			if (!dfs(S, i))
				break;
		}
	}
	cout << ans << '\n';
}