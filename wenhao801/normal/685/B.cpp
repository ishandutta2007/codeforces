#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

inline int read() {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
	return ret * t;
}

const int MAXN = 300300;

int n, q, ans[MAXN]; vector <int> E[MAXN];
int dep[MAXN], siz[MAXN], dfn[MAXN], idfn[MAXN], mx[MAXN], cnt, wson[MAXN], fa[MAXN];
int top[MAXN];
void dfs (int x, int f) {
	dep[x] = dep[f] + 1, siz[x] = 1; fa[x] = f;
	for (auto i: E[x]) dfs(i, x), siz[x] += siz[i], mx[x] = max(mx[x], siz[i]), wson[x] = siz[i] > siz[wson[x]] ? i : wson[x];
}

inline int val (int x, int u) { return max(mx[u], siz[x] - siz[u]); }
void dfs2 (int x, int f) {
	dfn[x] = ++cnt, idfn[cnt] = x;
	if (!f) top[x] = x;
	if (wson[x]) {
		top[wson[x]] = top[x], dfs2(wson[x], x), ans[x] = ans[wson[x]];
		while (ans[x] != x && val(x, ans[x]) > val(x, fa[ans[x]])) ans[x] = fa[ans[x]];
	}
	else { ans[x] = x; return; }
	for (auto i: E[x]) if (i != wson[x]) dfs2(i, x);
}

int main () {
	n = read(), q = read(); int i, j;
	for (i = 2; i <= n; i++) { j = read(); E[j].emplace_back(i); }
	dfs(1, 0), dfs2(1, 0);
	while (q--) {
		int x = read();
		printf("%d\n", ans[x]);
	}
	return 0;
}