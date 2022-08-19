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

const int INF = (int)1e9;
const int N = 71;
const int M = (1 << 17) + 3;
int A, B;
vector<pii> g[N];
int compId[N];
int n, m;
int a[N][N];
int dp[N][M];
int dist[N];
bool used[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d%d%d", &n, &m, &A, &B);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = (i == j ? 0 : INF);
	while(m--) {
		int v, u, w;
		scanf("%d%d%d", &v, &u, &w);
		v--;u--;
		g[v].push_back(mp(u, w));
		g[u].push_back(mp(v, w));
		if (w == A) {
			a[v][u] = a[u][v] = 1;
		}
	}
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
	m = 0;
	for (int i = 0; i < n; i++)
		compId[i] = -1;
	for (int v = 0; v < n; v++) {
		bool ok = true;
		for (int i = 0; i < v; i++)
			ok &= a[v][i] == INF;
		if (!ok) continue;
		int sz = 0;
		for (int i = 0; i < n; i++)
			if (a[v][i] < INF)
				sz++;
		if (sz < 4) continue;
		for (int i = 0; i < n; i++)
			if (a[v][i] < INF)
				compId[i] = m;
		m++;
	}
	if (m > 17) throw;
	for (int v = 0; v < n; v++)
		for (int mask = 0; mask < (1 << m); mask++)
			dp[v][mask] = INF;
	dp[0][(compId[0] == -1 ? 0 : (1 << compId[0]))] = 0;
	for (int mask = 0; mask < (1 << m); mask++) {
		for (int v = 0; v < n; v++)
			dist[v] = dp[v][mask];
		for (int i = 0; i < n; i++)
			used[i] = false;
		for (int it = 0; it < n; it++) {
			int v = -1;
			for (int i = 0; i < n; i++) {
				if (used[i]) continue;
				if (v == -1 || dist[v] > dist[i])
					v = i;
			}
			used[v] = 1;
			if (dist[v] == INF) break;
			for (pii e : g[v]) {
				int u = e.first;
				if (used[u]) continue;
				if (dist[u] <= dist[v] + e.second) continue;
				if (e.second == B && a[v][u] < INF) continue;
				if (e.second == B && compId[u] != -1) continue;
				dist[u] = dist[v] + e.second;
			}
		}
		for (int v = 0; v < n; v++)
			dp[v][mask] = dist[v];
		for (int v = 0; v < n; v++)
			for (pii e : g[v]) {
				if (e.second != B) continue;
				int u = e.first;
				if (compId[u] == -1) continue;
				if ((mask >> compId[u]) & 1) continue;
				dp[u][mask | (1 << compId[u])] = min(dp[u][mask | (1 << compId[u])], dp[v][mask] + e.second);
			}
	}

	for (int v = 0; v < n; v++) {
		int ans = INF;
		for (int mask = 0; mask < (1 << m); mask++)
			ans = min(ans, dp[v][mask]);
		printf("%d ", ans);
	}
	printf("\n");

	return 0;
}