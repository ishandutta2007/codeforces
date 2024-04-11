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

const int N = 200200;
int n, m;
int a[N];
int b[N];

struct Edge {
	int v, u, w;

	Edge() : v(), u(), w() {}
	Edge(int _v, int _u, int _w) : v(_v), u(_u), w(_w) {}

	bool operator < (const Edge &e) const {
		return w > e.w;
	}
};
Edge ed[N];
int k;
int par[N];

int getPar(int v) {
	return par[v] == v ? v : par[v] = getPar(par[v]);
}
bool unite(int v, int u) {
	v = getPar(v);
	u = getPar(u);
	if (v == u) return false;
	par[u] = v;
	return true;
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &m, &n);
	for (int i = 0; i < m; i++)
		scanf("%d", &a[i]);
	for (int j = 0; j < n; j++)
		scanf("%d", &b[j]);
	ll ans = 0;
	for (int i = 0; i < m; i++) {
		int sz;
		scanf("%d", &sz);
		while(sz--) {
			int v;
			scanf("%d", &v);
			v--;
			ans += a[i] + b[v];
			ed[k++] = Edge(i, m + v, a[i] + b[v]);
		}
	}
	sort(ed, ed + k);
	n += m;
	for (int v = 0; v < n; v++) {
		par[v] = v;
	}
	for (int i = 0; i < k; i++) {
		if (unite(ed[i].v, ed[i].u))
			ans -= ed[i].w;
	}
	printf("%lld\n", ans);

	return 0;
}