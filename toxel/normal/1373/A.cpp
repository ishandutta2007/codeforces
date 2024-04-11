#include <bits/stdc++.h>

using ll = long long;

void solve(){
    ll a, b, c;
    scanf("%lld%lld%lld", &a, &b, &c);
    if (a * b <= c){
        puts("1 -1");
    }
    else{
        printf("%d %lld\n", a >= c ? -1 : 1, b);
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