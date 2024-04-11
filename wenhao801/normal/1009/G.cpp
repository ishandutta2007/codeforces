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

const int MAXN = 100100;
char a[MAXN], ans[MAXN]; int s[MAXN], n;

int E[64][6], st[6], ed[64];
namespace flow {
    const int inf = 1e9 + 7;
    struct Edge { int nex, to, w; } edge[MAXN];
    int head[MAXN], cur[MAXN], S, T, cnt = 1;
    void add (int u, int v, int w) {
        edge[++cnt].to = v; edge[cnt].nex = head[u];
        head[u] = cnt; edge[cnt].w = w;
        edge[++cnt].to = u; edge[cnt].nex = head[v];
        head[v] = cnt; edge[cnt].w = 0;
    }

    queue <int> q; int dis[MAXN];
    bool bfs () {
        int i, j;
        for (i = 1; i <= T; i++) cur[i] = head[i], dis[i] = -1;
        dis[S] = 0; q.push(S);
        while (!q.empty()) {
            int x = q.front(); q.pop();
            for (i = head[x]; i; i = edge[i].nex) if (edge[i].w && dis[edge[i].to] == -1)
                dis[edge[i].to] = dis[x] + 1, q.push(edge[i].to);
        }
        return dis[T] != -1;
    }
    int dfs (int x, int rem) {
        if (!rem || x == T) return rem;
        int ret = 0, i, j;
        for (i = cur[x]; i; i = edge[i].nex) {
            cur[x] = i; j = edge[i].to;
            if (dis[j] != dis[x] + 1 || !edge[i].w) continue;
            int tmp = dfs(j, min(rem, edge[i].w));
            ret += tmp, rem -= tmp;
            edge[i].w -= tmp, edge[i ^ 1].w += tmp;
            if (!rem) break;
        }
        return ret;
    }
    int dinic () { int ret = 0; while (bfs()) ret += dfs(S, inf); return ret; }

    void remake (int id) {
        --edge[id].w; ++edge[id ^ 1].w;
        int tmp = st[edge[id].to - 1]; --edge[tmp].w;
        tmp = ed[edge[id ^ 1].to - 6 - 1]; --edge[tmp].w;
    }
    int aim; vector <int> path; bool vis[MAXN], win = 0;
    void dfs2 (int x, int las) {
        if (las && x == aim) { win = 1; return; }
        for (int i = head[x]; i; i = edge[i].nex) if (!vis[i] && edge[i].w) {
            path.push_back(i); vis[i] = 1; dfs2(edge[i].to, i);
            if (win) return;
            path.pop_back();
        }
    }
    bool attempt (int id) {
        for (int i = 1; i <= cnt; i++) vis[i] = 0;
        path.clear();
        int u = edge[id ^ 1].to, v = edge[id].to;
        aim = v;
        win = 0, dfs2(u, 0); if (!win) return 0;
        for (auto i: path) --edge[i].w, ++edge[i ^ 1].w;
        ++edge[id].w, --edge[id ^ 1].w;
        return 1;
    }
}

int main () {
    scanf("%s", a + 1); n = strlen(a + 1);
    int i, j = read(), buc[6] = {}, buc2[64] = {};
    for (i = 1; i <= n; i++) s[i] = 63, ++buc[a[i] - 'a'];
    while (j--) {
        int x = read(); s[x] = 0;
        char stmp[11]; scanf("%s", stmp);
        for (int i = 0, len = strlen(stmp); i < len; i++) s[x] |= 1 << (stmp[i] - 'a');
    }
    for (i = 1; i <= n; i++) ++buc2[s[i]];
    flow::S = 6 + 64 + 1, flow::T = flow::S + 1;
    for (i = 1; i <= 6; i++) flow::add(flow::S, i, buc[i - 1]), st[i - 1] = flow::cnt;
    for (i = 0; i < 64; i++) {
        flow::add(i + 6 + 1, flow::T, buc2[i]); ed[i] = flow::cnt;
        for (j = 0; j < 6; j++) if ((i >> j) & 1) flow::add(j + 1, i + 6 + 1, flow::inf), E[i][j] = flow::cnt;
    }
    if (flow::dinic() != n) { puts("Impossible"); return 0; }
    for (i = 1; i <= n; i++) {
        for (j = 0; j < 6; j++) if ((s[i] >> j) & 1) {
            if (flow::edge[E[s[i]][j]].w || flow::attempt(E[s[i]][j])) {
                flow::remake(E[s[i]][j]);
                ans[i] = 'a' + j;
                break;
            }
        }
    }
    printf("%s\n", ans + 1);
    return 0;
}