#include <bits/stdc++.h>
using namespace std;
const int MX = 2e5;
vector<int> adj[MX + 1];
bool vstd[MX + 1];
int dep[MX + 1];
int par[MX + 1];
int tin[MX + 1], tout[MX + 1];
int v[MX + 1];

int d = 0;
int t = 0;
void dfs(int u) {
	dep[u] = ++d;
	tin[u] = ++t;
	for (auto c : adj[u]) {
		if (c != par[u]) {
			par[c] = u;
			dfs(c);
		}
	}
	--d;
	tout[u] = ++t;
}

bool cmp(int a, int b) {
	return dep[a] < dep[b];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n - 1; ++i) { 
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1);

	while (m--) {
		int k;
		cin >> k;
		for (int i = 0; i < k; ++i) {
			cin >> v[i];
			if (v[i] != 1) {
				v[i] = par[v[i]];
			}
		}
		sort(v, v + k, cmp);
		bool ok = true;
		for (int i = 1; i < k; ++i) {
			if (tin[v[i]] < tin[v[i - 1]] || tout[v[i]] > tout[v[i - 1]]) {
				ok = false;
			}
		}
		if (ok) {
			cout << "YES" << '\n';
		} else {
			cout << "NO" << '\n';
		}
	}
}