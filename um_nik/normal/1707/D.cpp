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


ll MOD = 998244353;
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

const int N = 2020;
int n;
ll dp[N][N];
ll C[N][N];
ll a[N];
vector<int> g[N];

void dfs(int v, int par) {
	vector<int> sons;
	for (int u : g[v]) if (u != par) {
		sons.push_back(u);
		dfs(u, v);
	}
	int k = (int)sons.size();
	vector<ll> sums(k, 0);
	vector<ll> w(k, 0);
	vector<ll> pref(k + 1, 0), suf(k + 1, 0);
	for (int x = 0; x <= n; x++) {
		dp[v][x] = 1;
		for (int i = 0; i < k; i++) {
			sums[i] = add(sums[i], dp[sons[i]][x]);
			dp[v][x] = mult(dp[v][x], sums[i]);
		}
		for (int i = 0; i < k; i++)
			dp[v][x] = add(dp[v][x], mult(w[i], dp[sons[i]][x]));
		pref[0] = 1;
		for (int i = 0; i < k; i++)
			pref[i + 1] = mult(pref[i], sums[i]);
		suf[k] = 1;
		for (int i = k - 1; i >= 0; i--) {
			suf[i] = mult(suf[i + 1], sums[i]);
		}
		for (int i = 0; i < k; i++)
			w[i] = add(w[i], mult(pref[i], suf[i + 1]));
	}
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%lld", &n, &MOD);
	for (int i = 1; i < n; i++) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	dfs(0, -1);
/*
	for (int v = 0; v < n; v++)
		for (int x = 0; x <= n; x++)
			eprintf("dp[%d][%d] = %lld\n", v, x, dp[v][x]);
*/

	for (int i = 0; i < N; i++)
		C[i][0] = C[i][i] = 1;
	for (int i = 1; i < N; i++)
		for (int j = 1; j < i; j++)
			C[i][j] = add(C[i - 1][j - 1], C[i - 1][j]);

	int k = (int)g[0].size();
	vector<ll> sums(k, 0);
	for (int x = 0; x <= n; x++) {
		a[x] = 1;
		for (int i = 0; i < k; i++)
			a[x] = mult(a[x], sums[i]);
		for (int i = 0; i < k; i++) {
			sums[i] = add(sums[i], dp[g[0][i]][x]);
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j < i; j++)
			a[i] = sub(a[i], mult(a[j], C[i][j]));
	for (int i = 1; i < n; i++)
		printf("%lld ", a[i]);
	printf("\n");

	return 0;
}