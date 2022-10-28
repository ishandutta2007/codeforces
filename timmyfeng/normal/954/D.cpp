#include <bits/stdc++.h>
using namespace std;

const int MX = 1000 + 1;

vector<int> adj[MX];
bool cnt[MX][MX];
int n;

vector<int> bfs(int src) {
	vector<int> res(n + 1, -1);
	res[src] = 0;
	queue<int> que;
	que.push(src);
	while (!que.empty()) {
		int u = que.front();
		que.pop();
		for (auto v : adj[u]) {
			if (res[v] == -1) {
				res[v] = res[u] + 1;
				que.push(v);
			}
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int m, s, t;
	cin >> n >> m >> s >> t;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		cnt[u][v] = true;
		cnt[v][u] = true;
	}

	vector<int> dist_s = bfs(s);
	vector<int> dist_t = bfs(t);

	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			if (cnt[i][j])
				continue;
			ans += (dist_s[i] + dist_t[j] + 1 >= dist_s[t] && dist_s[j] + dist_t[i] + 1 >= dist_s[t]);		
		}
	}
	cout << ans << '\n';
}