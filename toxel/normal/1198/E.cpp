#include <bits/stdc++.h>

using ll = long long;

struct Dinic{
    const static int N = 1010;
    const static ll INF = 0x3f3f3f3f3f3f3f3f;

    struct Edge{
        int to, n;
        ll c;
    };

    std::vector <Edge> e;
    int ecnt, cur[N], head[N], dis[N];
    int n, s, t;

    bool bfs(){
        memset(dis + 1, -1, sizeof(dis[0]) * n);
        dis[s] = 0;
        std::queue<int> queue;
        queue.emplace(s);
        while (!queue.empty()){
            int u = queue.front();
            queue.pop();
            for (int i = head[u]; ~i; i = e[i].n){
                if (!e[i].c) continue;
                int v = e[i].to;
                if (dis[v] == -1){
                    dis[v] = dis[u] + 1;
                    queue.emplace(v);
                }
            }
        }
        return dis[t] != -1;
    }

    ll dfs(int u, ll a){
        if (u == t) return a;
        ll ret = 0;
        for (int &i = cur[u]; ~i; i = e[i].n){
            int v = e[i].to;
            if (!e[i].c || dis[u] + 1 != dis[v]) continue;
            ll tmp = dfs(v, std::min(a - ret, e[i].c));
            if (tmp){
                e[i].c -= tmp, e[i ^ 1].c += tmp;
                if ((ret += tmp) == a) break;
            }
        }
        if (!ret) dis[u] = -1;
        return ret;
    }

    void init(int n, int s, int t){
        this -> n = n, this -> s = s, this -> t = t;
        memset(head + 1, -1, sizeof(head[0]) * n);
        e.clear(), ecnt = 0;
    }

    void addedge(int u, int v, ll c){
        e.push_back({v, head[u], c});
        head[u] = ecnt ++;
        e.push_back({u, head[v], 0});
        head[v] = ecnt ++;
    }

    ll maxflow(){
        ll ret = 0;
        while (bfs()){
            memcpy(cur + 1, head + 1, sizeof(head[0]) * n);
            ret += dfs(s, INF);
        }
        return ret;
    }
};

const int N = 1010;

int c1[N], c2[N];
int x1[N], y1_[N], x2[N], y2[N];
Dinic dinic;
bool vis[N][N];

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    if (m == 0){
        puts("0");
        return 0;
    }
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < m; ++ i){
        scanf("%d%d%d%d", &x1[i], &y1_[i], &x2[i], &y2[i]);
        ++ x2[i], ++ y2[i];
        c1[cnt1 ++] = x1[i];
        c1[cnt1 ++] = x2[i];
        c2[cnt2 ++] = y1_[i];
        c2[cnt2 ++] = y2[i];
    }
    std::sort(c1, c1 + cnt1);
    cnt1 = std::unique(c1, c1 + cnt1) - c1;
    std::sort(c2, c2 + cnt2);
    cnt2 = std::unique(c2, c2 + cnt2) - c2;
    for (int i = 0; i < m; ++ i){
        x1[i] = std::lower_bound(c1, c1 + cnt1, x1[i]) - c1;
        x2[i] = std::lower_bound(c1, c1 + cnt1, x2[i]) - c1;
        y1_[i] = std::lower_bound(c2, c2 + cnt2, y1_[i]) - c2;
        y2[i] = std::lower_bound(c2, c2 + cnt2, y2[i]) - c2;
    }
    for (int i = 0; i < m; ++ i){
        for (int j = x1[i]; j < x2[i]; ++ j){
            for (int k = y1_[i]; k < y2[i]; ++ k){
                vis[j][k] = true;
            }
        }
    }
    int s = 1, t = 2;
    int y_base = t + cnt1 - 1;
    dinic.init(y_base + cnt2 - 1, s, t);
    for (int i = 0; i < N; ++ i){
        for (int j = 0; j < N; ++ j){
            if (vis[i][j]){
                dinic.addedge(t + i + 1, y_base + j + 1, std::min(c1[i + 1] - c1[i], c2[j + 1] - c2[j]));
            }
        }
    }
    for (int i = 0; i < cnt1 - 1; ++ i){
        dinic.addedge(s, t + i + 1, c1[i + 1] - c1[i]);
    }
    for (int i = 0; i < cnt2 - 1; ++ i){
        dinic.addedge(y_base + i + 1, t, c2[i + 1] - c2[i]);
    }
    printf("%d\n", dinic.maxflow());
    return 0;
}