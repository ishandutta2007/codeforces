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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int N = 200100;
const int LOG = 19;
vector<int> g[N];
vector<int> G[N];
int h[N];
int par[N][LOG];
int bigPar[N][LOG];
vector<pii> busForLCA[N];
vector<int> queryForLCA[N];
int query[N][2];
int ans[N];
int ans2[N];
int n, m;
pii ord[N];
int ordSz;
bool bad[N];
int col[N];
int t[N][2];
int sz[N];

int fenv[N];
int T;
void addFenv(int p) {
	for(; p <= T; p |= p + 1)
		fenv[p]++;
}
int getFenv(int r) {
	int res = 0;
	for(; r >= 0; r = (r & (r + 1)) - 1)
		res += fenv[r];
	return res;
}
int getSum(int l, int r) {
	return getFenv(r - 1) - getFenv(l - 1);
}

int up(int v, int dh) {
	for (int k = LOG - 1; k >= 0; k--) {
		if (dh < (1 << k)) continue;
		dh -= 1 << k;
		v = par[v][k];
	}
	return v;
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

void dfs(int v) {
	for (int u : G[v]) {
		h[u] = h[v] + 1;
		par[u][0] = v;
		for (int k = 0; k < LOG - 1; k++) {
			int w = par[u][k];
			if (w != -1)
				par[u][k + 1] = par[w][k];
		}
		dfs(u);
	}
}

void markBest(int v, int w) {
	if (h[bigPar[v][0]] <= h[w]) return;
	bigPar[v][0] = w;
	markBest(par[v][0], w);
}

void solveLCA(int w) {
	for (int id : queryForLCA[w]) {
		int v = query[id][0], u = query[id][1];
		if (u == w) swap(v, u);
		if (v == w) {
			int res = 0;
			for (int k = LOG - 1; k >= 0; k--) {
				if (h[bigPar[u][k]] > h[v]) {
					res += 1 << k;
					u = bigPar[u][k];
				}
			}
			res++;
			u = bigPar[u][0];
			if (h[u] > h[v]) {
				ans[id] = -1;
				query[id][0] = query[id][1] = -1;
			} else {
				ans[id] = res;
				query[id][0] = query[id][1] = -1;
			}
			continue;
		}
		int res = 0;
		for (int k = LOG - 1; k >= 0; k--) {
			if (h[bigPar[v][k]] > h[w]) {
				res += 1 << k;
				v = bigPar[v][k];
			}
			if (h[bigPar[u][k]] > h[w]) {
				res += 1 << k;
				u = bigPar[u][k];
			}
		}
		if (h[bigPar[v][0]] > h[w] || h[bigPar[u][0]] > h[w]) {
			ans[id] = -1;
			query[id][0] = query[id][1] = -1;
		} else {
			ans[id] = res + 2;
			query[id][0] = v;
			query[id][1] = u;
		}
	}
}

void dfs2(int v, int p) {
	sz[v] = 1;
	for (int u : g[v]) {
		if (u == p || bad[u]) continue;
		dfs2(u, v);
		sz[v] += sz[u];
	}
}

int findCentroid(int v) {
	dfs2(v, -1);
	int S = sz[v];
	while(true) {
		int w = v;
		for (int u : g[v]) {
			if (bad[u] || sz[u] > sz[v]) continue;
			if (2 * sz[u] >= S) {
				v = u;
			}
		}
		if (v == w) break;
	}
	return v;
}

void dfs3(int v, int p, int c) {
	col[v] = c;
	t[v][0] = T++;
	for (int u : g[v]) {
		if (bad[u] || u == p) continue;
		int nc = c;
		if (p == -1) nc = u;
		dfs3(u, v, nc);
	}
	t[v][1] = T;
}

struct Event {
	int type;
	int x;
	int y1, y2;
	int id;

	Event() : type(), x(), y1(), y2(), id() {}
	Event(int _type, int _x, int _y1, int _y2, int _id) : type(_type), x(_x), y1(_y1), y2(_y2), id(_id) {}

	bool operator < (const Event &e) const {
		if (x != e.x) return x < e.x;
		return type < e.type;
	}
};
Event ev[6 * N];
int evSz;

void doEvents() {
	sort(ev, ev + evSz);
	for (int i = 0; i <= T; i++)
		fenv[i] = 0;
	for (int i = 0; i < evSz; i++) {
		Event e = ev[i];
		if (e.type == 0) {
			addFenv(e.y1);
		} else {
			ans2[e.id] += getSum(e.y1, e.y2) * e.type;
		}
	}
}

void solveCentroid(int v, vector<pii> buses, vector<int> queries) {
	if (buses.empty() || queries.empty()) return;
	v = findCentroid(v);
	T = 0;
	bad[v] = 1;
	dfs3(v, -1, v);
	evSz = 0;
	for (pii z : buses) {
		int u = z.first, w = z.second;
		if (col[u] == col[w]) continue;
		u = t[u][0];
		w = t[w][0];
		ev[evSz++] = Event(0, u, u, u, -1);
		ev[evSz++] = Event(0, u, w, w, -1);
		ev[evSz++] = Event(0, w, u, u, -1);
		ev[evSz++] = Event(0, w, w, w, -1);
	}
	for (int id : queries) {
		int u = query[id][0], w = query[id][1];
		ev[evSz++] = Event(-1, t[u][0], t[w][0], t[w][1], id);
		ev[evSz++] = Event(1, t[u][1] - 1, t[w][0], t[w][1], id);
	}
	doEvents();
	map<int, vector<pii>> mapBuses;
	map<int, vector<int>> mapQ;
	for (pii z : buses) {
		int u = z.first, w = z.second;
		if (col[u] != col[w]) continue;
		mapBuses[col[u]].push_back(z);
	}
	for (int id : queries) {
		int u = query[id][0], w = query[id][1];
		if (col[u] != col[w]) continue;
		mapQ[col[u]].push_back(id);
	}
	for (int u : g[v]) {
		if (bad[u]) continue;
		solveCentroid(u, mapBuses[u], mapQ[u]);
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int p;
		scanf("%d", &p);
		p--;
		G[p].push_back(i);
		g[p].push_back(i);
		g[i].push_back(p);
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < LOG; j++)
			par[i][j] = -1;
	dfs(0);

	scanf("%d", &m);
	while(m--) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		int w = LCA(v, u);
		busForLCA[w].push_back(mp(v, u));
	}

	for (int i = 0; i < n; i++)
		ord[i] = mp(h[i], i);
	sort(ord, ord + n);
	for (int v = 0; v < n; v++)
		for (int k = 0; k < LOG; k++)
			bigPar[v][k] = v;
	for (int i = 0; i < n; i++) {
		int v = ord[i].second;
		for (pii t : busForLCA[v]) {
			markBest(t.first, v);
			markBest(t.second, v);
		}
	}
/*
	for (int v = 0; v < n; v++)
		cerr << bigPar[v][0] << " ";
	cerr << endl;
*/
	for (int i = 0; i < n; i++) {
		int v = ord[i].second;
		for (int k = 0; k < LOG - 1; k++)
			bigPar[v][k + 1] = bigPar[bigPar[v][k]][k];
	}

	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &query[i][0], &query[i][1]);
		query[i][0]--;
		query[i][1]--;
		int w = LCA(query[i][0], query[i][1]);
		queryForLCA[w].push_back(i);
	}

	for (int v = 0; v < n; v++)
		solveLCA(v);

	vector<pii> buses;
	vector<int> queries;
	for (int v = 0; v < n; v++)
		for (pii t : busForLCA[v])
			buses.push_back(t);
	for (int i = 0; i < m; i++) {
		if (query[i][0] == -1) continue;
		queries.push_back(i);
	}
	solveCentroid(0, buses, queries);

	for (int i = 0; i < m; i++) {
		if (ans2[i] > 0) ans[i]--;
		printf("%d\n", ans[i]);
//		printf("%d : %d %d\n", ans[i], query[i][0], query[i][1]);
	}

	return 0;
}