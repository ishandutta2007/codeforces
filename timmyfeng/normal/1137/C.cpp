#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
const int D = 50;

vector<int> adj[N];
string schedule[N];
int visited[N];
int d;

vector<pair<int, int>> stk;
int time_in[N][D];
int color[N][D];
int low[N][D];
int timer;
int cnt;

vector<int> dag[N * D];
int val[N * D];
int dp[N * D];

inline void dfs(int u, int t) {
	int nxt = (t + 1) % d;
	stk.emplace_back(u, t);
	time_in[u][t] = ++timer;
	low[u][t] = time_in[u][t];

	for (auto& v : adj[u]) {
		if (!color[v][nxt]) {
			if (time_in[v][nxt]) {
				low[u][t] = min(low[u][t], time_in[v][nxt]);
			} else {
				dfs(v, nxt);
				low[u][t] = min(low[u][t], low[v][nxt]);
			}
		}
	}

	if (low[u][t] == time_in[u][t]) {
		++cnt;
		while (!color[u][t]) {
			int uu, tt;
			tie(uu, tt) = stk.back();
			stk.pop_back();

			if (schedule[uu][tt] == '1' && visited[uu] < cnt) {
				visited[uu] = cnt;
				++val[cnt];
			}

			color[uu][tt] = cnt;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m >> d;
	while (m--) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}

	for (int i = 1; i <= n; ++i) {
		cin >> schedule[i];
	}

	dfs(1, 0);

	for (int u = 1; u <= n; ++u) {
		for (int i = 0; i < d; ++i) {
			int nxt = (i + 1) % d;
			for (auto& v : adj[u]) {
				if (color[v][nxt] != color[u][i]) {
					dag[color[u][i]].push_back(color[v][nxt]);
				}
			}
		}
	}

	for (int u = 1; u <= cnt; ++u) {
		for (auto& v : dag[u]) {
			dp[u] = max(dp[u], dp[v]);
		}
		dp[u] += val[u];
	}

	cout << dp[cnt] << "\n";
}