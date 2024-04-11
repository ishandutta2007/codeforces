#include <bits/stdc++.h>

const int N = 300010;
using ll = long long;

int k[N], c[N];
ll pre[N], pre1[N];

void solve(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &k[i]);
    }
    std::sort(k + 1, k + n + 1);
    int min = 0;
    for (int i = 1; i <= n; ++ i){
        min = std::min(min, k[i] - i);
    }
    min = -min;
    for (int i = 1; i <= m; ++ i){
        scanf("%d", &c[i]);
    }
    for (int i = 1; i <= n; ++ i){
        pre[i] = pre[i - 1] + c[k[i]];
        pre1[i] = pre1[i - 1] + c[i];
    }
    ll ans = LLONG_MAX;
    for (int i = min; i <= n; ++ i){
        ans = std::min(ans, pre[i] + pre1[n - i]);
    }
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