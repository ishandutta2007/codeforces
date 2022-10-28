#include <bits/stdc++.h>
using namespace std;

const int MX = 500 + 1;
const int MXK = 11;
const int INF = 0x3f3f3f3f;
const int AL = 10;

int dp[MX][MX][MXK], dpChd[MX][AL + 1][MX][MXK], to[MX][AL], cnt[MX], len[MX], sz, k;

void dfs(int u) {
	for (int l = 0; l <= len[u]; ++l) {
		dpChd[u][0][l][0] = 0;
	}
	for (int i = 0; i < AL; ++i) {
		int c = to[u][i];
		if (c) {
			dfs(c);
			for (int l = 0; l <= len[u]; ++l) {
				for (int v = 0; v <= k; ++v) {
					for (int j = 0; j <= v; ++j) {
						dpChd[u][i + 1][l][v] = min(dpChd[u][i + 1][l][v], dpChd[u][i][l][v - j] + dp[c][l][j]);
					}
				}
			}
		} else {
			for (int l = 0; l <= len[u]; ++l) {
				for (int j = 0; j <= k; ++j) {
					dpChd[u][i + 1][l][j] = dpChd[u][i][l][j];
				}
			}
		}
	}

	for (int l = 0; l <= len[u]; ++l) {
		for (int v = 0; v <= k; ++v) {
			dp[u][l][v] = (len[u] - l) * cnt[u] + dpChd[u][AL][l][v];
		}
	}
	for (int l = 0; l < len[u]; ++l) {
		for (int v = 1; v <= k; ++v) {
			dp[u][l][v] = min(dp[u][l][v], dp[u][len[u]][v - 1]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		string s;
		int m;
		cin >> s >> m;

		int cur = 0;
		for (auto c : s) {
			if (!to[cur][c - '0']) {
				to[cur][c - '0'] = ++sz;
				len[sz] = len[cur] + 1;
			}
			cur = to[cur][c - '0'];
		}
		cnt[cur] += m;
	}

	memset(dp, INF, sizeof dp);
	memset(dpChd, INF, sizeof dpChd);
	dfs(0);
	cout << *min_element(dp[0][0], dp[0][0] + k + 1) << '\n';
}