#include <bits/stdc++.h>

const int N = 310;

int a[N][N], ans[N][N];

void solve(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            scanf("%d", &a[i][j]);
            ans[i][j] = 0;
        }
    }
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            for (int dx = -1; dx <= 1; ++ dx){
                for (int dy = -1; dy <= 1; ++ dy){
                    if (std::abs(dx) + std::abs(dy) != 1){
                        continue;
                    }
                    int x = i + dx, y = j + dy;
                    if (x < 0 || x >= n || y < 0 || y >= m){
                        continue;
                    }
                    ++ ans[x][y];
                }
            }
        }
    }
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            if (a[i][j] > ans[i][j]){
                puts("NO");
                return;
            }
        }
    }
    puts("YES");
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            printf("%d%c", ans[i][j], " \n"[j == m - 1]);
        }
    }
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}