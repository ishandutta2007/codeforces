#include <bits/stdc++.h>

const int N = 1010;
const int M = N * N;
const int K = 100010;

int a[N][N];
std::vector <int> e[M], vec[N];
int n, m, k;
int dis[M];
bool vis[N];
int l1[K], r1[K], l2[K], r2[K];
int ans[K];

int encode(int x, int y){
    return x * m + y;
}

void addedge(int u, int v){
    e[u].emplace_back(v);
    e[v].emplace_back(u);
}

void bfs(int s){
    memset(dis, 0x3f, sizeof(dis));
    const int INF = 0x3f3f3f3f;
    memset(vis, 0, sizeof(vis));
    std::queue <int> queue;
    for (auto u : vec[s]){
        dis[u] = 0;
        queue.emplace(u);
    }
    while (!queue.empty()){
        int u = queue.front();
        queue.pop();
        for (auto v : e[u]){
            if (dis[v] == INF){
                dis[v] = dis[u] + 1;
                queue.emplace(v);
            }
        }
        int col = a[u / m][u % m];
        if (!vis[col]){
            vis[col] = true;
            for (auto v : vec[col]){
                if (dis[v] == INF){
                    dis[v] = dis[u] + 1;
                    queue.emplace(v);
                }
            }
        }
    }
}

int main(){
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            scanf("%d", &a[i][j]);
            -- a[i][j];
            int code = encode(i, j);
            if (i < n - 1){
                addedge(code, encode(i + 1, j));
            }
            if (j < m - 1){
                addedge(code, encode(i, j + 1));
            }
            vec[a[i][j]].emplace_back(code);
        }
    }
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; ++ i){
        scanf("%d%d%d%d", &l1[i], &r1[i], &l2[i], &r2[i]);
        -- l1[i], -- r1[i], -- l2[i], -- r2[i];
        ans[i] = std::abs(l1[i] - l2[i]) + std::abs(r1[i] - r2[i]);
    }
    for (int i = 0; i < k; ++ i){
        bfs(i);
        for (int j = 0; j < q; ++ j){
            ans[j] = std::min(ans[j], dis[encode(l1[j], r1[j])] + dis[encode(l2[j], r2[j])] + 1);
        }
    }
    for (int i = 0; i < q; ++ i){
        printf("%d\n", ans[i]);
    }
    return 0;
}