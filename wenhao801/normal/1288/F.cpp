#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

inline int read() {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
	return ret * t;
}

const int MAXN = 100010, inf = 1e9;
struct Edge { int nex, to, w, f; } edge[MAXN];
int head[MAXN], cnt = 1;
void add (int u, int v, int w, int f) {
	edge[++cnt].to = v, edge[cnt].nex = head[u];
	head[u] = cnt; edge[cnt].w = w, edge[cnt].f = f;
	edge[++cnt].to = u, edge[cnt].nex = head[v];
	head[v] = cnt; edge[cnt].w = -w, edge[cnt].f = 0;
}

int dis[MAXN], pre[MAXN], N; bool vis[MAXN];
queue <int> q;
bool spfa (int s, int t) {
	int i, j;
	for (i = 1; i <= N; i++) dis[i] = inf, vis[i] = 0, pre[i] = 0;
	dis[s] = 0, vis[s] = 1; q.push(s);
	while (!q.empty()) {
		int x = q.front(); q.pop(); vis[x] = 0;
		for (i = head[x]; i; i = edge[i].nex) {
			j = edge[i].to;
			if (edge[i].f && dis[j] > dis[x] + edge[i].w) {
				dis[j] = dis[x] + edge[i].w;
				pre[j] = i ^ 1;
				if (!vis[j]) vis[j] = 1, q.push(j);
			}
		}
	}
	return dis[t] != inf;
}

#define pii pair <int, int>
#define fr first
#define se second
pii mcmf (int s, int t) {
	int flow = 0, cost = 0;
	while (spfa(s, t)) {
		int now, fl = inf;
		for (now = t; now != s; now = edge[pre[now]].to)
			fl = min(fl, edge[pre[now] ^ 1].f);
		for (now = t; now != s; now = edge[pre[now]].to)
			edge[pre[now]].f += fl, edge[pre[now] ^ 1].f -= fl, cost += fl * edge[pre[now] ^ 1].w;
		flow += fl;
	}
    return pii(flow, cost);
}

int ind[MAXN], oud[MAXN], S, T;
void exadd (int u, int v, int lb, int rb, int w) {
    add(u, v, w, rb - lb);
    oud[u] += lb, ind[v] += lb;
}

char L[202], R[202];
int nl, nr, m, r, b;

int main () {
	nl = read(), nr = read(), m = read(), r = read(), b = read();
    int s = nl + nr + 1, t = s + 1; S = t + 1, T = S + 1; N = T;
    int i, j;
    scanf("%s", L + 1); scanf("%s", R + 1);
    for (i = 1; i <= nl; i++) {
        if (L[i] == 'R') exadd(s, i, 1, inf, 0);
        if (L[i] == 'B') exadd(i, t, 1, inf, 0);
        if (L[i] == 'U') add(s, i, 0, inf), add(i, t, 0, inf);
    }
    for (i = 1; i <= nr; i++) {
        if (R[i] == 'R') exadd(i + nl, t, 1, inf, 0);
        if (R[i] == 'B') exadd(s, i + nl, 1, inf, 0);
        if (R[i] == 'U') add(s, i + nl, 0, inf), add(i + nl, t, 0, inf);
    }
    int sav = cnt;
    for (i = 1; i <= m; i++) {
        int u = read(), v = read() + nl;
        add(u, v, r, 1); add(v, u, b, 1);
    }

    add(t, s, 0, inf);
    for (i = 1, j = 0; i <= t; i++) {
        if (ind[i] - oud[i] > 0) add(S, i, 0, ind[i] - oud[i]), j += ind[i] - oud[i];
        else add(i, T, 0, oud[i] - ind[i]);
    }
    pii res = mcmf(S, T);
    if (res.fr != j) { puts("-1"); return 0; }
    printf("%d\n", res.se);
    for (i = sav; i < 4 * m + sav; i += 4) {
        if (!edge[i + 1].f) putchar('R');
        else if (!edge[i + 3].f) putchar('B');
        else putchar('U');
    }
    putchar('\n');
	return 0;
}