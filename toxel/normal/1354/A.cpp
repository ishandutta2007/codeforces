#include <bits/stdc++.h>

using ll = long long;

void solve(){
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    if (a <= b){
        printf("%d\n", b);
        return;
    }
    a -= b;
    if (c <= d){
        puts("-1");
        return;
    }
    ll round = (a + c - d - 1) / (c - d);
    ll ans = b + round * c;
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