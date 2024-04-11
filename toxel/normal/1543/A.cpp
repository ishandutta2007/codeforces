#include <bits/stdc++.h>

using ll = long long;

void solve(){
    ll a, b;
    scanf("%lld%lld", &a, &b);
    if (a == b){
        puts("0 0");
        return;
    }
    ll max = std::abs(a - b);
    ll min = std::min(a % max, (max - a % max) % max);
    printf("%lld %lld\n", max, min);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}