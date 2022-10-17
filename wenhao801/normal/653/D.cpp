#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

#define ld long double
#define ll long long
const int MAXN = 1010;
const ll inf = 1e18;
const ld eps = 1e-12;
struct Edge {
    int nex, to; ll w;
} edge[MAXN << 1];
int head[MAXN], cur[MAXN], cnt = 1;

int n, m, s, t;
void add (int u, int v, ll w) {
    edge[++cnt].nex = head[u]; head[u] = cnt;
    edge[cnt].to = v; edge[cnt].w = w;
    edge[++cnt].nex = head[v]; head[v] = cnt;
    edge[cnt].to = u; edge[cnt].w = 0;
}

ll dis[MAXN]; queue <int> q;
bool bfs () {
	int i, j;
	for (i = 1; i <= s; i++) dis[i] = inf, cur[i] = head[i];
	dis[s] = 0; q.push(s);
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (i = head[x]; i; i = edge[i].nex) {
			j = edge[i].to; if (dis[j] != inf || !edge[i].w) continue;
			dis[j] = dis[x] + 1;
			q.push(j);
		}
	}
	return dis[t] != inf;
}
ll dfs (int x, ll lim) {
	if (x == t) return lim;
	ll ret = 0, i, j;
	for (i = cur[x]; i; i = edge[i].nex) {
		cur[x] = i; j = edge[i].to;
		if (dis[j] != dis[x] + 1 || !edge[i].w) continue;
		ll tmp = dfs(j, min(lim, edge[i].w));
		ret += tmp; lim -= tmp;
		edge[i].w -= tmp, edge[i ^ 1].w += tmp;
		if (!lim) return ret;
	} 
	return ret;
}
int X;
ll dinic () { ll ret = 0; while (bfs()) ret += dfs(s, inf); return ret; }
void clear () {
    int i, j;
    for (i = 1; i <= cnt; i++) edge[i].to = edge[i].nex = edge[i].w = 0;
    for (i = 1; i <= s; i++) head[i] = 0;
    cnt = 1;
}


struct sav { int u, v, w; } ee[505];
bool check (ld d) {
    clear();
    for (int i = 1; i <= m; i++) add(ee[i].u, ee[i].v, 1ll * ee[i].w / d);
    add(s, 1, X);
    return dinic() == X;
}

int main () {
    n = read(), m = read(), X = read();
    s = n + 1, t = n;
    ld L = 0, R = 1e6 + 5, res = 0;
    for (int i = 1; i <= m; i++) ee[i].u = read(), ee[i].v = read(), ee[i].w = read();
    // cout << check(0.5) << endl;
    while (R - L > eps) {
        ld mid = (L + R) / 2;
        if (check(mid)) L = mid + eps, res = mid;
        else R = mid - eps;
    }
    printf("%.6Lf\n", res * X);
    return 0;
}