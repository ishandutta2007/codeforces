#include <bits/stdc++.h>

using ll = long long;

void solve(){
    int n;
    scanf("%d", &n);
    ll sum = 0;
    for (int i = 0, x; i < n; ++ i){
        scanf("%d", &x);
        sum += x;
    }
    int less = sum % n, more = n - less;
    printf("%lld\n", 1ll * less * more);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}