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

const int MAXN = 200200;
int fa[MAXN], head[MAXN], cnt = 1;
struct Edge {
	int nex, to, ori;
	bool tree; int cov;
} edge[MAXN << 1];
void add (int u, int v) {
	edge[++cnt].to = v; edge[cnt].nex = head[u];
	head[u] = cnt; edge[cnt].ori = u;
}
int n, m;
bool vis[MAXN]; int dep[MAXN];
void dfs (int x) {
	vis[x] = true;
	for (int i = head[x]; i; i = edge[i].nex) {
		int j = edge[i].to;
		if (vis[j]) continue; 
		edge[i].tree = true, fa[j] = i, dep[j] = dep[x] + 1;
		dfs(j);
	}
}

int cover (int u, int v, int k) {
	if (dep[u] < dep[v]) swap(u, v);
	while (dep[u] > dep[v]) {
		if (edge[fa[u]].cov) return edge[fa[u]].cov;
		edge[fa[u]].cov = k; u = edge[fa[u]].ori;
	}
	while (u != v) {
		if (edge[fa[u]].cov) return edge[fa[u]].cov;
		if (edge[fa[v]].cov) return edge[fa[v]].cov;
		edge[fa[u]].cov = k; u = edge[fa[u]].ori;
		edge[fa[v]].cov = k; v = edge[fa[v]].ori;
	}
	return 0;
}
vector <int> ans;
int lca (int u, int v) {
	bool f = false;
	if (dep[u] < dep[v]) swap(u, v);
	while (dep[u] > dep[v]) u = edge[fa[u]].ori;
	while (u != v) u = edge[fa[u]].ori, v = edge[fa[v]].ori;
	return u;
}
void jump (int x, int to) { while (x != to) ans.push_back(x), x = edge[fa[x]].ori; ans.push_back(x); }
void prt () { printf("%d", ans.size()); for (auto i: ans) printf(" %d", i); puts(""); ans.clear(); }

int main () {
	n = read(), m = read();
	int i, j;
	for (i = 1; i <= m; i++) {
		int u = read(), v = read();
		add(u, v); add(v, u);
	}
	for (i = 1; i <= n; i++) if (!vis[i]) dep[i] = 1, dfs(i);
	for (i = 2; i <= cnt; i += 2) if (!edge[i].tree && !edge[i ^ 1].tree) {
		j = cover(edge[i].ori, edge[i].to, i);
		if (j) {
			puts("YES");
			int u = edge[i].ori, v = edge[j].ori, x = edge[i].to, y = edge[j].to;
			if (dep[u] < dep[x]) swap(u, x); if (dep[v] < dep[y]) swap(v, y);
			if (dep[x] < dep[y]) swap(x, y), swap(u, v);
			int qwq = lca(u, v);
			jump(u, qwq); reverse(ans.begin(), ans.end()); ans.push_back(x); prt();
			jump(qwq, x); prt();
			jump(x, y); jump(v, qwq); reverse(ans.begin(), ans.end()); prt();
			return 0;
		}
	}
	puts("NO");
	return 0;
}