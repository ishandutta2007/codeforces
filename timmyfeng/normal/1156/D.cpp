#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MX = 2e5;

vector<int> adj1[MX + 1], adj0[MX + 1];
ll sz[MX + 1], ans, cur;
int col[MX + 1], cmp;
bool vstd[MX + 1];

void dfs1(int u, int ncol) {
	++sz[ncol];
	col[u] = ncol;
	for (auto c : adj1[u]) {
		if (!col[c]) {
			dfs1(c, ncol);
		}
	}
}

int dfs2(int u) {
	vstd[u] = true;
	cur += sz[col[u]] - 1;
	int cnt = 1;
	for (auto c : adj0[u]) {
		if (!vstd[c]) {
			cnt += dfs2(c);
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n  -1; ++i) {
		int u, v, t;
		cin >> u >> v >> t;
		if (t) {
			adj1[u].push_back(v);
			adj1[v].push_back(u);
		} else {
			adj0[u].push_back(v);
			adj0[v].push_back(u);
		}
	}

	for (int i = 1; i <= n; ++i) {
		if (!col[i]) {
			dfs1(i, ++cmp);
			ans += sz[cmp] * (sz[cmp] - 1);
		}
	}

	for (int i = 1; i <= n; ++i) {
		if (!vstd[i]) {
			cur = 0;
			ll cnt = dfs2(i);
			ans += cnt * (cnt - 1);
			ans += cur * (cnt - 1);
		}
	}
	
	cout << ans << '\n';
}