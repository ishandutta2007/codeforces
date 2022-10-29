#include <bits/stdc++.h>
using namespace std;
const int maxn = 300010;
typedef pair<int, bool> pii;
struct edge {
	int v, w; edge* next, *op;
	bool bridge;
} ES[maxn * 2], *tot[maxn];
int n, m, st, ed, stamp, bcc_cnt, EC, dfn[maxn], low[maxn], bccno[maxn];
bool in[maxn];
vector<pii> G[maxn];
void add(int u, int v, int w) {
	ES[++EC].v = v; ES[EC].w = w; ES[EC].next = tot[u]; ES[EC].op = ES + EC + 1; tot[u] = ES + EC;
	ES[++EC].v = u; ES[EC].w = w; ES[EC].next = tot[v]; ES[EC].op = ES + EC - 1; tot[v] = ES + EC;
}
void tarjan(int u, int f) {
	dfn[u] = low[u] = ++stamp;
	for (edge* e = tot[u]; e; e = e->next) {
		int v = e->v;
		if (!dfn[v]) {
			tarjan(v, u);
			low[u] = min(low[u], low[v]);
			if (low[v] > dfn[u]) e->bridge = e->op->bridge = true;
		}
		else if (v != f) low[u] = min(low[u], dfn[v]);
	}
}
void dfs(int x) {
	dfn[x] = 1;
	bccno[x] = bcc_cnt;
	for (edge* e = tot[x]; e; e = e->next) {
		if (e->bridge) continue;
		if (!dfn[e->v]) dfs(e->v);
	}
}
bool go(int x, bool vis) {
	if (x == ed) return vis;
	dfn[x] = 1;
	for (unsigned int i = 0; i < G[x].size(); ++i) {
		int v = G[x][i].first;
		if (!dfn[v]) {
			if (go(v, vis || in[v] || G[x][i].second)) return true;
		}
	}
	return false;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		add(u, v, w);
	}
	scanf("%d%d", &st, &ed);
	tarjan(1, 0);
	memset(dfn, 0, sizeof dfn);
	for (int i = 1; i <= n; ++i)
		if (!dfn[i]) {
			bcc_cnt++;
			dfs(i);
		}
	for (int u = 1; u <= n; ++u)
		for (edge* e = tot[u]; e; e = e->next) {
			if (e->w && bccno[e->v] == bccno[u])
				in[bccno[u]] = true;
			if (e->bridge) G[bccno[u]].push_back(pii(bccno[e->v], e->w));
		}
	memset(dfn, 0, sizeof dfn);
	st = bccno[st]; ed = bccno[ed];
	if (go(st, in[st])) printf("YES\n");
	else printf("NO\n");
}