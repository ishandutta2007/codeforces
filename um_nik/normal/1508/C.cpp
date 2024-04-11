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

const int N = 200400;
const int LOG = 18;
const int S = 1001;

struct Edge {
	int v, u, w;

	Edge() : v(), u(), w() {}
	Edge(int _v, int _u, int _w) : v(_v), u(_u), w(_w) {}

	bool operator < (const Edge &e) const {
		return w < e.w;
	}

	void scan() {
		scanf("%d%d%d", &v, &u, &w);
		v--;u--;
	}
};

int n, m, k;
Edge ed[2 * N];
bool U[S][S];
int par[N];
int sz[N];
vector<pii> g[N];
int pp[N][LOG];
int h[N];
int pref[N];

int getPar(int v) {
	return par[v] == v ? v : par[v] = getPar(par[v]);
}
bool unite(int v, int u) {
	v = getPar(v);
	u = getPar(u);
	if (v == u) return false;
	if (sz[v] < sz[u]) swap(v, u);
	sz[v] += sz[u];
	par[u] = v;
	return true;
}

void dfs(int v, int p) {
	eprintf("dfs %d %d\n", v, p);
	for (pii e : g[v]) {
		int u = e.first;
		if (u == p) continue;
		h[u] = h[v] + 1;
		pref[u] = pref[v];
		if (e.second == 0) pref[u]++;
		pp[u][0] = v;
		for (int k = 0; k < LOG - 1; k++)
			pp[u][k + 1] = pp[pp[u][k]][k];
		dfs(u, v);
	}
}

int up(int v, int dh) {
	for (int k = 0; k < LOG; k++)
		if ((dh >> k) & 1)
			v = pp[v][k];
	return v;
}
int LCA(int v, int u) {
	if (h[v] > h[u]) swap(v, u);
	u = up(u, h[u] - h[v]);
	if (v == u) return v;
	for (int k = LOG - 1; k >= 0; k--)
		if (pp[v][k] != pp[u][k]) {
			v = pp[v][k];
			u = pp[u][k];
		}
	return pp[v][0];
}

void solveSmall() {
	eprintf("solveSmall\n");
	assert(n < S);
	for (int i = 0; i < m; i++)
		U[ed[i].v][ed[i].u] = U[ed[i].u][ed[i].v] = 1;
	int k = m;
	for (int v = 0; v < n; v++)
		for (int u = 0; u < v; u++) {
			if (U[v][u]) continue;
			ed[k++] = Edge(v, u, 0);
		}
	int X = 0;
	for (int i = 0; i < m; i++)
		X ^= ed[i].w;
	sort(ed, ed + k);
	for (int v = 0; v < n; v++) {
		par[v] = v;
		sz[v] = 1;
	}
	ll ans1 = 0;
	int cntZ = 0;
	for (int i = 0; i < k; i++) {
		int v = ed[i].v, u = ed[i].u;
		if (unite(v, u)) {
			if (ed[i].w == 0) cntZ++;
			ans1 += ed[i].w;
			g[v].push_back(mp(u, ed[i].w));
			g[u].push_back(mp(v, ed[i].w));
		}
	}
	if (cntZ != n * (n - 1) / 2 - m) {
		printf("%lld\n", ans1);
		return;
	}
	eprintf("here ans = %lld\n", ans1);
	ans1 += X;
	dfs(0, -1);
	for (int i = 0; i < k; i++) {
		if (ed[i].w == 0) continue;
		if (ed[i].w >= X) break;
		int v = ed[i].v, u = ed[i].u;
		int z = LCA(v, u);
		if (pref[v] + pref[u] - 2 * pref[z] > 0) {
			ans1 -= X - ed[i].w;
			printf("%lld\n", ans1);
			return;
		}
	}
	printf("%lld\n", ans1);
}

void solveBig() {
	eprintf("solveBig\n");
	for (int v = 0; v < n; v++) {
		par[v] = v;
		sz[v] = 1;
		g[v].push_back(mp(-1, -1));
		g[v].push_back(mp(n, -1));
	}
	for (int i = 0; i < m; i++) {
		int v = ed[i].v, u = ed[i].u;
		g[v].push_back(mp(u, ed[i].w));
		g[u].push_back(mp(v, ed[i].w));
	}
	for (int v = 0; v < n; v++) {
		sort(all(g[v]));
		for (int i = 0; i < (int)g[v].size() - 1; i++) {
			int l = g[v][i].first, r = g[v][i + 1].first;
			if (l + 1 >= r) continue;
			unite(v, l + 1);
			pref[l + 1]++;
			pref[r - 1]--;
		}
	}
	for (int i = 1; i <= n; i++)
		pref[i] += pref[i - 1];
	for (int i = 0; i < n - 1; i++)
		if (pref[i] > 0)
			unite(i, i + 1);
	ll ans = 0;
	sort(ed, ed + m);
	for (int i = 0; i < m; i++) {
		if (unite(ed[i].v, ed[i].u))
			ans += ed[i].w;
	}
	printf("%lld\n", ans);
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
		ed[i].scan();
	if (m + n >= (ll)n * (n - 1) / 2 - 5)
		solveSmall();
	else
		solveBig();

	return 0;
}