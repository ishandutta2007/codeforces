#include <bits/stdc++.h> 
using namespace std;

const int MX = 2e5 + 5;

int s[MX], pre_sum[MX], ans[MX], time_in[MX], time_out[MX], edge[MX], parity[MX], t;
vector<tuple<int, int, int>> adj[MX];

void dfs(int u) {
	time_in[u] = ++t;
	for (auto [c, i, s] : adj[u]) {
		if (time_in[c])
			continue;
		edge[c] = i;
		parity[c] = s;
		dfs(c);
	}
	time_out[u] = t;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int sum = 0;
	vector<int> pos, neg;
	for (int i = 1; i <= n; ++i) {
		cin >> s[i];
		if (s[i] >= 0) {
			pos.push_back(i);
		} else {
			neg.push_back(i);
		}
		sum += s[i];
	}
	
	int m;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].emplace_back(v, i, 1);
		adj[v].emplace_back(u, i, -1);
	}

	if (sum) {
		cout << "Impossible" << '\n';
		return 0;
	}

	dfs(1);

	while (!neg.empty()) {
		int u = neg.back();
		while (s[u]) {
			int v = pos.back();
			int val = min(s[v], -s[u]);

			pre_sum[time_in[u]] -= val;
			pre_sum[time_in[v]] += val;

			s[u] += val;
			s[v] -= val;
			if (!s[v]) {
				pos.pop_back();
			}
		}
		neg.pop_back();
	}

	for (int i = 1; i <= t; ++i) {
		pre_sum[i] += pre_sum[i - 1];
	}
	for (int i = 2; i <= n; ++i) {
		ans[edge[i]] = (pre_sum[time_out[i]] - pre_sum[time_in[i] - 1]) * parity[i];
	}

	cout << "Possible" << '\n';
	for (int i = 0; i < m; ++i) {
		cout << ans[i] << '\n';
	}
}