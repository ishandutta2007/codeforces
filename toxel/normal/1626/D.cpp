//
// Created by  on 2022/1/17.
//

//
// Created by  on 2022/1/6.
//

#include <bits/stdc++.h>
#define mp std::make_pair
#define scanf dont_use_scanf
#define printf dont_use_printf
#define endl dont_use_endl

using ll = int64_t;
using pii = std::pair <int, int>;
using piii = std::tuple <int, int, int>;

void solve(){
    int n;
    std::cin >> n;
    std::vector <int> cnt(n + 1);
    for (int i = 0; i < n; ++ i){
        int x;
        std::cin >> x;
        ++ cnt[x];
    }
    for (int i = 1; i <= n; ++ i){
        cnt[i] += cnt[i - 1];
    }
    const int BIT = 19;
    int ans = INT_MAX;
    for (int i = 0; i <= BIT; ++ i){
        for (int j = 0; j <= BIT; ++ j){
            auto u = std::upper_bound(cnt.begin(), cnt.end(), 1 << i);
            assert(u != cnt.begin());
            u = std::prev(u);
            int cost = (1 << i) - *u;
            auto v = std::upper_bound(cnt.begin(), cnt.end(), (1 << j) + *u);
            v = std::prev(v);
            cost += (1 << j) + *u - *v;
            int left = cnt[n] - *v;
            for (int k = 0; k <= BIT; ++ k){
                if ((1 << k) >= left){
                    cost += (1 << k) - left;
                    break;
                }
            }
            ans = std::min(ans, cost);
        }
    }
    std::cout << ans << '\n';
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int test;
    std::cin >> test;
    while (test --){
        solve();
    }
    return 0;
}