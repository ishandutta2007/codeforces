#include <bits/stdc++.h>

const int N = 60;

int dp[N][N][N][N];
char s[N][N];
bool col[N][N][N], row[N][N][N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%s", s[i]);
    }
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < n; ++ j){
            for (int k = j; k < n; ++ k){
                col[i][j][k] = row[i][j][k] = true;
                for (int u = j; u <= k; ++ u){
                    if (s[u][i] == '#'){
                        col[i][j][k] = false;
                    }
                    if (s[i][u] == '#'){
                        row[i][j][k] = false;
                    }
                }
            }
        }
    }
    for (int len1 = 1; len1 <= n; ++ len1){
        for (int len2 = 1; len2 <= n; ++ len2){
            for (int i = 1; i <= n; ++ i){
                for (int j = 1; j <= n; ++ j){
                    int k = i + len1 - 1, u = j + len2 - 1;
                    if (k > n || u > n){
                        continue;
                    }
                    dp[i][j][k][u] = std::max(len1, len2);
                    for (int a = i; a <= k; ++ a){
                        if (row[a - 1][j - 1][u - 1]){
                            dp[i][j][k][u] = std::min(dp[i][j][k][u], dp[i][j][a - 1][u] + dp[a + 1][j][k][u]);
                        }
                    }
                    for (int a = j; a <= u; ++ a){
                        if (col[a - 1][i - 1][k - 1]){
                            dp[i][j][k][u] = std::min(dp[i][j][k][u], dp[i][j][k][a - 1] + dp[i][a + 1][k][u]);
                        }
                    }
                }
            }
        }
    }
    printf("%d\n", dp[1][1][n][n]);
    return 0;
}