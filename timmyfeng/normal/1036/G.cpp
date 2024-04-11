#include <bits/stdc++.h> 
using namespace std;

const int MX = 1e6 + 1;
const int MXS = 20;

int ndx[MX], inc[MXS], deg[MX], cur;
vector<int> adj[MX];
bool vstd[MX];

void dfs(int u) {
	vstd[u] = true;
	if (ndx[u] != -1) {
		inc[cur] |= 1 << ndx[u];
	}
	for (auto v : adj[u]) {
		if (!vstd[v]) {
			dfs(v);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	while (m--) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		++deg[v];
	}

	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		ndx[i] = adj[i].empty() ? cnt++ : -1;
	}

	for (int i = 1; i <= n; ++i) {
		if (!deg[i]) {
			memset(vstd, false, sizeof vstd);
			dfs(i);
			++cur;
		}
	}

	for (int ma = 1; ma < (1 << cnt) - 1; ++ma) {
		int all = 0;
		for (int i = 0; i < cnt; ++i) {
			if (ma & (1 << i)) {
				all |= inc[i];
			}
		}
		if (__builtin_popcount(ma) >= __builtin_popcount(all)) {
			cout << "NO" << '\n';
			return 0;
		}
	}
	cout << "YES" << '\n';
}