#include <bits/stdc++.h>
using namespace std;

const int MX = 5000 + 1;

bool dp0[MX][MX], dp1[MX][MX], col[MX], off[MX], ok = true;
int cnt[MX][MX], cmp[MX], cur;
vector<int> adj[MX];

void dfs(int u) {
	cmp[u] = cur;
	++cnt[cur][col[u]];
	for (auto v : adj[u]) {
		if (cmp[v]) {
			if (col[v] == col[u]) {
				ok = false;
			}
			continue;
		}
		col[v] = !col[u];
		dfs(v);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, n1, n2, n3;
	cin >> n >> m >> n1 >> n2 >> n3;
	while (m--) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dp0[0][0] = dp1[0][0] = true;
	for (int i = 1; i <= n; ++i) {
		if (!cmp[i]) {
			++cur;
			dfs(i);
			for (int j = 0; j <= n; ++j) {
				if (dp0[cur - 1][j] || dp1[cur - 1][j]) {
					dp0[cur][j + cnt[cur][0]] = true;
					dp1[cur][j + cnt[cur][1]] = true;
				}
			}
		}
	}
	
	if (!ok || (!dp0[cur][n2] && !dp1[cur][n2])) {
		cout << "NO" << '\n';
		return 0;
	}

	cout << "YES" << '\n';
	int tot = n2;
	for (int i = cur; i; --i) {
		if (tot >= cnt[i][0] && dp0[i][tot]) {
			tot -= cnt[i][0];
			off[i] = true;
		} else if (tot >= cnt[i][1] && dp1[i][tot]) {
			tot -= cnt[i][1];
		}
	}

	for (int i = 1; i <= n; ++i) {
		int tru = col[i] ^ off[cmp[i]];
		if (tru) {
			cout << '2';
		} else {
			if (n1) {
				cout << '1';
				--n1;
			} else {
				cout << '3';
			}
		}
	}
	cout << '\n';
}