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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

double startTime;
double getCurrentTime() {
	return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}

const int INF = (int)1e9 + 4;
const int N = 200200;
const int LOG = 18;
int h[N];
int par[N][LOG];
int t[N];
vector<int> g[N];
vector<pii> G[N];
int n, m;
int ttm;
int sz1, sz2;
int vir[N][2];
int Q[N];
int vert[N];

struct Dist {
	int v, d, lft, id;

	Dist() : v(-1), d(INF), lft(INF), id(INF) {}
	Dist(int _v, int _d, int _lft, int _id) : v(_v), d(_d), lft(_lft), id(_id) {}

	bool operator < (const Dist &I) const {
		if (d != I.d) return d < I.d;
		if (id != I.id) return id < I.id;
		if (lft != I.lft) return lft > I.lft;
		return v < I.v;
	}
};
Dist dist[N];

void dfs(int v) {
//	eprintf("dfs %d\n", v);
	t[v] = ttm++;
	for (int u : g[v]) {
		if (h[u] != -1) continue;
		h[u] = h[v] + 1;
		par[u][0] = v;
		for (int k = 0; k < LOG - 1; k++) {
			par[u][k + 1] = par[par[u][k]][k];
		}
		dfs(u);
	}
}

int up(int v, int dh) {
	for (int k = 0; k < LOG; k++)
		if ((dh >> k) & 1)
			v = par[v][k];
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

void addEdge(int v, int u) {
	int w = abs(h[v] - h[u]);
//	eprintf("addEdge %d %d %d\n", v, u, w);
	v = vert[v];
	u = vert[u];
//	eprintf("v = %d u = %d\n", v, u);
	G[v].push_back(mp(u, w));
	G[u].push_back(mp(v, w));
}

void solve() {
//	eprintf("SOLVE\n");
	while(m > 0) {
		m--;
		G[m].clear();
	}
	scanf("%d%d", &sz1, &sz2);
	vector<pii> all;
	for (int i = 0; i < sz1; i++) {
		scanf("%d%d", &vir[i][0], &vir[i][1]);
		all.push_back(mp(t[vir[i][0]], vir[i][0]));
	}
	for (int i = 0; i < sz2; i++) {
		scanf("%d", &Q[i]);
		all.push_back(mp(t[Q[i]], Q[i]));
	}
	all.push_back(mp(t[1], 1));
	sort(all.begin(), all.end());
	all.resize(unique(all.begin(), all.end()) - all.begin());
//	for (pii z : all)
//		eprintf("(%d %d) ", z.first, z.second);
//	eprintf("\n");
	vector<int> st;
	for (pii z : all) {
//		eprintf("st:");
//		for (int x : st)
//			eprintf(" %d", x);
//		eprintf("\n");
		int v = z.second;
		vert[v] = m++;
		if (st.empty()) {
			st.push_back(v);
			continue;
		}
		int lca = LCA(v, st.back());
//		eprintf("%d %d %d\n", st.back(), v, lca);
		if (v == lca) throw;
		if (st.back() == lca) {
			st.push_back(v);
			continue;
		}
		while((int)st.size() >= 2 && h[st[(int)st.size() - 2]] >= h[lca]) {
//			eprintf("in while\n");
			int u = st.back();
			st.pop_back();
			addEdge(u, st.back());
		}
		if (st.back() != lca) {
			vert[lca] = m++;
			addEdge(st.back(), lca);
			st.pop_back();
			st.push_back(lca);
		}
		st.push_back(v);
	}
	while((int)st.size() > 1) {
		int v = st.back();
		st.pop_back();
		addEdge(v, st.back());
	}
	for (int i = 0; i < m; i++)
		dist[i] = Dist(i, INF, 0, INF);
	for (int i = 0; i < sz1; i++) {
		int v = vert[vir[i][0]];
		dist[v] = Dist(v, 0, 0, i);
	}
	set<Dist> setik;
	for (int i = 0; i < m; i++)
		setik.insert(dist[i]);
	while(!setik.empty()) {
		Dist D = *setik.begin();
		setik.erase(setik.begin());
		int v = D.v;
		int id = D.id;
		for (pii e : G[v]) {
			int u = e.first;
			int w = vir[id][1] * D.d - D.lft + e.second;
			int nd = (w + vir[id][1] - 1) / vir[id][1];
			Dist nD = Dist(u, nd, vir[id][1] * nd - w, id);
			if (nD < dist[u]) {
				setik.erase(dist[u]);
				dist[u] = nD;
				setik.insert(dist[u]);
			}
		}
	}
	for (int i = 0; i < sz2; i++) {
		int v = vert[Q[i]];
		printf("%d ", dist[v].id + 1);
	}
	printf("\n");
}

int main()
{
	startTime = (double)clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int v, u;
		scanf("%d%d", &v, &u);
		g[v].push_back(u);
		g[u].push_back(v);
	}
	for (int i = 1; i <= n; i++)
		h[i] = -1;
	h[1] = 0;
	dfs(1);

	int q;
	scanf("%d", &q);
	while(q--)
		solve();

	return 0;
}