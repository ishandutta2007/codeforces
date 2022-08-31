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


const ll MOD = (ll)1e9 + 7;
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

const int N = 204;
int n;
vector<int> g[N];
int sz[N];
int h[N];
int par[N];
ll dp[N][N];

void dfs(int v) {
	sz[v] = 1;
	for (int u : g[v]) {
		if (h[u] != -1) continue;
		h[u] = h[v] + 1;
		par[u] = v;
		dfs(u);
		sz[v] += sz[u];
	}
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int i = 1; i < N; i++)
		dp[i][0] = 1;
	for (int i = 1; i < N; i++)
		for (int j = 1; j < N; j++) {
			dp[i][j] = add(dp[i - 1][j], dp[i][j - 1]);
			if (dp[i][j] & 1) dp[i][j] += MOD;
			dp[i][j] /= 2;
		}

	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	ll ans = 0;
	for (int v = 0; v < n; v++) {
		for (int i = 0; i < n; i++)
			h[i] = -1;
		h[v] = 0;
		dfs(v);
		for (int u = v + 1; u < n; u++) {
			ll cur = 0;
			int x = u;
			cur = add(cur, mult(dp[h[u]][0], sz[u]));
			while(par[x] != v) {
				cur = add(cur, mult(dp[(h[x] - 1)][h[u] - (h[x] - 1)], sz[par[x]] - sz[x]));
				x = par[x];
			}
			cur = mult(cur, rev(n));
			ans = add(ans, cur);
		}
	}
	printf("%lld\n", ans);

	return 0;
}