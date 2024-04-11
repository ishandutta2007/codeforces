#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
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
#include <bitset>
#include <array>
using namespace std;
 
#ifdef LOCAL
	#define eprintf(...) {fprintf(stderr, __VA_ARGS__);fflush(stderr);}
#else
	#define eprintf(...) 42
#endif
 
using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}
 
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
 
clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

const int N = (int)2e5 + 3;
const int S = 450;

vector<int> g[N];
vector<pii> Q[N][2];
int dp[N][S];
int ans[N];
int sz[N];

void dfs1(int u, int p) {
	for (int v : g[u]) {
		if (v == p) continue;
		dfs1(v, u);
		for (int j = 0; j < S; j++) {
			dp[u][j] += max(1, dp[v][j] - j);
		}
	}
}

int tmp[S];

void dfs2(int u, int p) {
	sz[u] = 1;
	dp[u][0] = g[u].size() - (p != 0);
	for (int i = 1; i < S; i++) {
	    tmp[i] = -1e8;
	}
	for (int v : g[u]) {
		if (v == p) continue;
		dfs2(v, u);
		for (int i = 0; i < S; i++) {
		    tmp[i] = dp[u][i];
		}
		for (int i = 0; i < min(S, sz[u]); i++) {
			for (int j = 0; j < min(sz[v], S - i - 1); j++) {
				dp[u][i + j + 1] = max(dp[u][i + j + 1], tmp[i] + dp[v][j] - 1);
			}
		}
                sz[u] += sz[v];
	}
}

bool leaf(int v) {
    return g[v].empty() || (g[v].size() == 1 && v != 1);
}

int main()
{
	startTime = clock();

	int n;
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		g[u].pb(v);
		g[v].pb(u);
	}
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		int v, k;
		scanf("%d %d", &v, &k);
		if (leaf(v)) {
		    continue;
		} else if (k < S) {
			Q[v][0].pb(mp(k, i));
		} else {
			Q[v][1].pb(mp(k, i));
		}
	}
	dfs1(1, 0);
	for (int i = 1; i <= n; i++) {
		for (auto x : Q[i][0]) {
			ans[x.se] = dp[i][x.fi];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < S; j++) {
			dp[i][j] = -1e8;
		}
	}
	dfs2(1, 0);
	for (int i = 1; i <= n; i++) {
		for (auto x : Q[i][1]) {
			for (int j = 0; j < S; j++) {
				ans[x.se] = max(ans[x.se], dp[i][j] - j * x.fi);
			}
		}
	}
	for (int i = 0; i < q; i++) {
		printf("%d\n", ans[i]);
	}

	return 0;
}