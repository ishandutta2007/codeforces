#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 3030;
int n;
vector<int> g[N];
int h[N];
int par[N][N];
int lca[N][N];
ll dp[N][N];
int sz[N];

void dfs(int v) {
	sz[v] = 1;
	par[v][h[v]] = v;
	for (int u : g[v]) {
		if (h[u] != -1) continue;
		h[u] = h[v] + 1;
		for (int i = 0; i <= h[v]; i++)
			par[u][i] = par[v][i];
		dfs(u);
		sz[v] += sz[u];
	}
}

int LCA(int v, int u) {
	if (v == u) return v;
	if (v > u) swap(v, u);
	if (lca[v][u] != -1) return lca[v][u];
	if (h[v] > h[u])
		lca[v][u] = LCA(par[v][h[v] - 1], u);
	else
		lca[v][u] = LCA(v, par[u][h[u] - 1]);
	return lca[v][u];
}

ll DP(int v, int u) {
	if (v == u) return 0;
	if (v > u) swap(v, u);
	if (dp[v][u] != -1) return dp[v][u];
	dp[v][u] = 0;
	int w = LCA(v, u);
	if (v == w) {
		dp[v][u] = max(dp[v][u], DP(v, par[u][h[u] - 1]));
		dp[v][u] = max(dp[v][u], DP(par[u][h[v] + 1], u));
		dp[v][u] += (n - sz[par[u][h[v] + 1]]) * sz[u];
	} else if (u == w) {
		dp[v][u] = max(dp[v][u], DP(u, par[v][h[v] - 1]));
		dp[v][u] = max(dp[v][u], DP(par[v][h[u] + 1], v));
		dp[v][u] += (n - sz[par[v][h[u] + 1]]) * sz[v];
	} else {
		dp[v][u] = max(dp[v][u], DP(v, par[u][h[u] - 1]));
		dp[v][u] = max(dp[v][u], DP(par[v][h[v] - 1], u));
		dp[v][u] += sz[v] * sz[u];
	}
	return dp[v][u];
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	for (int i = 0; i < n; i++)
		h[i] = -1;
	h[0] = 0;
	dfs(0);

	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++) {
			lca[i][j] = -1;
			dp[i][j] = -1;
		}

	ll ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			ans = max(ans, DP(i, j));
	
//	for (int i = 0; i < n; i++)
//		for (int j = i + 1; j < n; j++)
//			eprintf("dp[%d][%d] = %lld\n", i, j, dp[i][j]);

	printf("%lld\n", ans);

	return 0;
}