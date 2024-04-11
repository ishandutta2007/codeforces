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
#include <queue>
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = (int)1e9;
const int N = (int)1e5 + 2;
const int M = (int)1e6 + 3;
//const int N = 1000;
const int LOG = 17;
int n, m;
int ed[M][3];
pii ord[M];
bool tk[M];
vector<int> g[N];
int par[N][LOG][3];
int pp[N];
int sz[N];
int h[N];
int ans[M];

int getPar(int v) {
	return pp[v] == -1 ? v : pp[v] = getPar(pp[v]);
}
bool unite(int v, int u) {
	v = getPar(v);
	u = getPar(u);
	if (v == u) return false;
	if (sz[v] < sz[u]) swap(v, u);
	sz[v] += sz[u];
	pp[u] = v;
	return true;
}

void dfs(int v) {
	for (int id : g[v]) {
		int u = ed[id][0] ^ ed[id][1] ^ v;
		if (h[u] != -1) continue;
		h[u] = h[v] + 1;
		par[u][0][0] = v;
		par[u][0][1] = ed[id][2];
		for (int k = 0; k < LOG - 1; k++) {
			int w = par[u][k][0];
			if (w == -1) break;
			par[u][k + 1][0] = par[w][k][0];
			par[u][k + 1][1] = max(par[u][k][1], par[w][k][1]);
		}
		dfs(u);
	}
}

int up(int v, int dh) {
	for (int k = 0; k < LOG; k++) {
		if (((dh >> k) & 1) == 0) continue;
		v = par[v][k][0];
	}
	return v;
}
int getMaxOnPath(int v, int dh) {
	int res = 0;
	for (int k = 0; k < LOG; k++) {
		if (((dh >> k) & 1) == 0) continue;
		res = max(res, par[v][k][1]);
		v = par[v][k][0];
	}
	return res;
}
void setMinOnPath(int v, int dh, int x) {
	for (int k = 0; k < LOG; k++) {
		if (((dh >> k) & 1) == 0) continue;
		par[v][k][2] = min(par[v][k][2], x);
		v = par[v][k][0];
	}
}
int LCA(int v, int u) {
	if (h[v] > h[u]) swap(v, u);
	u = up(u, h[u] - h[v]);
	if (v == u) return v;
	for (int k = LOG - 1; k >= 0; k--) {
		if (par[v][k][0] != par[u][k][0]) {
			v = par[v][k][0];
			u = par[u][k][0];
		}
	}
	return par[v][0][0];
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &ed[i][j]);
		}
		ed[i][0]--;
		ed[i][1]--;
		ord[i] = mp(ed[i][2], i);
	}
	for (int i = 0; i < n; i++) {
		sz[i] = 1;
		pp[i] = -1;
	}
	sort(ord, ord + m);
	for (int i = 0; i < m; i++) {
		int id = ord[i].second;
		if (unite(ed[id][0], ed[id][1])) {
//			eprintf("take %d\n", id);
			tk[id] = 1;
			g[ed[id][0]].push_back(id);
			g[ed[id][1]].push_back(id);
		}
	}
	for (int v = 0; v < n; v++) {
		h[v] = -1;
		for (int k = 0; k < LOG; k++) {
			par[v][k][0] = -1;
			par[v][k][1] = 0;
			par[v][k][2] = INF;
		}
	}
	h[0] = 0;
	dfs(0);
/*
	for (int v = 0; v < n; v++) {
		eprintf("v = %d\n", v);
		eprintf("h = %d\n", h[v]);
		for (int k = 0; k < 2; k++) {
			eprintf("%d %d\n", par[v][k][0], par[v][k][1]);
		}
	}
*/
	for (int i = 0; i < m; i++) {
		if (tk[i]) continue;
		int v = ed[i][0], u = ed[i][1];
		int w = LCA(v, u);
		ans[i] = max(getMaxOnPath(v, h[v] - h[w]), getMaxOnPath(u, h[u] - h[w]));
		setMinOnPath(v, h[v] - h[w], ed[i][2]);
		setMinOnPath(u, h[u] - h[w], ed[i][2]);
	}
	for (int k = LOG - 1; k > 0; k--) {
		for (int v = 0; v < n; v++) {
			par[v][k - 1][2] = min(par[v][k - 1][2], par[v][k][2]);
			int u = par[v][k - 1][0];
			if (u != -1)
				par[u][k - 1][2] = min(par[u][k - 1][2], par[v][k][2]);
		}
	}
	for (int i = 0; i < m; i++) {
		if (!tk[i]) continue;
		int v = ed[i][0], u = ed[i][1];
		if (h[u] > h[v]) swap(v, u);
		ans[i] = par[v][0][2];
	}
	
	
	for (int i = 0; i < m; i++)
		if (!tk[i])
			printf("%d\n", ans[i]);
//	printf("%d\n", ans[0]);

	return 0;
}