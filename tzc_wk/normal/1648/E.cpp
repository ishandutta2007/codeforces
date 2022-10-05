// Created time: 2022/5/1 14:54:43
#include <bits/stdc++.h>
using namespace std;
template<typename T1, typename T2> void chkmin(T1 &x, T2 y) {if (x > y) x = y;}
template<typename T1, typename T2> void chkmax(T1 &x, T2 y) {if (x < y) x = y;}
const int MAXN = 2e5;
const int LOG_N = 18;
int n, m, k;
int hd[MAXN + 5], val[MAXN * 2 + 5], to[MAXN * 2 + 5], nxt[MAXN * 2 + 5], ec = 0;
void adde(int u, int v, int w) {
//	printf("adde %d %d %d\n", u, v, w);
	to[++ec] = v; val[ec] = w; nxt[ec] = hd[u]; hd[u] = ec;
}
struct edge {
	int u, v, w;
	bool operator < (const edge &rhs) {
		return w < rhs.w;
	}
} e[MAXN + 5], ee[MAXN + 5], tmp[MAXN + 5];
int f[MAXN + 5];
int find(int x) {return (!f[x]) ? x : f[x] = find(f[x]);}
map<int, int> has[MAXN + 5];
pair<int, int> check(vector<int> &X, vector<int> &Y) {
	for (int x : X) for (int y : Y) if (!has[x].count(y)) return make_pair(x, y);
	return make_pair(0, 0);
}
vector<vector<int> > vec[MAXN + 5];
int siz[MAXN + 5];
void merge(int x, int y, int w) {
//	printf("merge %d %d %d\n", x, y, w);
	x = find(x); y = find(y); if (siz[x] < siz[y]) swap(x, y);
//	for (auto X : vec[x]) {for (int z : X) printf("%d ", z); printf("\n");}
//	for (auto Y : vec[y]) {for (int z : Y) printf("%d ", z); printf("\n");}
	vector<int> ad;
	for (int j = 0; j < vec[y].size(); j++) {
		vector<int> mrg;
		for (int i = 0; i < vec[x].size(); i++) {
			pair<int, int> pp = check(vec[x][i], vec[y][j]);
			if (pp.first) {
				mrg.push_back(i);
				adde(pp.first, pp.second, w);
				adde(pp.second, pp.first, w);
			}
		}
		if (mrg.empty()) ad.push_back(j);
		else {
			for (int i = 1; i < mrg.size(); i++) {
				if (vec[x][mrg[0]].size() < vec[x][mrg[i]].size())
					vec[x][mrg[0]].swap(vec[x][mrg[i]]);
				for (int z : vec[x][mrg[i]]) vec[x][mrg[0]].push_back(z);
				vec[x][mrg[i]].clear();
			}
			for (int z : vec[y][j]) vec[x][mrg[0]].push_back(z);
			for (int i = (int)(mrg.size()) - 1; i; i--)
				vec[x].erase(vec[x].begin() + mrg[i]);
		}
	}
	for (int id : ad) vec[x].push_back(vec[y][id]);
	vec[y].clear();
	f[y] = x; siz[x] += siz[y];
}
int mx[MAXN + 5][LOG_N + 2], fa[MAXN + 5][LOG_N + 2], dep[MAXN + 5];
void clear() {
	for (int i = 1; i <= n; i++) {
		hd[i] = f[i] = 0;
		memset(mx[i], 0, sizeof(mx[i]));
		vec[i].clear(); has[i].clear();
	}
	ec = k = 0;
}
void dfs(int x, int f) {
	for (int e = hd[x]; e; e = nxt[e]) {
		int y = to[e], z = val[e]; if (y == f) continue;
		dep[y] = dep[x] + 1; mx[y][0] = z; fa[y][0] = x; dfs(y, x);
	}
}
int query(int x, int y) {
	int ret = 0; if (dep[x] < dep[y]) swap(x, y);
	for (int i = LOG_N; ~i; i--) if (dep[x] - (1 << i) >= dep[y])
		chkmax(ret, mx[x][i]), x = fa[x][i];
	if (x == y) return ret;
	for (int i = LOG_N; ~i; i--) if (fa[x][i] != fa[y][i])
		chkmax(ret, mx[x][i]), chkmax(ret, mx[y][i]), x = fa[x][i], y = fa[y][i];
	chkmax(ret, mx[x][0]); chkmax(ret, mx[y][0]); return ret;
}
void solve() {
	scanf("%d%d", &n, &m); clear();
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
		has[e[i].u][e[i].v] = has[e[i].v][e[i].u] = 1;
		tmp[i] = e[i];
	}
	for (int i = 1; i <= n; i++) vec[i].push_back({i});
	sort(e + 1, e + m + 1);
	for (int i = 1; i <= m; i++) {
		int fu = find(e[i].u), fv = find(e[i].v);
		if (fu != fv) ee[++k] = e[i], f[fu] = fv;
	}
	for (int i = 1; i <= n; i++) f[i] = 0, siz[i] = 1;
	for (int i = 1; i <= k; i++) merge(ee[i].u, ee[i].v, ee[i].w);
	dfs(1, 0);
	for (int i = 1; i <= LOG_N; i++) for (int j = 1; j <= n; j++) {
		fa[j][i] = fa[fa[j][i - 1]][i - 1];
		mx[j][i] = max(mx[j][i - 1], mx[fa[j][i - 1]][i - 1]);
	}
	for (int i = 1; i <= m; i++) printf("%d%c", query(tmp[i].u, tmp[i].v), " \n"[i == m]);
}
int main() {int qu; scanf("%d", &qu); while (qu--) solve(); return 0;}