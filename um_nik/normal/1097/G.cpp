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

const ll MOD = (ll)1e9 + 7;
int add(int x, int y) {
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}
int sub(int x, int y) {
	x -= y;
	if (x < 0) return x + MOD;
	return x;
}
int mult(int x, int y) {
	return ((ll)x * y) % MOD;
}

const int N = 100010;
const int K = 207;
int rp2[N];
int n, k;
vector<int> g[N];
vector<int> sons[N];
int dp[N][K];
int inner[N][K];
int sum_one[N][K];
int sz[N];
int ans[K];
int c[K];
int C[K][K];

void dfs(int v) {
	sz[v] = 1;
	dp[v][0] = 1;
	for (int u : g[v]) {
		if (sz[u]) continue;
		sons[v].push_back(u);
		dfs(u);
		for (int i = 0; i <= sz[v] + sz[u] && i <= k; i++)
			inner[v][i] = 0;
		for (int x = 0; x <= sz[v] && x <= k; x++)
			for (int y = 0; y <= sz[u] && x + y <= k; y++)
				inner[v][x + y] = add(inner[v][x + y], mult(dp[v][x], dp[u][y]));
		sz[v] += sz[u];
		for (int i = 0; i <= sz[v] && i <= k; i++)
			dp[v][i] = inner[v][i];
	}
	for (int i = 0; i <= sz[v] && i <= k; i++)
		sum_one[v][i] = 0;
	for (int u : sons[v]) {
		for (int i = 0; i <= sz[u] && i <= k; i++)
			sum_one[v][i] = add(sum_one[v][i], dp[u][i]);
	}
	for (int i = 2; i <= sz[v] && i <= k; i++)
		ans[i] = add(ans[i], sub(dp[v][i], sum_one[v][i]));
	if (v == 0) return;
	int Q = sub(1, rp2[n - sz[v]]);
	for (int i = min(sz[v], k); i >= 2; i--) {
		ans[i] = add(ans[i], mult(Q, dp[v][i - 1]));
		dp[v][i] = add(dp[v][i], dp[v][i - 1]);
	}
	ans[1] = add(ans[1], mult(Q, sub(1, rp2[sz[v]])));
	dp[v][1] = add(dp[v][1], sub(1, rp2[sz[v]]));
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	rp2[0] = 1;
	for (int i = 1; i < N; i++) {
		rp2[i] = rp2[i - 1];
		if (rp2[i] & 1) rp2[i] += MOD;
		rp2[i] >>= 1;
	}

	scanf("%d%d", &n, &k);
	for (int i = 1; i < n; i++) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	dfs(0);

	for (int i = 0; i < K; i++)
		C[i][0] = C[i][i] = 1;
	for (int i = 1; i < K; i++)
		for (int j = 1; j < i; j++)
			C[i][j] = add(C[i - 1][j], C[i - 1][j - 1]);
	c[1] = 1;
	for (int i = 2; i < K; i++) {
		c[i] = 1;
		for (int j = 0; j < k; j++)
			c[i] = mult(c[i], i);
		for (int j = 1; j < i; j++)
			c[i] = sub(c[i], mult(C[i][j], c[j]));
	}

	ll res = 0;
	for (int i = 1; i <= k; i++)
		res = add(res, mult(ans[i], c[i]));
	for (int i = 0; i < n; i++)
		res = add(res, res);
	printf("%lld\n", res);

	return 0;
}