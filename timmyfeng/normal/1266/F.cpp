#include <bits/stdc++.h> 
using namespace std;

const int MX = 5e5 + 1;

int cnt[MX];
int oth[MX];
int best[MX];
int ans[MX * 2];
vector<int> adj[MX];
vector<int> deps[MX];

void dfs_down(int u, int p) {
	for (auto c : adj[u]) {
		if (c != p) {
			dfs_down(c, u);
			if (best[c] + 1 > best[u]) {
				oth[u] = best[u];
				best[u] = best[c] + 1;
			} else if (best[c] + 1 > oth[u]) {
				oth[u] = best[c] + 1;
			}
		}
	}
	deps[p].push_back(best[u] + 1);
}

void dfs_up(int u, int p) {
	if (p) {
		deps[u].push_back(best[p] + 1);
		if (best[p] + 1 > best[u]) {
			oth[u] = best[u];
			best[u] = best[p] + 1;
		} else if (best[p] + 1 > oth[u]) {
			oth[u] = best[p] + 1;
		}
	}

	for (auto c : adj[u]) {
		if (c != p) {
			if (best[u] == best[c] + 1) {
				swap(best[u], oth[u]);
			}
			dfs_up(c, u);
			if (oth[u] > best[u]) {
				swap(oth[u], best[u]);
			}
		}
	}
}

void dfs(int u, int p) {
	vector<pair<int, int>> chd;
	sort(deps[u].rbegin(), deps[u].rend());

	for (int i = 0; i < int(deps[u].size()); ++i) {
		int d = deps[u][i];
		chd.emplace_back(d, u);

		if (i && d + 1 <= deps[u][i - 1]) {
			ans[d * 2 + 1] = max(ans[d * 2 + 1], i + 1);
		}
		ans[d * 2 - 1] = max(ans[d * 2 - 1], i + 1);
		ans[d * 2] = max(ans[d * 2], i + 1);
	}

	for (auto c : adj[u]) {
		if (c != p) {
			dfs(c, u);
			cnt[c] = 0;
			for (auto i : deps[c]) {
				chd.emplace_back(i, c);
			}
		}
	}

	int mx = 0;
	sort(chd.rbegin(), chd.rend());
	for (auto [d, i] : chd) {
		++cnt[i];
		if (i != u) {
			mx = max(mx, cnt[i]);
		}
		ans[2 * d] = max(ans[2 * d], cnt[u] + mx - 2);
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

	fill(ans, ans + n + 1, 1);
	for (int i = 1; i <= n; ++i) {
		ans[1] = max(ans[1], int(adj[i].size()) + 1);
	}

	dfs_down(1, 0);
	dfs_up(1, 0);
	dfs(1, 0);

	for (int i = n - 2; i; --i) {
		ans[i] = max(ans[i], ans[i + 2]);
	}

	for (int i = 1; i <= n; ++i) {
		cout << ans[i] << " ";
	}
	cout << "\n";
}