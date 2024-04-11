#include <bits/stdc++.h>

const int N = 100010;

bool vis[N];
int ans[N];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i <= n; ++ i){
        vis[i] = false;
        ans[i] = -1;
    }
    for (int i = 1; i <= n; ++ i){
        int num;
        scanf("%d", &num);
        for (int j = 0; j < num; ++ j){
            int x;
            scanf("%d", &x);
            if (!vis[x] && ans[i] == -1){
                ans[i] = x;
                vis[x] = true;
            }
        }
    }
    int sum = 0;
    for (int i = 1; i <= n; ++ i){
        sum += ans[i] == -1;
    }
    if (sum == 0){
        puts("OPTIMAL");
        return;
    }
    puts("IMPROVE");
    for (int i = 1; i <= n; ++ i){
        if (ans[i] == -1){
            for (int j = 1; j <= n; ++ j){
                if (!vis[j]){
                    printf("%d %d\n", i, j);
                    return;
                }
            }
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