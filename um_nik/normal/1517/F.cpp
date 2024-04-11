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


const int N = 333;
int n;
ll dp[N][2][N];
int sz[N];
vector<int> g[N];
int k;
ll ANS[N];

void myMerge(int f1, int s1, int f2, int s2, int &f, int &s) {
	if (f1 > f2) {
		swap(f1, f2);
		swap(s1, s2);
	}
	if (f1 == 0 && f2 == 0) {
		f = 0;
		s = max(s1, s2);
	} else if (f1 == 0 && f2 == 1) {
		if (s1 + s2 <= k) {
			f = 1;
			s = s2;
		} else {
			f = 0;
			s = s1;
		}
	} else if (f1 == 1 && f2 == 1) {
		f = 1;
		s = min(s1, s2);
	} else throw;
	if (f == 1 && s > k) {
		f = 0;
		s = 0;
	}
	if (f == 0 && s > k) f = -1;
}

void dfs(int v) {
	sz[v] = 1;
	dp[v][0][0] = dp[v][1][0] = 1;
	ll inner[2][N];
	for (int u : g[v]) {
		if (sz[u]) continue;
		dfs(u);
		for (int f = 0; f < 2; f++)
			for (int i = 0; i < sz[v] + sz[u]; i++)
				inner[f][i] = 0;
		for (int f1 = 0; f1 < 2; f1++)
			for (int s1 = 0; s1 < sz[v]; s1++)
				for (int f2 = 0; f2 < 2; f2++)
					for (int s2 = 0; s2 < sz[u]; s2++) {
						int f, s;
						myMerge(f1, s1, f2, s2 + 1, f, s);
						if (f == -1) continue;
						inner[f][s] = add(inner[f][s], mult(dp[v][f1][s1], dp[u][f2][s2]));
					}
		sz[v] += sz[u];
		for (int f = 0; f < 2; f++)
			for (int i = 0; i < sz[v]; i++)
				dp[v][f][i] = inner[f][i];
	}
}

ll solve() {
	for (int v = 0; v < n; v++) {
		sz[v] = 0;
		for (int f = 0; f < 2; f++)
			for (int i = 0; i <= n; i++)
				dp[v][f][i] = 0;
	}
	dfs(0);
	ll res = 0;
	for (int i = 0; i <= k; i++)
		res = add(res, dp[0][1][i]);
	return res;
}

int main()
{
	startTime = clock();
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
	for (k = 0; k <= n; k++)
		ANS[k] = solve();
	for (int k = 0; k <= n; k++)
		eprintf("ans[%d] = %lld\n", k, ANS[k]);
	assert(ANS[0] == 1);
	ll ans = sub(n, 1);
	for (int k = 0; k < n; k++)
		ans = add(ans, mult(k, sub(ANS[k + 1], ANS[k])));
	for (int i = 0; i < n; i++) {
		if (ans & 1) ans += MOD;
		ans /= 2;
	}
	printf("%lld\n", ans);

	return 0;
}