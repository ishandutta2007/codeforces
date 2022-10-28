#include <bits/stdc++.h>
using namespace std;

const int MX = 5e3;

bool vstd[MX + 1];
int ans[MX + 1];
vector<int> stk;
vector<pair<int, int>> adj[MX + 1];
int cur = 0;

void dfs(int u) {
	vstd[u] = true;
	stk.push_back(u);
	for (auto [c, i] : adj[u]) {
		if (count(stk.begin(), stk.end(), c)) {
			ans[i] = 2;
		} else {
			ans[i] = 1;
		}
		if (!vstd[c]) {
			dfs(c);
		}
	}
	stk.pop_back();
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].emplace_back(v, i);
	}

	for (int i = 1; i <= n; ++i) {
		if (!vstd[i]) {
			++cur;
			dfs(i);
		}
	}
	cout << *max_element(ans, ans + m) << '\n';
	for (int i = 0; i < m; ++i ){
		cout << ans[i] << ' ';
	}
	cout << '\n';
}