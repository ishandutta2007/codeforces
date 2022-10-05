#include <bits/stdc++.h>

const int N = 200010;
using ll = long long;

ll a[N];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%lld", &a[i]);
    }
    ll ans = 0;
    for (int i = 0; i < n - 1; ++ i){
        ans += std::max(0ll, a[i] - a[i + 1]);
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