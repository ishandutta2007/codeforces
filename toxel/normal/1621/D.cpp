#include <bits/stdc++.h>

const int N = 1010;
using ll = long long;

int a[N][N];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < 2 * n; ++ i){
        for (int j = 0; j < 2 * n; ++ j){
            scanf("%d", &a[i][j]);
        }
    }
    ll ans = 0;
    for (int i = n; i < 2 * n; ++ i){
        for (int j = n; j < 2 * n; ++ j){
            ans += a[i][j];
        }
    }
    int x = INT_MAX;
    x = std::min(x, a[n][0]);
    x = std::min(x, a[n][n - 1]);
    x = std::min(x, a[2 * n - 1][0]);
    x = std::min(x, a[2 * n - 1][n - 1]);
    x = std::min(x, a[0][n]);
    x = std::min(x, a[n - 1][n]);
    x = std::min(x, a[0][2 * n - 1]);
    x = std::min(x, a[n - 1][2 * n - 1]);
    ans += x;
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