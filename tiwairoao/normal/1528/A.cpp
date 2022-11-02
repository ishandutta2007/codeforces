#include <bits/stdc++.h>

typedef long long ll;

const int N = 100000;

int read() {
	int x = 0, ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while ('0' <= ch && ch <= '9') x = 10 * x + ch - '0', ch = getchar();
	return x;
}

std::vector<int>G[N + 5];
void adde(int u, int v) {G[u].push_back(v), G[v].push_back(u);}
int a[2][N + 5];

ll dp[2][N + 5];
void dfs1(int x, int fa) {
	dp[0][x] = dp[1][x] = 0;
	for (auto to : G[x]) if (to != fa) {
		dfs1(to, x);
		dp[0][x] += std::max(dp[0][to] + std::abs(a[0][x] - a[0][to])
			, dp[1][to] + std::abs(a[0][x] - a[1][to]));
		dp[1][x] += std::max(dp[0][to] + std::abs(a[1][x] - a[0][to])
			, dp[1][to] + std::abs(a[1][x] - a[1][to]));
	}
}
void solve() {
	int n = read();
	for (int i = 1; i <= n; i++) G[i].clear(), a[0][i] = read(), a[1][i] = read();
	for (int i = 1, u, v; i < n; i++) u = read(), v = read(), adde(u, v);
	dfs1(1, 0), printf("%lld\n", std::max(dp[0][1], dp[1][1]));
}

int main() {
	for (int t = read(); t; t--) solve();
}