#include<bits/stdc++.h>

const int N = 2010;

char s[N][N];
int dp[N][N];
bool vis[N][N];

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++ i){
        scanf("%s", s[i]);
    }
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < n; ++ j){
            dp[i][j] += s[i][j] == 'a';
            dp[i][j + 1] = std::max(dp[i][j + 1], dp[i][j]);
            dp[i + 1][j] = std::max(dp[i + 1][j], dp[i][j]);
        }
    }
    int max = 0;
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < n; ++ j){
            int more = i + j + 1 - dp[i][j];
            if (more <= k){
                if (dp[i][j] > max){
                    max = dp[i][j];
                    if (max + k >= 2 * n - 1){
                        for (int i = 0; i < 2 * n - 1; ++ i){
                            putchar('a');
                        }
                        puts("");
                        return 0;
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < n; ++ j){
            int more = i + j + 1 - dp[i][j];
            if (more <= k){
                if (dp[i][j] == max){
                    for (int x = 0; x < n; ++ x){
                        int y = max + k - 1 - x;
                        if (y < 0 || y >= n || i > x || j > y) continue;
                        vis[x + 1][y] = true;
                        vis[x][y + 1] = true;
                    }
                }
            }
        }
    }
    for (int i = 0; i < max + k; ++ i){
        putchar('a');
    }
    if (!max && !k){
        vis[0][0] = true;
    }
    for (int dis = max + k; dis < 2 * n - 1; ++ dis){
        int min = INT_MAX;
        for (int x = 0; x < n; ++ x){
            int y = dis - x;
            if (y < 0 || y >= n || !vis[x][y]) continue;
            min = std::min(min, (int) s[x][y]);
        }
        for (int x = 0; x < n; ++ x){
            int y = dis - x;
            if (y < 0 || y >= n || !vis[x][y]) continue;
            if (s[x][y] == min){
                vis[x + 1][y] = true;
                vis[x][y + 1] = true;
            }
        }
        putchar((char) min);
    }
    puts("");
    return 0;
}