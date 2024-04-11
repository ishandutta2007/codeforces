#include <bits/stdc++.h>

const int N = 100010;
using ll = long long;

int a[N];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    ll lcm = 1;
    for (int i = 0; i < n; ++ i){
        if (lcm <= 1e12){
            lcm = lcm * (i + 2) / std::gcd(lcm, i + 2);
        }
        if (a[i] % lcm == 0){
            puts("NO");
            return;
        }
    }
    puts("YES");
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}