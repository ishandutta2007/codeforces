#include <bits/stdc++.h>

const int N = 510;
const int K = 11;

int d1[N][N], d2[N][N];
int dp[K * 2][K * 2][K];

inline void update(int &u, int v, int w){
    u = std::min(u, v + w);
}

void read(int &n){
    char ch;
    while (!isdigit(ch = getchar()))
        ;
    n = ch - '0';
    while (isdigit(ch = getchar())){
        n = n * 10 + ch - '0';
    }
}

int main(){
    int n, m, k;
    read(n), read(m), read(k);
    for (int i = 1; i <= n; ++ i){
        for (int j = 1; j < m; ++ j){
            read(d1[i][j]);
            // d1[i][j] = 1;
        }
    }
    for (int i = 1; i < n; ++ i){
        for (int j = 1; j <= m; ++ j){
            read(d2[i][j]);
            // d2[i][j] = 1;
        }
    }
    if (k % 2 == 1){
        for (int i = 1; i <= n; ++ i){
            for (int j = 1; j <= m; ++ j){
                printf("%d%c", -1, " \n"[j == m]);
            }
        }
        return 0;
    }
    k /= 2;
    for (int i = 1; i <= n; ++ i){
        for (int j = 1; j <= m; ++ j){
            memset(dp, 0x3f, sizeof(dp));
            dp[K][K][0] = 0;
            for (int t = 0; t < k; ++ t){
                for (int u = -t + K; u <= t + K; ++ u){
                    for (int v = -t + std::abs(u - K) + K; std::abs(u + v - 2 * K) <= t; v += 2){
                        int uu = u - K + i;
                        int vv = v - K + j;
                        if (uu > 1){
                            update(dp[u - 1][v][t + 1], dp[u][v][t], d2[uu - 1][vv]);
                        }
                        if (uu < n){
                            update(dp[u + 1][v][t + 1], dp[u][v][t], d2[uu][vv]);
                        }
                        if (vv > 1){
                            update(dp[u][v - 1][t + 1], dp[u][v][t], d1[uu][vv - 1]);
                        }
                        if (vv < m){
                            update(dp[u][v + 1][t + 1], dp[u][v][t], d1[uu][vv]);
                        }
                    }
                }
            }
            const int INF = 0x3f3f3f3f;
            int ans = INF;
            for (int u = 0; u < K * 2; ++ u){
                for (int v = 0; v < K * 2; ++ v){
                    update(ans, dp[u][v][k], 0);
                }
            }
            printf("%d%c", ans * 2, " \n"[j == m]);
        }
    }
    return 0;
}