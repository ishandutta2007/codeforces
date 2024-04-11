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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__);fflush(stderr);
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


const ll MOD = 998244353;
ll add(ll x, ll y) {
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}
ll sub(ll x, ll y) {
	x -= y;
	if (x < 0) return x + MOD;
	return x;
}
ll mult(ll x, ll y) {
	return (x * y) % MOD;
}
ll bin_pow(ll x, ll p) {
	if (p == 0) return 1;
	if (p & 1) return mult(x, bin_pow(x, p - 1));
	return bin_pow(mult(x, x), p / 2);
}
ll rev(ll x) {
	return bin_pow(x, MOD - 2);
}

//const int N = 20;
const int N = 1505;
const int M = 2 * N;
const int K = N * N / 2;
vector<int> g[M];
vector<int> a[M];
vector<int> b[M];
int par[M];
int sz[M];
int cntEd[M];
int dp[M][N];
int ed[K][2];
int n, m;

void unite(int v, int u) {
	v = par[v];
	u = par[u];
	if (v == u) {
		cntEd[v]++;
		if (cntEd[v] == sz[v] * (sz[v] - 1) / 2) {
			for (int w : b[v]) {
				g[v].push_back(w);
			}
			b[v].clear();
			b[v].push_back(v);
		}
		return;
	}
	sz[m] = sz[v] + sz[u];
	cntEd[m] = cntEd[v] + cntEd[u] + 1;
	for (int x : a[v]) {
		a[m].push_back(x);
		par[x] = m;
	}
	for (int x : a[u]) {
		a[m].push_back(x);
		par[x] = m;
	}
	for (int x : b[v]) b[m].push_back(x);
	for (int x : b[u]) b[m].push_back(x);
	v = m;
	m++;
	if (cntEd[v] == sz[v] * (sz[v] - 1) / 2) {
		for (int w : b[v]) {
			g[v].push_back(w);
		}
		b[v].clear();
		b[v].push_back(v);
	}
}

void dfs(int v) {
	if (g[v].empty()) {
		dp[v][1] = 1;
		return;
	}
	dp[v][0] = 1;
	int cur = 0;
	for (int u : g[v]) {
		dfs(u);
		int inner[N];
		for (int i = 0; i <= cur + sz[u]; i++)
			inner[i] = 0;
		for (int i = 0; i <= cur; i++)
			for (int j = 1; j <= sz[u]; j++)
				inner[i + j] = add(inner[i + j], mult(dp[v][i], dp[u][j]));
		cur += sz[u];
		for (int i = 0; i <= cur; i++)
			dp[v][i] = inner[i];
	}
	assert(cur == sz[v]);
	dp[v][1] = add(dp[v][1], 1);
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	m = n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x;
			scanf("%d", &x);
			if (i < j) {
				ed[x][0] = i; 
				ed[x][1] = j;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		par[i] = i;
		a[i].push_back(i);
		b[i].push_back(i);
		sz[i] = 1;
		cntEd[i] = 0;
	}
	for (int x = 1; x <= n * (n - 1) / 2; x++) {
		int v = ed[x][0], u = ed[x][1];
		assert(u > 0);
		unite(v, u);
	}
	dfs(m - 1);
	for (int i = 1; i <= n; i++)
		printf("%d ", dp[m - 1][i]);
	printf("\n");

	return 0;
}