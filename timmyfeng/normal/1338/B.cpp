#include <bits/stdc++.h>
using namespace std;

const int MX = 1e5;

vector<int> adj[MX + 1];
bool odd[MX + 1], even[MX + 1];
int ans1, ans2;

void dfs(int u, int p) {
	int leaf = 0;
	for (auto c : adj[u]) {
		if (c == p) continue;
		if (adj[c].size() == 1) {
			++leaf;
			odd[u] = true;
		} else {
			dfs(c, u);
			if (odd[c]) {
				even[u] = true;
			} else {
				odd[u] = true;
			}
		}
	}
	if (odd[u] && even[u]) {
		ans1 = 3;
	}
	ans2 -= max(0, leaf - 1);
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

	int rt = 1;
	if (adj[rt].size() == 1) {
		rt = adj[rt][0];
	}

	ans1 = 1;
	ans2 = n - 1;
	dfs(rt, 0);
	cout << ans1 << ' ' << ans2 << '\n';
}