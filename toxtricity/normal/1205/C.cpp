#include <bits/stdc++.h>

const int N = 51;

int a[2][N][N];
int dp[2][N][N][N][N];

int query(int x1, int y1, int x2, int y2){
    printf("? %d %d %d %d\n", x1 + 1, y1 + 1, x2 + 1, y2 + 1);
    fflush(stdout);
    int ans;
    scanf("%d", &ans);
    if (ans == -1){
        exit(0);
    }
    return 1 ^ ans;
}

void getDp(int type, int n){
    for (int len1 = 1; len1 <= n; ++ len1){
        for (int i = 0; i < n; ++ i){
            int j = i + len1 - 1;
            if (j >= n){
                break;
            }
            for (int len2 = 1; len2 <= n; ++ len2){
                for (int u = 0; u < n; ++ u){
                    int v = u + len2 - 1;
                    if (v >= n){
                        break;
                    }
                    if (len1 + len2 == 2){
                        dp[type][i][j][u][v] = 1;
                    }
                    else if (len1 + len2 == 3){
                        dp[type][i][j][u][v] = a[type][i][u] == a[type][j][v];
                    }
                    else{
                        if (a[type][i][u] == a[type][j][v]){
                            dp[type][i][j][u][v] |= dp[type][i + 1][j][u - 1][v];
                            dp[type][i][j][u][v] |= dp[type][i][j + 1][u - 1][v];
                            dp[type][i][j][u][v] |= dp[type][i + 1][j][u][v - 1];
                            dp[type][i][j][u][v] |= dp[type][i][j + 1][u][v - 1];
                        }
                    }
                }
            }
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);
    memset(a, -1, sizeof(a));
    a[0][0][0] = a[1][0][0] = 1;
    a[0][n - 1][n - 1] = a[1][n - 1][n - 1] = 0;
    a[0][0][1] = 0, a[1][0][1] = 1;
    for (int i = 0; i < n; ++ i){
        if (a[0][0][i] == -1){
            int ret = query(0, i - 2, 0, i);
            a[0][0][i] = a[0][0][i - 2] ^ ret;
            a[1][0][i] = a[1][0][i - 2] ^ ret;
        }
    }
    for (int i = 1; i < n; ++ i){
        if (a[0][1][i] == -1){
            int ret = query(0, i - 1, 1, i);
            a[0][1][i] = a[0][0][i - 1] ^ ret;
            a[1][1][i] = a[1][0][i - 1] ^ ret;
        }
    }
    {
        int ret = query(1, 0, 1, 2);
        a[0][1][0] = a[0][1][2] ^ ret;
        a[1][1][0] = a[1][1][2] ^ ret;
    }
    for (int i = 2; i < n; ++ i){
        for (int j = 0; j < n; ++ j){
            if (a[0][i][j] == -1){
                int ret = query(i - 2, j, i, j);
                a[0][i][j] = a[0][i - 2][j] ^ ret;
                a[1][i][j] = a[1][i - 2][j] ^ ret;
            }
        }
    }
    getDp(0, n);
    getDp(1, n);
    int type = -1;
    for (int i = 0; i < n; ++ i){
        for (int j = i; j < n; ++ j){
            for (int u = 0; u < n; ++ u){
                for (int v = u; v < n; ++ v){
                    if (i + u + 2 <= j + v){
                        if (dp[0][i][j][u][v] != dp[1][i][j][u][v]){
                            int ret = query(i, u, j, v) ^ 1;
                            for (int _ = 0; _ < 2; ++ _){
                                if (dp[_][i][j][u][v] == ret){
                                    type = _;
                                }
                            }
                            goto output;
                        }
                    }
                }
            }
        }
    }
    output:
    puts("!");
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < n; ++ j){
            putchar(a[type][i][j] + '0');
        }
        puts("");
    }
    return 0;
}