#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

inline int read () {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}

#define size(v) (int(v.size()))
const int MAXN = 101000;
int n, m, h; vector <int> E[MAXN];
int dfn[MAXN], low[MAXN], a[MAXN], top;

vector <int> s; bool vis[MAXN];
vector <int> c[MAXN]; int col[MAXN], cc = 0, d[MAXN];
void tarjan (int x) {
	dfn[x] = low[x] = ++top; vis[x] = 1; s.push_back(x);
	for (auto i: E[x]) {
		if (!dfn[i]) {
			tarjan(i); low[x] = min(low[x], low[i]);
		}
		else if (vis[i]) low[x] = min(low[x], dfn[i]);
	}
	if (dfn[x] == low[x]) {
		col[x] = ++cc; c[cc].push_back(x); vis[x] = 0;
		while (s.back() != x) col[s.back()] = cc, c[cc].push_back(s.back()), vis[s.back()] = 0, s.pop_back();
		s.pop_back();
	}
}

int main () {
	n = read(), m = read(), h = read(); int i, j;
	for (i = 1; i <= n; i++) a[i] = read();
	for (i = 1; i <= m; i++) {
		int	u = read(), v = read();
		if ((a[u] + 1) % h == a[v]) E[u].push_back(v);
		if ((a[v] + 1) % h == a[u]) E[v].push_back(u);
	}
	for (i = 1; i <= n; i++) if (!dfn[i]) tarjan(i);
	for (i = 1; i <= n; i++) for (auto j: E[i]) if (col[j] != col[i]) ++d[col[i]];
	int ans = 0;
	for (i = 1; i <= cc; i++) if (!d[i]) {
		if (!ans || (size(c[ans]) > size(c[i]))) ans = i;
	}
	printf("%d\n", size(c[ans]));
	for (auto i: c[ans]) printf("%d ", i);
	return 0;
}