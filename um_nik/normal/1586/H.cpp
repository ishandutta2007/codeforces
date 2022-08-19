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

const int N = 200200;
const int LOG = 18;
int n;
vector<pii> g[N];
int par[N][LOG];
int mx[N][LOG];
int h[N];
int m, q;
int ANS[N][2];
int p[2 * N];
int sz[2 * N];
int bstVal[2 * N];
int bstCnt[2 * N];
int sons[2 * N][2];
vector<pii> Q[2 * N];
int st[N][2];
int stSz;

pair<int, pii> ev[2 * N];
int evSz;

void dfs1(int v, int pp) {
	for (pii e : g[v]) {
		int u = e.first;
		if (u == pp) continue;
		h[u] = h[v] + 1;
		par[u][0] = v;
		mx[u][0] = e.second;
		for (int k = 0; k < LOG - 1; k++) {
			par[u][k + 1] = par[par[u][k]][k];
			mx[u][k + 1] = max(mx[u][k], mx[par[u][k]][k]);
		}
		dfs1(u, v);
	}
}

int getPar(int v) {
	return (p[v] == v ? v : p[v] = getPar(p[v]));
}
void unite(int v, int u) {
	eprintf("unite %d %d\n", v, u);
	v = getPar(v);
	u = getPar(u);
	eprintf("pars: %d %d\n", v, u);
	assert(v != u);
	int w = m++;
	p[v] = p[u] = p[w] = w;
	sz[w] = sz[v] + sz[u];
	if (bstVal[v] < bstVal[u]) swap(v, u);
	bstVal[w] = bstVal[v];
	bstCnt[w] = bstCnt[v];
	if (bstVal[v] == bstVal[u]) {
		bstCnt[w] += bstCnt[u];
		if (bstCnt[v] < bstCnt[u]) swap(v, u);
	}
	sons[w][0] = v;
	sons[w][1] = u;
}

int up(int v, int dh) {
	for (int k = 0; k < LOG; k++)
		if ((dh >> k) & 1)
			v = par[v][k];
	return v;
}
int getMaxUp(int v, int dh) {
	int res = 0;
	for (int k = 0; k < LOG; k++)
		if ((dh >> k) & 1) {
			res = max(res, mx[v][k]);
			v = par[v][k];
		}
	return res;
}
int LCA(int v, int u) {
	if (h[v] > h[u]) swap(v, u);
	u = up(u, h[u] - h[v]);
	if (v == u) return v;
	for (int k = LOG - 1; k >= 0; k--) {
		if (par[v][k] != par[u][k]) {
			v = par[v][k];
			u = par[u][k];
		}
	}
	return par[v][0];
}
int getMaxOnPath(int v, int u) {
	int w = LCA(v, u);
	return max(getMaxUp(v, h[v] - h[w]), getMaxUp(u, h[u] - h[w]));
}

void addOne(int v) {
	if (stSz == 0) {
		st[0][0] = v;
		st[0][1] = 0;
		stSz++;
	} else {
		st[stSz][0] = v;
		st[stSz][1] = max(st[stSz - 1][1], getMaxOnPath(st[0][0], v));
		stSz++;
	}
}
void dfsAdd(int v) {
	if (v <= n) {
		addOne(v);
		return;
	}
	for (int i = 0; i < 2; i++) {
		int u = sons[v][i];
		if (bstVal[v] == bstVal[u])
			dfsAdd(u);
	}
}
void dfs2(int v) {
	eprintf("dfs2 %d\n", v);
	if (v <= n) {
		addOne(v);
	} else {
		int oldSz = stSz;
		dfs2(sons[v][1]);
		stSz = oldSz;
		dfs2(sons[v][0]);
		if (bstCnt[v] > bstCnt[sons[v][0]])
			dfsAdd(sons[v][1]);
	}
	for (pii QQ : Q[v]) {
		addOne(QQ.first);
		ANS[QQ.second][1] = st[stSz - 1][1];
		stSz--;
	}
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &q);
	m = n + 1;
	for (int i = 1; i <= n; i++) {
		p[i] = i;
		sz[i] = 1;
		scanf("%d", &bstVal[i]);
		bstCnt[i] = 1;
	}
	for (int i = 1; i < n; i++) {
		int v, u, w, t;
		scanf("%d%d%d%d", &v, &u, &w, &t);
		ev[evSz++] = mp(w, mp(v, u));
		g[v].push_back(mp(u, t));
		g[u].push_back(mp(v, t));
	}
	dfs1(1, -1);
	eprintf("after dfs1\n");
	for (int i = 0; i < q; i++) {
		int x, v;
		scanf("%d%d", &x, &v);
		ev[evSz++] = mp(x, mp(-v, i));
	}
	sort(ev, ev + evSz);
	reverse(ev, ev + evSz);
	for (int i = 0; i < evSz; i++) {
		eprintf("event %d %d\n", ev[i].second.first, ev[i].second.second);
		int v = ev[i].second.first;
		if (v < 0) {
			v *= -1;
			int id = ev[i].second.second;
			int u = getPar(v);
			ANS[id][0] = bstVal[u];
			Q[u].push_back(mp(v, id));
		} else {
			int u = ev[i].second.second;
			unite(v, u);
		}
	}
	dfs2(getPar(1));
	for (int i = 0; i < q; i++)
		printf("%d %d\n", ANS[i][0], ANS[i][1]);
	return 0;
}