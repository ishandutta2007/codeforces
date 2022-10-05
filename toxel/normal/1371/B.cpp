#include <bits/stdc++.h>

void solve(){
    int n, r;
    scanf("%d%d", &n, &r);
    long long ans = 0;
    if (r >= n){
        ++ ans;
    }
    r = std::min(n - 1, r);
    printf("%lld\n", ans + 1ll * r * (r + 1) / 2);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}