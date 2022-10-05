#include <bits/stdc++.h>

const int N = 310;

int a[N][N], ans[N][N];
int maxx[N], maxy[N];
bool vis[N * N];

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            scanf("%d", &a[i][j]);
            maxx[i] = std::max(maxx[i], a[i][j]);
            maxy[j] = std::max(maxy[j], a[i][j]);
        }
    }
    std::sort(maxx, maxx + n);
    std::sort(maxy, maxy + m);
    int cur = 1;
    for (int i = 0, j = 0; i < n || j < m; ){
        int x = maxx[i], y = maxy[j];
        ans[i][j] = std::min(x, y);
        vis[ans[i][j]] = true;
        if (x <= y){
            for (int k = m - 1; k > j; -- k){
                while (vis[cur]){
                    ++ cur;
                }
                ans[i][k] = cur;
                vis[cur] = true;
            }
        }
        if (y <= x){
            for (int k = n - 1; k > i; -- k){
                while (vis[cur]){
                    ++ cur;
                }
                ans[k][j] = cur;
                vis[cur] = true;
            }
        }
        if (x <= y){
            ++ i;
        }
        if (y <= x){
            ++ j;
        }
    }
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            printf("%d%c", ans[i][j], " \n"[j == m - 1]);
        }
    }
    return 0;
}