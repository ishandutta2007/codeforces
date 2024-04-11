#include <bits/stdc++.h>
using namespace std;

bool dfs(int a, int L, vector<vector<int>>& g, vector<int>& btoa, vector<int>& A, vector<int>& B) {
	if (A[a] != L) return 0;
	A[a] = -1;
	for (auto &b: g[a]) if (B[b] == L + 1) {
		B[b] = 0;
		if (btoa[b] == -1 || dfs(btoa[b], L + 1, g, btoa, A, B))
			return btoa[b] = a, 1;
	}
	return 0;
}

int hopcroftKarp(vector<vector<int>>& g, vector<int>& btoa) {
	int res = 0;
	vector<int> A(g.size()), B(btoa.size()), cur, next;
	for (;;) {
		fill(A.begin(), A.end(), 0);
		fill(B.begin(), B.end(), 0);
		/// Find the starting nodes for BFS (i.e. layer 0).
		cur.clear();
		for (auto &a: btoa) if(a != -1) A[a] = -1;
		for (int a = 0; a < g.size(); a++) if(A[a] == 0) cur.push_back(a);
		/// Find all layers using bfs.
		for (int lay = 1;; lay++) {
			bool islast = 0;
			next.clear();
			for (auto &a: cur) for (auto &b: g[a]) {
				if (btoa[b] == -1) {
					B[b] = lay;
					islast = 1;
				}
				else if (btoa[b] != a && !B[b]) {
					B[b] = lay;
					next.push_back(btoa[b]);
				}
			}
			if (islast) break;
			if (next.empty()) return res;
			for (auto &a: next) A[a] = lay;
			cur.swap(next);
		}
		/// Use DFS to scan for augmenting paths.
		for (int a = 0; a < g.size(); a++) 
			res += dfs(a, 0, g, btoa, A, B);
	}
}

bool check(int n, int m, vector<tuple<int, int, int>> &edges) {
	vector<vector<int>> g(n);
	for (auto [u, v, w]: edges) {
		if (w <= m) {
			g[u].push_back(v);
		}
	}
	vector<int> btoa(n, -1); 

	return hopcroftKarp(g, btoa) == n;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m; cin >> n >> m;
	vector<tuple<int, int, int>> edges;
	for (int i = 0; i < m; i++) {
		int u, v, w; 
		cin >> u >> v >> w; u--, v--;
		edges.emplace_back(u, v, w);
	}

	int l = 1, r = 1000000000, ok = 0;
	while (l < r) {
		int mid = (l + r)/2;

		if (check(n, mid, edges)) {
			r = mid; ok = 1;
		} else {
			l = mid+1;
		}
	}
	if (ok) cout << l;
	else cout << -1;

	return 0;
}