#include <bits/stdc++.h>

const int N = 100010;
using ll = long long;
using db = double;

int a[N];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    std::sort(a, a + n);
    ll sum = 0;
    for (int i = 0; i < n; ++ i){
        sum += a[i];
    }
    ll cur = 0;
    db ans = -1e100;
    for (int i = 0; i < n - 1; ++ i){
        cur += a[i];
        ans = std::max(ans, 1. * cur / (i + 1) + 1. * (sum - cur) / (n - i - 1));
    }
    printf("%.15f\n", ans);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}