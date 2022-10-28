#include <bits/stdc++.h>
using namespace std;

const int MX = 1000 + 1;

vector<int> adj[MX];
int sz[MX];

void dfs_sz(int u, int p) {
	sz[u] = 1;
	for (auto c : adj[u]) {
		if (c != p) {
			dfs_sz(c, u);
			sz[u] += sz[c];
		}
	}
}

int dfs_find(int u, int p, int n) {
	for (auto c : adj[u]) {
		if (c != p && sz[c] > n / 2) {
			return dfs_find(c, u, n);
		}
	}
	return u;
}

void dfs_assign(int u, int p, int step) {
	int cnt = 0;
	for (auto c : adj[u]) {
		if (c != p) {
			cout << u << " " << c << " " << step * (cnt + 1) << "\n";
			dfs_assign(c, u, step);
			cnt += sz[c];
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

	dfs_sz(1, 0);

	int rt = dfs_find(1, 0, n);

	dfs_sz(rt, 0);
	sort(adj[rt].begin(), adj[rt].end(), [&](int a, int b) {
		return sz[a] > sz[b];
	});

	int cnt_a = 0;
	int cnt_b = 0;
	for (auto c : adj[rt]) {
		if (cnt_a * 3 < n) {
			cout << rt << " " << c << " " << cnt_a + 1 << "\n";
			dfs_assign(c, rt, 1);
			cnt_a += sz[c];
		} else {
			cout << rt << " " << c << " " << (cnt_a + 1) * (cnt_b + 1) << "\n";
			dfs_assign(c, rt, cnt_a + 1);
			cnt_b += sz[c];
		}
	}
}