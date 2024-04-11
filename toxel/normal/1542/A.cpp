#include <bits/stdc++.h>

void solve(){
    int n;
    scanf("%d", &n);
    int cnt[2] = {};
    for (int i = 0; i < 2 * n; ++ i){
        int x;
        scanf("%d", &x);
        ++ cnt[x & 1];
    }
    puts(cnt[0] == cnt[1] ? "Yes" : "No");
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}