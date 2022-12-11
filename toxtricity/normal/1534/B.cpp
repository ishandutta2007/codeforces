#include <bits/stdc++.h>

const int N = 500010;
using ll = long long;

int a[N];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    a[n + 1] = 0;
    ll sum = 0;
    for (int i = 1; i <= n + 1; ++ i){
        sum += std::abs(a[i] - a[i - 1]);
    }
    for (int i = 1; i <= n; ++ i){
        if (a[i] > a[i - 1] && a[i] > a[i + 1]){
            sum -= a[i] - std::max(a[i - 1], a[i + 1]);
        }
    }
    printf("%lld\n", sum);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}