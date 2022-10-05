#include <bits/stdc++.h>

const int N = 1000010;

int cnt[N];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i <= 2 * n + 10; ++ i){
        cnt[i] = 0;
    }
    for (int i = 0; i < n; ++ i){
        int x;
        scanf("%d", &x);
        ++ cnt[x];
    }
    for (int i = 0; i <= 2 * n; ++ i){
        if (cnt[i] >= 2){
            -- cnt[i];
            ++ cnt[i + 1];
        }
    }
    int ans = 0;
    for (int i = 0; i <= 2 * n + 1; ++ i){
        ans += cnt[i] > 0;
    }
    printf("%d\n", ans);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
}