#include <bits/stdc++.h>
using namespace std;

const int MX = 2e5 + 1;

vector<int> adj[MX];
int cost[MX];

long long closed[MX];
long long open[MX];
long long sum[MX];

vector<int> opt_chd[MX];
bool opt_closed[MX];
bool opt_open[MX];

vector<int> ans;

void dfs_calc(int u, int p) {
	if (u != 1 && adj[u].size() == 1u) {
		closed[u] = cost[u];
		return;
	}

	long long best = 0;
	for (auto c : adj[u]) {
		if (c != p) {
			dfs_calc(c, u);
			sum[u] += closed[c];

			long long val = open[c] - closed[c];
			if (val < best) {
				opt_chd[u].clear();
				best = val;
			}
			if (val == best) {
				opt_chd[u].push_back(c);
			}
		}
	}

	open[u] = sum[u] + best;
	closed[u] = min(sum[u], open[u] + cost[u]);
}

void dfs_find(int u, int p) {
	if (opt_closed[u]) {
		if (sum[u] == closed[u]) {
			for (auto c : adj[u]) {
				if (c != p) {
					opt_closed[c] = true;
				}
			}
		}
		if (open[u] + cost[u] == closed[u]) {
			ans.push_back(u);
			opt_open[u] = true;
		}
	}

	if (opt_open[u]) {
		for (auto c : opt_chd[u]) {
			opt_open[c] = true;
		}
		for (auto c : adj[u]) {
			if (c != p && (opt_chd[u].size() > 1u || c != opt_chd[u][0])) {
				opt_closed[c] = true;
			}
		}
	}

	for (auto c : adj[u]) {
		if (c != p) {
			opt_closed[c] |= (opt_closed[u] && sum[u] == closed[u]);
			dfs_find(c, u);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> cost[i];
	}

	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	opt_closed[1] = true;
	dfs_calc(1, 0);
	dfs_find(1, 0);

	cout << closed[1] << " " << ans.size() << "\n";
	sort(ans.begin(), ans.end());
	for (auto i : ans) {
		cout << i << " ";
	}
	cout << "\n";
}