#include <bits/stdc++.h>

using ll = long long;
const int N = 100010;

int d[N];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &d[i]);
    }
    std::sort(d + 1, d + n + 1);
    ll ans = d[n];
    for (int i = 1; i < n; ++ i){
        ans -= 1ll * (d[i + 1] - d[i]) * i * (n - i);
    }
    printf("%lld\n", ans);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}