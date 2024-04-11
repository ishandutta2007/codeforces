#include <bits/stdc++.h>

const int N = 110;

int h[N][N], f[N], l[N];
bool vis[N][N];

int main(){
    int n, m, hh;
    scanf("%d%d%d", &n, &m, &hh);
    for (int i = 0; i < m; ++ i){
        scanf("%d", &f[i]);
    }
    for (int i = 0; i < n; ++ i){
        scanf("%d" , &l[i]);
    }
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            scanf("%d", &h[i][j]);
            if (!h[i][j]){
                vis[i][j] = true;
            }
        }
    }
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            if (h[i][j] && f[j] >= l[i]){
                h[i][j] = l[i];
                vis[i][j] = true;
                break;
            }
        }
    }
    for (int j = 0; j < m; ++ j){
        for (int i = 0; i < n; ++ i){
            if (h[i][j] && l[i] >= f[j]){
                h[i][j] = f[j];
                vis[i][j] = true;
                break;
            }
        }
    }
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            if (!vis[i][j]){
                h[i][j] = 1;
            }
            printf("%d%c", h[i][j], " \n"[j == m - 1]);
        }
    }
    return 0;
}