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

const int N = 300300;
vector<pii> g[N];
int a[N];
int b[N];
int c[N];
int h[N];
int par[N];
bool bad[N];
int n;
int T1, T2;

void dfs(int v) {
	T1++;
	b[v] = T1;
	for (pii e : g[v]) {
		int u = e.second;
		par[u] = v;
		h[u] = h[v] + 1;
		dfs(u);
	}
	T2++;
	c[v] = T2;
}

void dfs2(int v) {
	T2++;
	c[v] = T2;
	for (pii e : g[v]) {
		int u = e.second;
		if (bad[u]) continue;
		dfs2(u);
	}
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i < n; i++) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		g[v].push_back(mp(a[u], u));
	}
	for (int v = 0; v < n; v++)
		sort(all(g[v]));
	dfs(0);

	int X = a[0];
	if (X == 1) {
		bool ok = true;
		for (int v = 0; v < n; v++)
			ok &= a[v] == b[v];
		if (!ok) {
			printf("NO\n");
			return 0;
		}
		printf("YES\n0\n");
		for (int v = 0; v < n; v++)
			printf("%d ", a[v]);
		printf("\n");
		return 0;
	}
	int V = -1;
	for (int v = 0; v < n; v++)
		if (a[v] == X - 1)
			V = v;
	assert(V != -1);
	int H = h[V];
	bool ok = true;
	int U = V;
	for (int i = 1; i <= H; i++) {
		assert(U != 0);
		U = par[U];
		ok &= a[U] == X + H - i;
		a[U]--;
	}
	a[V] += H;
	assert(U == 0);
	for (int v = 0; v < n; v++) {
		if (a[v] < X - 1) {
			ok &= a[v] == c[v];
			bad[v] = 1;
		}
	}
	if (!ok) {
		printf("NO\n");
		return 0;
	}
	T2 = X - 2;
	dfs2(0);
	for (int v = 0; v < n; v++) {
		ok &= a[v] == c[v];
	}
	if (!ok) {
		printf("NO\n");
		return 0;
	}
	ll ans = H;
	for (int v = 0; v < n; v++) {
		if (a[v] < X - 1)
			ans += h[v];
	}
	printf("YES\n%lld\n", ans);
	for (int i = 0; i < n; i++)
		printf("%d ", b[i]);
	printf("\n");

	return 0;
}