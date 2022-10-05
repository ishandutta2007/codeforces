#include <bits/stdc++.h>

const int N = 8010;

int a[N], pre[N];
bool vis[N];

void solve(){
    memset(vis, 0, sizeof(vis));
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
        pre[i] = pre[i - 1] + a[i];
    }
    for (int i = 1; i <= n; ++ i){
        for (int j = 0; j < i - 1; ++ j){
            int diff = pre[i] - pre[j];
            if (diff < N){
                vis[diff] = true;
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++ i){
        cnt += vis[a[i]];
    }
    printf("%d\n", cnt);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}