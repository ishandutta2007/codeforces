#include <bits/stdc++.h>

using ll = long long;

void solve(){
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    if (a == 1){
        if (b == 1){
            puts("Yes");
            return;
        }
        puts(n % b == 1 ? "Yes" : "No");
        return;
    }
    ll x = 1;
    while (x <= n){
        if ((n - x) % b == 0){
            puts("Yes");
            return;
        }
        x *= a;
    }
    puts("No");
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}