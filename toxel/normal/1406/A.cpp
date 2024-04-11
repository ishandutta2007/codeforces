#include <bits/stdc++.h>

const int N = 110;

int cnt[N];

void solve(){
    memset(cnt, 0, sizeof(cnt));
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        int x;
        scanf("%d", &x);
        ++ cnt[x];
    }
    int ans = 0;
    for (int i = 0; i < N; ++ i){
        if (cnt[i] < 2){
            ans += i;
            break;
        }
    }
    for (int i = 0; i < N; ++ i){
        if (cnt[i] < 1){
            ans += i;
            break;
        }
    }
    printf("%d\n", ans);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}