#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>

using namespace std;

inline int read () {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}

const int MAXN = 200200, inf = 1e9 + 7;
int n, m, q, a[MAXN];

vector <int> E[MAXN], T[MAXN];

int dfn[MAXN], low[MAXN], cnt;
int stk[MAXN], stop;
int col[MAXN], ccnt;

void ins_BCC (int x, int to) { col[x] = to; T[x].push_back(n + to); T[n + to].push_back(x); }
void tarjan (int x) {
	dfn[x] = low[x] = ++cnt; stk[++stop] = x;
	for (auto i: E[x]) {
		if (!dfn[i]) {
			tarjan(i), low[x] = min(low[x], low[i]);
			if (low[i] >= dfn[x]) {
				++ccnt; ins_BCC(i, ccnt);
				while (stk[stop] != i) ins_BCC(stk[stop], ccnt), --stop;
				--stop; ins_BCC(x, ccnt);
			}
		}
		else low[x] = min(low[x], dfn[i]);
	}
}

int fa[MAXN], dep[MAXN], wson[MAXN], siz[MAXN]; multiset <int> s[MAXN];
void dfs1 (int x, int f) {
	dep[x] = dep[f] + 1, fa[x] = f, siz[x] = 1;
	if (x > n) a[x] = inf;
	for (auto i: T[x]) if (i != f) {
		dfs1(i, x); siz[x] += siz[i]; if (siz[wson[x]] < siz[i]) wson[x] = i;
		if (x > n) s[x - n].insert(a[i]), a[x] = min(a[x], a[i]);
	}
}
int top[MAXN], idfn[MAXN];
void dfs2 (int x, int f) {
	dfn[x] = ++cnt; idfn[cnt] = x;
	if (wson[x]) top[wson[x]] = top[x], dfs2(wson[x], x);
	for (auto i: T[x]) if (i != f && i != wson[x]) top[i] = i, dfs2(i, x);
}

namespace seg {
	int t[MAXN << 2];
	void pushup (int x) { t[x] = min(t[x << 1], t[x << 1 | 1]); }
	void build (int l, int r, int x) {
		if (l == r) { t[x] = a[idfn[l]]; return; }
		int mid = (l + r) >> 1;
		build(l, mid, x << 1); build(mid + 1, r, x << 1 | 1);
		pushup(x);
	}
	int query (int l, int r, int L, int R, int x) {
		if (l <= L && R <= r) return t[x];
		int mid = (L + R) >> 1, ret = inf;
		if (l <= mid) ret = min(ret, query(l, r, L, mid, x << 1));
		if (mid < r) ret = min(ret, query(l, r, mid + 1, R, x << 1 | 1));
		return ret;
	}
	void modify (int pos, int k, int l, int r, int x) {
		if (l == r) { t[x] = k; return; }
		int mid = (l + r) >> 1;
		if (pos <= mid) modify(pos, k, l, mid, x << 1);
		else modify(pos, k, mid + 1, r, x << 1 | 1);
		pushup(x);
	}
}

pair <int, int> pquery (int u, int v) {
	int ret = inf;
	while (top[u] != top[v]) {
		if (dep[top[u]] < dep[top[v]]) swap(u, v);
		ret = min(ret, seg::query(dfn[top[u]], dfn[u], 1, n + ccnt, 1));
		u = fa[top[u]];
	}
	if (dep[u] > dep[v]) swap(u, v);
	ret = min(ret, seg::query(dfn[u], dfn[v], 1, n + ccnt, 1));
	return make_pair(ret, u);
}

int main () {
	n = read(), m = read(), q = read(); int i, j;
	for (i = 1; i <= n; i++) a[i] = read();
	for (i = 1; i <= m; i++) {
		int u = read(), v = read();
		E[u].push_back(v), E[v].push_back(u);
	}
	tarjan(1); dfs1(1, 0); top[1] = 1, cnt = 0;
	for (i = 1; i <= n + ccnt; i++) dfn[i] = 0;
	dfs2(1, 0);
	seg::build(1, n + ccnt, 1);
	while (q--) {
		char str[2]; scanf("%s", str);
		if (str[0] == 'C') {
			int x = read(), w = read();
			seg::modify(dfn[x], w, 1, n + ccnt, 1);
			if (fa[x] > n) {
				s[fa[x] - n].erase(s[fa[x] - n].find(a[x]));
				s[fa[x] - n].insert(w);
				a[fa[x]] = *(s[fa[x] - n].begin());
				seg::modify(dfn[fa[x]], a[fa[x]], 1, n + ccnt, 1);
			}
			a[x] = w;
		}
		else {
			int u = read(), v = read();
			pair <int, int> res = pquery(u, v); int ans = res.first;
			if (res.second > n) ans = min(ans, a[fa[res.second]]);
			printf("%d\n", ans);
		}
	}
	return 0;
}