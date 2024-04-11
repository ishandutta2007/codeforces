#include <bits/stdc++.h>

const int N = 400010;
using ll = long long;

int d[N];

ll calc(int x){
    return 1ll * x * (x + 1) / 2;
}

ll calc(int l, int r){
    return 1ll * (l + r) * (r - l + 1) / 2;
}

void solve(){
    int n;
    ll x;
    scanf("%d%lld", &n, &x);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &d[i]);
    }
    std::reverse(d, d + n);
    for (int i = 0; i < n; ++ i){
        d[i + n] = d[i];
    }
    ll sum = 0;
    ll value = 0;
    ll ans = 0;
    for (int i = 0, j = 0; i < n; ++ i){
        while (j < 2 * n && sum + d[j] <= x){
            sum += d[j];
            value += calc(d[j]);
            ++ j;
        }
        int left = x - sum;
        ans = std::max(ans, value + calc(d[j] - left + 1, d[j]));
        if (i == j){
            ++ j;
        }
        else{
            sum -= d[i];
            value -= calc(d[i]);
        }
    }
    printf("%lld\n", ans);
}

int main(){
    int test;
    test = 1;
    while (test --){
        solve();
    }
    return 0;
}