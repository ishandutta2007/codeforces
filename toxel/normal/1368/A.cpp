#include <bits/stdc++.h>

using ll = long long;

void solve(){
    ll a, b, n;
    scanf("%lld%lld%lld", &a, &b, &n);
    int cnt = 0;
    while (a <= n && b <= n){
        ll x = std::max(a, b);
        ll y = a + b;
        a = x, b = y;
        ++ cnt;
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