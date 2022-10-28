#include <bits/stdc++.h> 
using namespace std;

const int MX = 2e5 + 1;

vector<int> a, jda[MX], adj[MX];
bool vstd[MX], done[MX];
int dp[MX], mn[MX];

void topo(int u) {
	vstd[u] = true;
	for (auto c : adj[u]) {
		if (vstd[c]) {
			if (!done[c]) {
				cout << -1 << '\n';
				exit(0);
			}
			continue;
		}
		topo(c);
	}
	done[u] = true;
	a.push_back(u);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	while (m--) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		jda[v].push_back(u);
	}

	for (int i = 1; i <= n; ++i) {
		if (!vstd[i]) {
			topo(i);
		}
	}

	auto getmn = [&](vector<int>* gra) {
		iota(dp + 1, dp + 1 + n, 1);
		for (int i = 0; i < n; ++i) {
			mn[a[i]] = min(mn[a[i]], dp[a[i]]);
			for (auto c : gra[a[i]]) {
				dp[c] = min(dp[c], dp[a[i]]);
			}
		}
	};

	iota(mn + 1, mn + 1 + n, 1);
	getmn(jda);
	reverse(a.begin(), a.end());
	getmn(adj);

	string ans = "";
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		if (mn[i] == i) {
			ans += 'A';
			++cnt;
		} else {
			ans += 'E';
		}
	}
	cout << cnt << '\n';
	cout << ans << '\n';
}