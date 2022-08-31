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


const int N = 500500;
int ans[N];
int ansSz;
int par[N];
int sz[N];
bool a[N];
int n;

int getPar(int v) {
	return par[v] == v ? v : par[v] = getPar(par[v]);
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int m;
	scanf("%d%d", &m, &n);
	for (int i = 0; i < n; i++) {
		par[i] = i;
		sz[i] = 1;
		a[i] = 0;
	}
	for (int i = 0; i < m; i++) {
		int k;
		scanf("%d", &k);
		if (k == 1) {
			int v;
			scanf("%d", &v);
			v--;
			v = getPar(v);
			if (a[v]) continue;
			a[v] = 1;
			ans[ansSz++] = i + 1;
		} else if (k == 2) {
			int v, u;
			scanf("%d%d", &v, &u);
			v--;u--;
			v = getPar(v);
			u = getPar(u);
			if (v == u || (a[v] && a[u])) continue;
			if (sz[v] < sz[u]) swap(v, u);
			par[u] = v;
			a[v] |= a[u];
			sz[v] += sz[u];
			ans[ansSz++] = i + 1;
		} else throw;
	}
	ll c = 1;
	for (int i = 0; i < ansSz; i++)
		c = add(c, c);
	printf("%lld %d\n", c, ansSz);
	for (int i = 0; i < ansSz; i++)
		printf("%d ", ans[i]);
	printf("\n");

	return 0;
}