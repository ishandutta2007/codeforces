#include <bits/stdc++.h>

using ll = long long;

void solve(){
    ll r, g, b;
    scanf("%lld%lld%lld", &r, &g, &b);
    ll max = std::max(std::max(r, g), b);
    ll other = r + g + b - max;
    if (max > other + 1){
        puts("No");
    }
    else{
        puts("Yes");
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