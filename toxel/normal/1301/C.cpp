#include <bits/stdc++.h>

using ll = long long;

void solve(){
    ll n, m;
    scanf("%lld%lld", &n, &m);
    ll x = n - m;
    ll small = x / (m + 1), big = small + 1;
    ll numbig = x % (m + 1), numsmall = m + 1 - numbig;
    printf("%lld\n", n * (n + 1) / 2 - numsmall * small * (small + 1) / 2 - numbig * big * (big + 1) / 2);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}