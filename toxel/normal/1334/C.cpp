#include <bits/stdc++.h>

const int N = 300010;
using ll = long long;

ll a[N], b[N];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%lld%lld", &a[i], &b[i]);
    }
    ll min = LLONG_MAX;
    for (int i = 0; i < n; ++ i){
        min = std::min(min, std::min(a[i], b[(i - 1 + n) % n]));
    }
    ll sum = min;
    for (int i = 0; i < n; ++ i){
        sum += a[i] - std::min(a[i], b[(i - 1 + n) % n]);
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