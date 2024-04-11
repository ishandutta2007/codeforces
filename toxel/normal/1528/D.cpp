#include <bits/stdc++.h>

using ll = long long;
using pii = std::pair <ll, ll>;

const int N = 610;
const ll INF = 1e10;

ll mat[N][N], trans[N][N];
ll dis[N];
bool vis[N];

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++ i){
        for (int j = 1; j <= n; ++ j){
            mat[i][j] = INF;
        }
        for (int j = 1; j <= n; ++ j){
            trans[i][j] = INF;
        }
    }
    for (int i = 0; i < m; ++ i){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        ++ a, ++ b;
        mat[a][b] = c;
    }
    for (int i = 1; i <= n; ++ i){
        for (int j = 1; j <= n; ++ j){
            for (int t = 1; t <= n; ++ t){
                int walk = j - t;
                walk += walk < 0 ? n : 0;
                trans[i][j] = std::min(trans[i][j], walk + mat[i][t]);
            }
        }
    }
    for (int i = 1; i <= n; ++ i){
        for (int j = 1; j <= n; ++ j){
            dis[j] = INF;
            vis[j] = false;
        }
        dis[i] = 0;
        for (int j = 1; j <= n; ++ j){
            ll min = INF;
            int pos = 0;
            for (int k = 1; k <= n; ++ k){
                if (!vis[k] && min > dis[k]){
                    min = dis[k];
                    pos = k;
                }
            }
            vis[pos] = true;
            int t = dis[pos] % n;
            for (int k = 1; k <= n; ++ k){
                if (vis[k]){
                    continue;
                }
                ll target = k - t;
                target += target <= 0 ? n : 0;
                dis[k] = std::min(trans[pos][target] + dis[pos], dis[k]);
            }
        }
        for (int j = 1; j <= n; ++ j){
            printf("%lld%c", dis[j], " \n"[j == n]);
        }
    }
    return 0;
}