#include <bits/stdc++.h>

const int N = 200010;
using ll = long long;

ll a[N];

void solve(){
    int n;
    ll k;
    scanf("%d%lld", &n, &k);
    for (int i = 0; i < n; ++ i){
        scanf("%lld", &a[i]);
    }
    ll gcd = 0;
    for (int i = 0; i < n - 1; ++ i){
        ll diff = a[i + 1] - a[i];
        if (!diff){
            continue;
        }
        gcd = std::gcd(diff, gcd);
    }
    if (gcd == 0){
        puts(a[0] == k ? "YES" : "NO");
        return;
    }
    if ((k - a[0]) % gcd == 0){
        puts("YES");
    }
    else{
        puts("NO");
    }
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
}