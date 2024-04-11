#include <bits/stdc++.h>
using namespace std;

const int MX = 2e5 + 1;

vector<int> adj[MX];
bool col[MX];
int cnt;

void dfs(int u, int p) {
	cnt += col[u];
	for (auto c : adj[u]) {
		if (c != p) {
			col[c] = !col[u];
			dfs(c, u);
		}
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

	dfs(1, 0);

	cout << min(cnt - 1, n - cnt - 1) << "\n";
}