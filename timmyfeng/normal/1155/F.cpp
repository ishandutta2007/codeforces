#include <bits/stdc++.h> 
using namespace std;

const int MX = 14;

int path[MX + 1][MX + 1][1 << MX], dp[1 << MX], pre[1 << MX];
pair<int, int> pts[1 << MX];
vector<int> adj[MX + 1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	while (m--) {
		int u, v;
		cin >> u >> v;
		--u;
		--v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	memset(path, -1, sizeof path);
	for (int i = 0; i < n; ++i) {
		for (auto c : adj[i]) {
			path[i][c][0] = i;
		}
	}

	for (int ma = 0; ma < (1 << n); ++ma) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (i == j || (ma & (1 << i)) || (ma & (1 << j)) || path[i][j][ma] == -1)
					continue;
				for (auto c : adj[j]) {
					if ((ma & (1 << c)) || c == path[i][j][ma])
						continue;
					int nma = ma ^ (1 << j);
					path[i][c][nma] = j;
				}
			}
		}
	}

	for (int ma = 2; ma < (1 << n); ++ma) {
		dp[ma] = 1e9;
		for (int nma = ma; nma; nma = (nma - 1) & ma) {
			int pma = ma ^ nma;
			int cnt = __builtin_popcount(nma) + 1;
			if (dp[pma] + cnt >= dp[ma])
				continue;
			bool ok = false;
			for (int i = 0; i < n && !ok; ++i) {
				for (int j = 0; j < n && !ok; ++j) {
					if ((ma & (1 << j)) && (ma & (1 << i))) {
						if (path[i][j][nma] != -1) {
							dp[ma] = dp[pma] + cnt;
							pts[ma] = {i, j};
							pre[ma] = nma;
							ok = true;
						}
					}
				}
			}
		}
	}

	if (dp[(1 << n) - 1] == 1e9) {
		cout << -1 << '\n';
	} else {
		int cur = (1 << n) - 1;
		cout << dp[cur] << '\n';
		while (cur != 1) {
			int ma = pre[cur], u, v;
			tie(u, v) = pts[cur];
			cur ^= ma;
			while (ma) {
				int p = path[u][v][ma];
				cout << p + 1 << ' ' << v + 1 << '\n';
				ma ^= 1 << p;
				v = p;
			}
			cout << u + 1 << ' ' << v + 1 << '\n';
		}
	}
}