#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MX = 1e5;

vector<int> adj[MX + 1];
ll cost[3][MX + 1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < 3; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> cost[i][j];
		}
	}
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int rt = 0;
	ll ans = 1e18;
	for (int i = 1; i <= n; ++i) {
		if (adj[i].size() > 2) {
			cout << -1 << '\n';
			return 0;
		}
		if (adj[i].size() == 1) {
			rt = i;
		}
	}

	vector<int> perm = {0, 1, 2};
	vector<int> col;
	do {
		int p = 0, i = 0;
		vector<int> tmp(n + 1);
		ll res = cost[perm[i]][rt];
		tmp[rt] = perm[i];
		int k = rt;
		for (int j = rt; ; j = k) {
			i = (i + 1) % 3;
			for (auto c : adj[j]) {
				if (c != p) {
					k = c;
					res += cost[perm[i]][c];
					tmp[c] = perm[i];
				}
			}
			p = j;
			if (k == j) break;
		}
		if (res < ans) {
			col = tmp;
			ans = res;
		}
	} while (next_permutation(perm.begin(), perm.end()));
	cout << ans << '\n';
	for (int i = 1; i <= n; ++i) {
		cout << col[i] + 1 << ' ';
	}
	cout << '\n';
}