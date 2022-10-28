#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;

int cnt[N];
int row[N];
int col[N][2];

bool ok;
int color[N];
int component[N];
int component_color[N];

vector<pair<int, int>> adj[N];

pair<int, int> dfs(int u, int cur) {
	pair<int, int> res;
	if (color[u] == 1) {
		++res.first;
	} else {
		++res.second;
	}
	component[u] = cur;

	for (auto [v, w] : adj[u]) {
		if (component[v] == 0) {
			color[v] = color[u] ^ w;
			auto chd = dfs(v, cur);
			res.first += chd.first;
			res.second += chd.second;
		} else {
			ok &= (color[v] == (color[u] ^ w));
		}
	}
	return res;
}

void solve() {
	int n;
	cin >> n;

	fill(cnt, cnt + n + 1, 0);
	fill(row, row + n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		col[i][0] = 0;
		col[i][1] = 0;
	}

	fill(adj, adj + n + 1, vector<pair<int, int>>());

	fill(color, color + n + 1, 0);
	fill(component, component + n + 1, 0);
	fill(component_color, component_color + n + 1, 0);

	ok = true;

	for (int i = 0; i < 2; ++i) {
		for (int j = 1; j <= n; ++j) {
			int a;
			cin >> a;
			++cnt[a];
			row[a] ^= i;
			if (col[a][0] == 0) {
				col[a][0] = j;
			} else {
				col[a][1] = j;
			}
		}
	}

	if (count(cnt, cnt + n + 1, 2) < n) {
		cout << -1 << "\n";
		return;
	}

	for (int i = 1; i <= n; ++i) {
		adj[col[i][0]].emplace_back(col[i][1], row[i] ^ 1);
		adj[col[i][1]].emplace_back(col[i][0], row[i] ^ 1);
	}

	int ans = 0;
	int cur = 0;
	for (int i = 1; i <= n; ++i) {
		if (component[i] == 0) {
			auto res = dfs(i, ++cur);
			component_color[cur] = (res.first < res.second);
			ans += min(res.first, res.second);
		}
	}

	if (!ok) {
		cout << -1 << "\n";
		return;
	}

	cout << ans << "\n";
	for (int i = 1; i <= n; ++i) {
		if (color[i] == component_color[component[i]]) {
			cout << i << " ";
		}
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}