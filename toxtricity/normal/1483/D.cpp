#include <bits/stdc++.h>

const int N = 610;
using ll = long long;
const ll INF = 1e18;

ll mat[N][N], dis[N][N];
int pair[N][N];
bool vis[N][N];

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < N; ++ i){
        for (int j = 0; j < N; ++ j){
            mat[i][j] = INF;
        }
    }
    for (int i = 0, u, v, w; i < m; ++ i){
        scanf("%d%d%d", &u, &v, &w);
        mat[u][v] = mat[v][u] = w;
    }
    int q;
    scanf("%d", &q);
    memset(pair, -1, sizeof(pair));
    for (int i = 0, u, v, w; i < q; ++ i){
        scanf("%d%d%d", &u, &v, &w);
        pair[u][v] = pair[v][u] = w;
    }
    memcpy(dis, mat, sizeof(mat));
    for (int i = 1; i <= n; ++ i){
        dis[i][i] = 0;
    }
    for (int k = 1; k <= n; ++ k){
        for (int i = 1; i <= n; ++ i){
            for (int j = 1; j <= n; ++ j){
                dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    for (int u = 1; u <= n; ++ u){
        for (int y = 1; y <= n; ++ y){
            ll max = LLONG_MIN;
            for (int v = 1; v <= n; ++ v){
                if (dis[v][y] == INF){
                    continue;
                }
                if (pair[u][v] == -1){
                    continue;
                }
                max = std::max(max, pair[u][v] - dis[v][y]);
            }
            for (int x = 1; x <= n; ++ x){
                if (dis[u][x] == INF){
                    continue;
                }
                if (mat[x][y] == INF){
                    continue;
                }
                if (dis[u][x] + mat[x][y] <= max){
                    vis[x][y] = true;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++ i){
        for (int j = i + 1; j <= n; ++ j){
            ans += vis[i][j] || vis[j][i];
        }
    }
    printf("%d\n", ans);
    return 0;
}