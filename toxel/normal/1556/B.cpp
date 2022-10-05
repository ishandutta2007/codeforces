#include <bits/stdc++.h>

const int N = 100010;
using ll = long long;

int a[N], target[N];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; ++ i){
        a[i] %= 2;
    }
    ll ans = LLONG_MAX;
    for (int _ = 0; _ < 2; ++ _){
        target[0] = _;
        for (int i = 1; i < n; ++ i){
            target[i] = target[i - 1] ^ 1;
        }
        int sum = 0;
        for (int i = 0; i < n; ++ i){
            sum += a[i] - target[i];
        }
        if (sum != 0){
            continue;
        }
        std::vector <int> pos[2][2];
        for (int i = 0; i < n; ++ i){
            pos[0][a[i]].emplace_back(i);
            pos[1][target[i]].emplace_back(i);
        }
        ll tot = 0;
        for (int i = 0; i < 2; ++ i){
            int sz = pos[0][i].size();
            for (int j = 0; j < sz; ++ j){
                tot += std::abs(pos[1][i][j] - pos[0][i][j]);
            }
        }
        ans = std::min(ans, tot);
    }
    if (ans == LLONG_MAX){
        ans = -1;
    }
    else{
        ans /= 2;
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