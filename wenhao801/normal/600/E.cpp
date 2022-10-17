#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define int long long

inline int read () {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}

const int MAXN = 100100;

struct node {
	int lson, rson;
	int ans;
	int appear;
} tree[MAXN << 5] = {};
int cnt = 0;

int rt[MAXN] = {};
int col[MAXN] = {};

int n;

struct Edge {
	int nex;
	int to;
} edge[MAXN << 1] = {};
int head[MAXN], tot = 0;

void add (int u, int v) {
	edge[++tot].to = v;
	edge[tot].nex = head[u];
	head[u] = tot;
}

void pushup (int x) {
	if (tree[tree[x].lson].appear > tree[tree[x].rson].appear) {
		tree[x].appear = tree[tree[x].lson].appear;
		tree[x].ans = tree[tree[x].lson].ans;
	}
	else if (tree[tree[x].lson].appear < tree[tree[x].rson].appear) {
		tree[x].appear = tree[tree[x].rson].appear;
		tree[x].ans = tree[tree[x].rson].ans;
	}
	else {
		tree[x].appear = tree[tree[x].lson].appear;
		tree[x].ans = tree[tree[x].lson].ans + tree[tree[x].rson].ans;
	}
}

int merge (int x, int y, int l, int r) {
	if (!x) return y;
	if (!y) return x;
	if (l == r) {
		tree[x].ans = l;
		tree[x].appear += tree[y].appear;
		return x;
	}
	int mid = (l + r) >> 1;
	tree[x].lson = merge(tree[x].lson, tree[y].lson, l, mid);
	tree[x].rson = merge(tree[x].rson, tree[y].rson, mid + 1, r);
	pushup(x);
	return x;
}

int ans[MAXN] = {};

void update (int &root, int to, int l, int r) {
	if (!root) root = ++cnt;
	if (l == r) {
		tree[root].appear++;
		tree[root].ans = l;
		return;
	}
	int mid = (l + r) >> 1;
	if (to <= mid) update(tree[root].lson, to, l, mid);
	else update(tree[root].rson, to, mid + 1, r);
	pushup(root);
}

void dfs (int x, int f) {
	int i, j;
	for (i = head[x]; i; i = edge[i].nex) {
		j = edge[i].to;
		if (j == f) continue;
		dfs(j, x);
		merge(rt[x], rt[j], 1, 100000);
	}
	update(rt[x], col[x], 1, 100000);
	ans[x] = tree[rt[x]].ans;
}

signed main () {
	n = read();
	int i, j;
	for (i = 1; i <= n; i++) col[i] = read(), rt[i] = i, cnt = n;
	for (i = 1; i < n; i++) { int u = read(), v = read(); add(u, v), add(v, u); }
	dfs(1, 0);
	for (i = 1; i <= n; i++) printf("%lld ", ans[i]);
	return 0;
}