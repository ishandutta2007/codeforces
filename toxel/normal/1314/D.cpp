#include <bits/stdc++.h>

const int N = 81;
const int M = 6;
const int INF = 0x3f3f3f3f;

int a[N][N];
int min[N][N][N][N];
int b[M], c[M];
int trans[M][M];
int dp[M][M];
int n, k;
int ans = INF;

void dfs(int cur, int before){
    if (cur == n - 1){
        return;
    }
    b[cur] = 0;
    memcpy(c, b, sizeof(b));
    std::sort(c, c + cur + 1);
    for (int i = 0; i <= cur; ++ i){
        for (int j = 0; j <= cur; ++ j){
            trans[i][j] = INT_MAX;
            for (int k = 0; k <= cur; ++ k){
                trans[i][j] = std::min(trans[i][j], min[c[i]][c[j]][c[k] + 1][(k == cur ? n : c[k + 1]) - 1]);
            }
        }
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= k / 2 - 1; ++ i){
        for (int j = 0; j <= cur; ++ j){
            for (int k = 0; k <= cur; ++ k){
                if (dp[i - 1][k] == INF){
                    continue;
                }
                dp[i][j] = std::min(dp[i][j], dp[i - 1][k] + trans[k][j]);
            }
        }
    }
    for (int i = 0; i <= cur; ++ i){
        ans = std::min(ans, dp[k / 2 - 1][i] + trans[i][0]);
    }
    if (cur == 4){
        return;
    }
    for (int i = before + 1; i < n; ++ i){
        b[cur] = i;
        dfs(cur + 1, b[cur]);
    }
}

int main(){
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < n; ++ j){
            scanf("%d", &a[i][j]);
        }
    }
    memset(min, 0x3f, sizeof(min));
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < n; ++ j){
            for (int k = 0; k < n; ++ k){
                min[i][j][k][k] = a[i][k] + a[k][j];
                for (int u = k + 1; u < n; ++ u){
                    min[i][j][k][u] = std::min(min[i][j][k][u - 1], a[i][u] + a[u][j]);
                }
            }
        }
    }
    dfs(0, 0);
    printf("%d\n", ans);
    return 0;
}