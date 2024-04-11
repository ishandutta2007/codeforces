#include <bits/stdc++.h>

#define MAXN (100010)
#define ll long long

int n, m;
std::vector<std::pair<int, int>> vec[MAXN];
std::vector<int> pt;
int id[MAXN];
ll dis[22][MAXN];
bool vis[MAXN];

int seq[MAXN << 1], logdown[MAXN << 1], st[MAXN << 1][20], cnt;
int dep[MAXN];
ll path[MAXN];
int pos[MAXN];

void dfs(int u, int fa) {
    seq[++cnt] = u;
    pos[u] = cnt;
    for (auto &p : vec[u]) {
        int v = p.first, w = p.second;
        if (v == fa) continue;
        if (pos[v]) {
            if (pos[v] < pos[u]) {
                pt.push_back(v);
            }
            continue;
        }
        dep[v] = dep[u] + 1;
        path[v] = path[u] + w;
        dfs(v, u);
        seq[++cnt] = u;
    }
}

void make_st_table() {
    for (int i = 2; i <= cnt; ++i) logdown[i] = logdown[i >> 1] + 1;
    for (int i = 1; i <= cnt; ++i) st[i][0] = i;
    #define depless(u, v) (dep[seq[u]] < dep[seq[v]] ? u : v)
    for (int d = 1; d <= logdown[cnt]; ++d) {
        for (int i = 1; i + (1 << d - 1) <= cnt; ++i) {
            st[i][d] = depless(st[i][d - 1], st[i + (1 << d - 1)][d - 1]);
        }
    }
}

int lca(int u, int v) {
    if (!u || !v) return u + v;
    u = pos[u]; v = pos[v];
    if (u > v) std::swap(u, v);
    int d = logdown[v - u + 1];
    return seq[depless(st[u][d], st[v - (1 << d) + 1][d])];
}

void dijkstra(int s, ll *dis) {
    std::priority_queue<std::pair<ll, int>> pq;
    memset(dis + 1, 0x3f, n * sizeof(ll));
    memset(vis + 1, 0, n * sizeof(bool));
    dis[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (auto &p : vec[u]) {
            int v = p.first, w = p.second;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                pq.push({-dis[v], v});
            }
        }
    }
}

ll getdis(int u, int v) {
    int w = lca(u, v);
    return path[u] - path[w] + path[v] - path[w];
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        vec[u].push_back({v, w});
        vec[v].push_back({u, w});
    }
    dfs(1, 0);
    make_st_table();
    std::sort(pt.begin(), pt.end());
    pt.erase(std::unique(pt.begin(), pt.end()), pt.end());

    for (int i = 0; i < pt.size(); ++i) {
        id[pt[i]] = i;
        dijkstra(pt[i], dis[i]);
        //printf("pt[%d] = %d\n", i, pt[i]);
    }

    int q;
    scanf("%d", &q);
    while (q--) {
        int u, v;
        scanf("%d%d", &u, &v);
        ll ans = getdis(u, v);
        for (int i = 0; i < pt.size(); ++i) {
            ans = std::min(ans, dis[i][u] + dis[i][v]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}