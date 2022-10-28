#include <bits/stdc++.h>
using namespace std;

const int MX = 2e5;

vector<int> adj[MX + 1];
int dist[MX + 1], par[MX + 1];

void dfs(int u) {
	for (auto c : adj[u]) {
		if (c == par[u]) continue;
		dist[c] = dist[u] + 1;
		par[c] = u;
		dfs(c);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1);
	int a = max_element(dist + 1, dist + 1 + n) - dist;
	dist[a] = 0;
	par[a] = 0;
	dfs(a);
	int b = max_element(dist + 1, dist + 1 + n) - dist;
	int dia = dist[b];
	if (dia == n - 1) {
		cout << n - 1 << '\n';
		int c = 1;
		for ( ; a == c || b == c; ++c);
		cout << a << ' ' << b << ' ' << c << '\n';
		return 0;
	}

	memset(dist, -1, sizeof dist);
	queue<int> bfs;
	for (int i = b; i != par[a]; i = par[i]) {
		bfs.push(i);
		dist[i] = 0;
	}
	while (!bfs.empty()) {
		int u = bfs.front();
		bfs.pop();
		for (auto c : adj[u]) {
			if (dist[c] == -1) {
				dist[c] = dist[u] + 1;
				bfs.push(c);
			}
		}
	}

	int c = max_element(dist + 1, dist + 1 + n) - dist;
	cout << dia + dist[c] << '\n';
	cout << a << ' ' << b << ' ' << c << '\n';	
}