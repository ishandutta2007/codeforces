#include <bits/stdc++.h>

const int N = 20;
using ll = long long;

ll a[N];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%lld", &a[i]);
    }
    ll mult = 1;
    for (int i = 0; i < n; ++ i){
        while (a[i] % 2 == 0){
            a[i] /= 2;
            mult *= 2;
        }
    }
    std::sort(a, a + n);
    a[n - 1] *= mult;
    ll sum = 0;
    for (int i = 0; i < n; ++ i){
        sum += a[i];
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