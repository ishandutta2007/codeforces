#include <bits/stdc++.h>

using ll = long long;

void solve(){
    ll a, b, n, m;
    scanf("%lld%lld%lld%lld", &a, &b, &n, &m);
    ll diff = std::max(a, b) - std::min(a, b);
    diff = std::min(diff, n);
    if (a > b){
        a -= diff;
    }
    else{
        b -= diff;
    }
    n -= diff;
    ll x = std::min(n, m);
    if (std::min(a, b) < x){
        puts("No");
        return;
    }
    a -= x, b -= x, n -= x, m -= x;
    if (n > 0){
        puts(a + b >= n ? "Yes" : "No");
    }
    else{
        puts(std::min(a, b) >= m ? "Yes" : "No");
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