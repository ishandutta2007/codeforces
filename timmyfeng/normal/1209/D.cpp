#include <bits/stdc++.h>
using namespace std;

const int MX = 1e5 + 1;

vector<int> adj[MX];
bool vstd[MX];
bool used[MX];
int x[MX];
int y[MX];
int ans;

void dfs(int u) {
	vstd[u] = true;
	for (auto e : adj[u]) {
		if (used[e])
			continue;
		int c = x[e] == u ? y[e] : x[e];
		used[e] = true;
		if (vstd[c]) {
			++ans;
		} else {
			dfs(c);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < k; ++i) {
		cin >> x[i] >> y[i];
		adj[x[i]].push_back(i);
		adj[y[i]].push_back(i);
	}

	for (int i = 1; i <= n; ++i) {
		if (!vstd[i]) {
			dfs(i);
		}
	}
	cout << ans << "\n";
}