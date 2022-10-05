#include <bits/stdc++.h>

const int N = 200010;
using ll = long long;

ll a[N];

void solve(){
    int n;
    scanf("%d", &n);
    std::map <ll, int> map;
    for (int i = 1; i <= n; ++ i){
        scanf("%lld", &a[i]);
        ++ map[a[i]];
    }
    int ans = 0;
    for (const auto &p : map){
        auto [min, cur] = p;
        ll diff = 1;
        while (true){
            auto u = map.lower_bound(min + diff);
            if (u == map.end()){
                break;
            }
            ++ cur;
            diff = 2 * (u -> first - min);
        }
        ans = std::max(ans, cur);
    }
    printf("%d\n", n - ans);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}