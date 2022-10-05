#include <bits/stdc++.h>

const int N = 1010;

int a[N], color[N];
bool vis[N];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    memset(vis, 0, sizeof(vis));
    int col = 0;
    for (int i = 2; i <= 31; ++ i){
        int cnt = 0;
        for (int j = 0; j < n; ++ j){
            if (!vis[j] && a[j] % i == 0){
                ++ cnt;
            }
        }
        if (cnt > 0){
            ++ col;
            for (int j = 0; j < n; ++ j){
                if (!vis[j] && a[j] % i == 0){
                    color[j] = col;
                    vis[j] = true;
                }
            }
        }
    }
    printf("%d\n", col);
    for (int i = 0; i < n; ++ i){
        printf("%d%c", color[i], " \n"[i == n - 1]);
    }
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
}