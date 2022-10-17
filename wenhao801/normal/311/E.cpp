#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

#define ll long long
inline int read () {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}
const int MAXN = 100100, inf = 1e9;
struct Edge { int nex, to, w; } edge[MAXN << 1];
int head[MAXN], Elen = 1;
void addEdge (int u, int v, int w) {
	edge[++Elen].to = v; edge[Elen].nex = head[u];
	head[u] = Elen; edge[Elen].w = w;
	edge[++Elen].to = u; edge[Elen].nex = head[v];
	head[v] = Elen; edge[Elen].w = 0;
}
int n, m, g; bool ori[MAXN];
int V[MAXN];
int S, T;

int dis[MAXN]; int cur[MAXN];
queue <int> q;
bool bfs () {
	int i, j;
	for (i = 1; i <= T; i++) cur[i] = head[i], dis[i] = inf;
	dis[S] = 0; q.push(S);
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (i = head[x]; i; i = edge[i].nex) {
			j = edge[i].to; if (dis[j] != inf || !edge[i].w) continue;
			dis[j] = dis[x] + 1; q.push(j);
		}
	}
	return dis[T] != inf;
}
ll dfs (int x, int lim) {
	int i, j; ll ret = 0;
	if (x == T) return lim;
	for (i = cur[x]; i; i = edge[i].nex) {
		cur[x] = i; j = edge[i].to;
		if (dis[j] != dis[x] + 1 || !edge[i].w) continue;
		int tmp = dfs(j, min(edge[i].w, lim));
		edge[i].w -= tmp; edge[i ^ 1].w += tmp;
		ret += tmp; lim -= tmp;
		if (!lim) return ret;
	}
	return ret;
}

int main () {
	n = read(), m = read(), g = read();
	int i, j;
	for (i = 1; i <= n; i++) ori[i] = read();
	for (i = 1; i <= n; i++) V[i] = read();
	ll ans = 0;
	S = n + m + 1, T = n + m + 2;
	for (i = 1; i <= n; i++) {
		if (!ori[i]) addEdge(i, T, V[i]);
		else addEdge(S, i, V[i]);
	}
	for (i = 1; i <= m; i++) {
		int type = read(), W = read(), K = read();
		while (K--) {
			int k = read();
			if (type) addEdge(i + n, k, inf);
			else addEdge(k, i + n, inf);
		}
		int tg = read(); ans -= tg * g;
		if (!type) addEdge(i + n, T, W + tg * g), ans += W + tg * g;
		else addEdge(S, i + n, W + tg * g), ans += W + tg * g;
	}
	while (bfs()) ans -= dfs(S, inf);
	printf("%lld\n", ans);
	return 0;
}