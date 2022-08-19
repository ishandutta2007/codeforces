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


const int N = 404;
int n, m;
vector<int> g[N];
int a[N][N];
int ans[N][N];
pii ord[N];

int solve(int v, int u) {
	eprintf("solve %d %d\n", v, u);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			eprintf("%d ", a[i][j]);
		eprintf("\n");
	}

	for (int i = 0; i < n; i++)
		ord[i] = mp(a[v][i] + a[u][i], i);
	sort(ord, ord + n);
	
	for (int i = 0; i < n; i++)
		eprintf("(%d %d) ", ord[i].first, ord[i].second);
	eprintf("\n");

	int p = 0;
	while(p < n && ord[p].first == a[v][u]) p++;

	if (p != a[v][u] + 1) return 0;
	int res = 1;
	for (int i = p; i < n; i++) {
		int x = ord[i].second;
		int w = 0;
		for (int y : g[x]) {
			if (a[v][x] == a[v][y] + 1 && a[u][x] == a[u][y] + 1)
				w++;
		}
		res = mult(res, w);
	}
	return res;
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = N;
	for (int i = 0; i < m; i++) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		g[v].push_back(u);
		g[u].push_back(v);
		a[v][u] = a[u][v] = 1;
	}
	for (int i = 0; i < n; i++)
		a[i][i] = 0;
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			eprintf("%d ", a[i][j]);
		eprintf("\n");
	}
	for (int v = 0; v < n; v++)
		for (int u = 0; u <= v; u++) {
			ans[v][u] = ans[u][v] = solve(v, u);
		}
	for (int v = 0; v < n; v++) {
		for (int u = 0; u < n; u++) {
			printf("%d ", ans[v][u]);
		}
		printf("\n");
	}

	return 0;
}