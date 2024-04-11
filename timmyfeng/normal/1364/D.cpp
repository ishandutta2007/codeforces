#include <bits/stdc++.h>
using namespace std;

const int MX = 2e5 + 1;

vector<int> adj[MX];
pair<int, int> pts;
int col[MX], dep[MX], par[MX], best, k;
bool odd[MX];

void dfs(int u, int p) {
	col[u] = 1;
	if (dep[u] % 2) {
		odd[u] = true;
	}

	for (auto c : adj[u]) {
		if (c == p)
			continue;
		if (col[c] == 1) {
			if (dep[u] - dep[c] + 1 < best) {
				best = dep[u] - dep[c] + 1;
				pts = {u, c};
			}
		} else if (!col[c]) {
			par[c] = u;
			dep[c] = dep[u] + 1;
			dfs(c, u);
		}
	}
	col[u] =2;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m >> k;

	while (m--) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	best = 1e9;
	dfs(1, 0);

	if (best <= k) {
		cout << 2 << '\n';
		cout << best << '\n';
		while (pts.first != pts.second) {
			cout << pts.first << ' ' ;
			pts.first = par[pts.first];
		}
		cout << pts.second << '\n';
	} else if (best < 1e9) {
		cout << 1 << '\n';
		for (int i = 0; i < (k + 1) / 2; ++i) {
			cout << pts.first << ' ';
			pts.first = par[par[pts.first]];
		}
		cout << '\n';
	} else {
		cout << 1 << '\n';
		bool flip = count(odd + 1, odd + 1 + n, true) < (k + 1) / 2;
		for (int i = 1, j = 0; i <= n && j < (k + 1) / 2; ++i) {
			if (flip ^ odd[i]) {
				cout << i << ' ' ;
				++j;
			}
		}
		cout << '\n';
	}
}