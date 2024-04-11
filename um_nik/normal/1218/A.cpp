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

const int N = 15005;
int n;
vector<int> g[N];
int deg[N];
int q[N];
int topQ;
vector<int> G[N];
int cyc[N];
int pref[2 * N];
int dp[2][N];
int m;
int sz[N];
int bstSt[N];
int addAll = 0;

void dfs2(int v) {
	cyc[m++] = v;
	deg[v] = 1;
	for (int u : g[v]) {
		if (deg[u] == 1) continue;
		dfs2(u);
	}
}

void dfsSz(int v) {
	sz[v] = 1;
	for (int u : G[v]) {
		dfsSz(u);
		sz[v] += sz[u];
	}
}
void dfs(int v, int pp, int curSum) {
	if (v != pp) {
		addAll += sz[v];
		curSum += n - 2 * sz[v];
	}
	bstSt[pp] = max(bstSt[pp], curSum);
	for (int u : G[v])
		dfs(u, pp, curSum);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int v, u;
		scanf("%d%d", &v, &u);
		g[v].push_back(u);
		g[u].push_back(v);
		deg[v]++;
		deg[u]++;
	}
	for (int v = 0; v < n; v++)
		if (deg[v] == 1)
			q[topQ++] = v;
	for (int i = 0; i < topQ; i++) {
		int v = q[i];
		int w = -1;
		for (int u : g[v]) {
			if (deg[u] != 1) {
				if (w != -1) throw;
				w = u;
			}
		}
		G[w].push_back(v);
		deg[w]--;
		if (deg[w] == 1) q[topQ++] = w;
	}
	int v = 0;
	while(deg[v] == 1) v++;
	dfs2(v);
	for (int i = 0; i < m; i++) {
		dfsSz(cyc[i]);
		dfs(cyc[i], cyc[i], n);
	}
	for (int i = 0; i < m; i++)
		pref[i + 1] = sz[cyc[i]];
	for (int i = m + 1; i <= 2 * m; i++)
		pref[i] = pref[i - m];
	for (int i = 1; i <= 2 * m; i++)
		pref[i] += pref[i - 1];
	for (int len = 1; len < m; len++) {
		dp[0][m] = dp[0][0];
		for (int i = 0; i < m; i++) {
			dp[1][i] = max(dp[0][i], dp[0][i + 1]) + pref[i + len] - pref[i];
		}
		for (int i = 0; i < m; i++)
			dp[0][i] = dp[1][i];
	}
	int ans = -(int)1e9;
	dp[0][m] = dp[0][0];
	for (int i = 0; i < m; i++)
		ans = max(ans, dp[0][i + 1] + bstSt[cyc[i]]);
	printf("%d\n", ans + addAll);

	return 0;
}