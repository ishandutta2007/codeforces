#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MX = 2e5 + 1;

int a[MX], cnt1[MX], cnt0[MX];
vector<int> adj[MX];
bool b[MX], c[MX];
ll ans = 0;

void dfs(int u, int p) {
	a[u] = min(a[u], a[p]);
	cnt0[u] += (!b[u] && c[u]);
	cnt1[u] += (b[u] && !c[u]);
	for (auto c : adj[u]) {
		if (c != p) {
			dfs(c, u);
			cnt0[u] += cnt0[c];
			cnt1[u] += cnt1[c];
		}
	}
	while (cnt0[u] && cnt1[u]) {
		--cnt0[u];
		--cnt1[u];
		ans += a[u] * 2;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i] >> b[i] >> c[i];
	}

	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	a[0] = 1e9;
	dfs(1, 0);
	if (cnt0[1] || cnt1[1]) {
		cout << -1 << '\n';
	} else {
		cout << ans << '\n';
	}
}