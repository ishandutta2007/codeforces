#include <bits/stdc++.h>
using namespace std;
const int maxn = 400010;
typedef long long LL;
int n, m, EC, st, ed, dfn, l[maxn], r[maxn], w[maxn];
LL value, c[maxn];
struct edge {
	int v; edge* next;
} ES[maxn * 2], *tot[maxn];
void add(int x, int y) {
	ES[++EC].v = y; ES[EC].next = tot[x]; tot[x] = ES + EC;
}
void dfs(int x, int fa) {
	w[l[x] = ++dfn] = x;
	for (edge* e = tot[x]; e; e = e->next)
		if (e->v != fa) dfs(e->v, x);
	r[x] = dfn;
}
struct node {
	LL tag, v;
} seg[maxn * 4];
inline void update(int tot) {
	seg[tot].v = seg[tot * 2].v | seg[tot * 2 + 1].v;
}
inline void down(int tot) {
	if (seg[tot].tag) {
		seg[tot * 2].v = seg[tot * 2].tag = seg[tot].tag;
		seg[tot * 2 + 1].v = seg[tot * 2 + 1].tag = seg[tot].tag;
		seg[tot].tag = 0;
	}
}
void build(int tot, int l, int r) {
	if (l == r) {
		seg[tot].v = c[w[l]];
		return;
	}
	int mid = (l + r) / 2;
	build(tot * 2, l, mid); build(tot * 2 + 1, mid + 1, r);
	update(tot);
}
void modify(int tot, int l, int r) {
	if (st <= l && r <= ed) {
		seg[tot].v = seg[tot].tag = value;
		return;
	}
	int mid = (l + r) / 2;
	down(tot);
	if (st <= mid) modify(tot * 2, l, mid); 
	if (mid < ed) modify(tot * 2 + 1, mid + 1, r);
	update(tot);
}
LL query(int tot, int l, int r) {
	if (st <= l && r <= ed) return seg[tot].v;
	int mid = (l + r) / 2; LL ret = 0;
	down(tot);
	if (st <= mid) ret |= query(tot * 2, l, mid);
	if (mid < ed) ret |= query(tot * 2 + 1, mid + 1, r);
	return ret;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		int type;
		scanf("%d", &type);
		c[i] = 1LL << type;
	}
	for (int i = 1; i < n; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y); add(y, x);
	}
	dfs(1, 0);
	build(1, 1, n);
	for (int i = 1; i <= m; ++i) {
		int type, x;
		scanf("%d%d", &type, &x);
		st = l[x]; ed = r[x];
		if (type == 1) {
			int c; scanf("%d", &c);
			value = 1LL << c;
			modify(1, 1, n);
		}
		else printf("%d\n", __builtin_popcountll(query(1, 1, n)));
	}
}