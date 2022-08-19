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
set<pii> allEdges;
int n, m, k;
int Q[N][2];
pair<int, pii> ed[N];
pair<int, pii> ed2[N];
vector<int> a[N], b[N], aa[N];
int c1[N], c2[N];
vector<pii> g[N];
int par[N][LOG][2];
int h[N];

bool haveEdge(int v, int u) {
	assert(v != u);
	for (int x : b[v])
		for (int y : b[u])
			if (allEdges.count(mp(x, y)) == 0)
				return true;
	return false;
}
int mergeB(int v, int u) {
	v = c2[v]; u = c2[u];
	if (v == u) return -1;
	if ((int)b[v].size() < (int)b[u].size()) swap(v, u);
	for (int w : b[u]) {
		b[v].push_back(w);
		c2[w] = v;
	}
	return v;
}

void dfs(int v, int p) {
	for (pii e : g[v]) {
		int u = e.first;
		if (u == p) continue;
		h[u] = h[v] + 1;
		par[u][0][0] = v;
		par[u][0][1] = e.second;
		for (int i = 0; i < LOG - 1; i++) {
			int w = par[u][i][0];
			par[u][i + 1][0] = par[w][i][0];
			par[u][i + 1][1] = max(par[u][i][1], par[w][i][1]);
		}
		dfs(u, v);
	}
}
int up(int v, int dh) {
	for (int i = 0; i < LOG; i++)
		if ((dh >> i) & 1)
			v = par[v][i][0];
	return v;
}
int LCA(int v, int u) {
	if (h[v] > h[u]) swap(v, u);
	u = up(u, h[u] - h[v]);
	if (v == u) return v;
	for (int i = LOG - 1; i >= 0; i--) {
		if (par[v][i][0] != par[u][i][0]) {
			v = par[v][i][0];
			u = par[u][i][0];
		}
	}
	return par[v][0][0];
}
int maxUp(int v, int dh) {
	int res = 0;
	for (int i = 0; i < LOG; i++) {
		if ((dh >> i) & 1) {
			res = max(res, par[v][i][1]);
			v = par[v][i][0];
		}
	}
	return res;
}
int getMax(int v, int u) {
	int w = LCA(v, u);
	return max(maxUp(v, h[v] - h[w]), maxUp(u, h[u] - h[w]));
}

void solve() {
	//eprintf("SOLVE\n");
	scanf("%d%d", &n, &m);
	allEdges.clear();
	for (int i = 0; i < m; i++) {
		int v, u, w;
		scanf("%d%d%d", &v, &u, &w);
		Q[i][0] = v;
		Q[i][1] = u;
		allEdges.insert(mp(v, u));
		allEdges.insert(mp(u, v));
		ed[i] = mp(w, mp(v, u));
	}
	sort(ed, ed + m);
	k = 0;
	for (int v = 1; v <= n; v++) {
		a[v].clear();
		b[v].clear();
		aa[v].clear();
		c1[v] = c2[v] = v;
		a[v].push_back(v);
		b[v].push_back(v);
		aa[v].push_back(v);
	}
	for (int i = 0; i < m; i++) {
		int v = c1[ed[i].second.first], u = c1[ed[i].second.second];
		if (v == u) continue;
		if ((int)aa[v].size() > (int)aa[u].size()) swap(v, u);
		for (int w : aa[v]) {
			c1[w] = u;
			aa[u].push_back(w);
		}
		int cost = ed[i].first;
		vector<pii> toMerge;
		for (int x : a[v]) {
			int q = -1;
			for (int p = 0; p < (int)a[u].size(); p++) {
				if (!haveEdge(x, a[u][p])) continue;
				if (q == -1) {
					q = p;
					toMerge.push_back(mp(x, a[u][p]));
				} else {
					ed2[k++] = mp(cost, mp(x, a[u][p]));
					a[u][q] = mergeB(a[u][q], a[u][p]);
					assert(a[u][q] != -1);
					swap(a[u][p], a[u].back());
					a[u].pop_back();
					p--;
				}
			}
		}
		for (pii e : toMerge) {
			int v = e.first, u = e.second;
			if (mergeB(v, u) == -1) continue;
			ed2[k++] = mp(cost, mp(v, u));
		}
		vector<int> nw;
		for (int x : a[v]) nw.push_back(c2[x]);
		for (int x : a[u]) nw.push_back(c2[x]);
		sort(all(nw));
		nw.resize(unique(all(nw)) - nw.begin());
		a[u] = nw;
	}
	/*
	eprintf("k = %d\n", k);
	for (int i = 0; i < k; i++)
		eprintf("%d %d %d\n", ed2[i].first, ed2[i].second.first, ed2[i].second.second);
	*/
	assert(k == n - 1);
	for (int v = 1; v <= n; v++) {
		h[v] = -1;
		for (int i = 0; i < LOG; i++)
			par[v][i][0] = 0;
		g[v].clear();
	}
	for (int i = 0; i < k; i++) {
		int w = ed2[i].first, v = ed2[i].second.first, u = ed2[i].second.second;
		g[v].push_back(mp(u, w));
		g[u].push_back(mp(v, w));
	}
	h[1] = 0;
	dfs(1, 0);
	for (int i = 0; i < m; i++)
		printf("%d ", getMax(Q[i][0], Q[i][1]));
	printf("\n");
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while(t--) solve();

	return 0;
}