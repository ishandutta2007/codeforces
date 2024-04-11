//
// Created by  on 2022/3/6.
//

//
// Created by  on 2022/1/6.
//

#ifndef WORKSPACE_TEMPLATE_H
#define WORKSPACE_TEMPLATE_H

#include <bits/stdc++.h>
#define mp std::make_pair
#define scanf dont_use_scanf
#define printf dont_use_printf
#define puts dont_use_puts
#define endl dont_use_endl

using ll = int64_t;
using i128 = __int128_t;
using pii = std::pair <int, int>;
using piii = std::tuple <int, int, int>;
using piiii = std::tuple <int, int, int, int>;
using pll = std::pair <ll, ll>;
using plll = std::tuple <ll, ll, ll>;
using pllll = std::tuple <ll, ll, ll, ll>;

const int N = 210;

pll dp[N][N];

pii operator -(pii p1, pii p2){
    return {p1.first - p2.first, p1.second - p2.second};
}

class Solver{
public:
    int n, k;
    std::vector <pii> ps;

    bool check(ll mid){
        memset(dp, 0, sizeof(dp));
        for (int len = 2; len < n; ++ len){
            for (int i = 0; i < n; ++ i){
                int j = (i + len) % n;
                for (int K = (i + 1) % n; K != j; ++ K, K -= K >= n ? n : 0){
                    pii p1 = ps[j] - ps[i], p2 = ps[K] - ps[i];
                    ll area = std::abs(1ll * p1.first * p2.second - 1ll * p2.first * p1.second);
                    ll s = area + dp[i][K].second + dp[K][j].second;
                    ll value = dp[i][K].first + dp[K][j].first;
                    if (s >= mid){
                        ++ value;
                        s = 0;
                    }
                    pll p{value, s};
                    dp[i][j] = std::max(dp[i][j], p);
                }
            }
        }
        return dp[0][n - 1].first >= k + 1;
    }

    void solve(){
        std::cin >> n >> k;
        ps.resize(n);
        for (int i = 0; i < n; ++ i){
            std::cin >> ps[i].first >> ps[i].second;
        }
        ll l = 1, r = 1.1e17;
        while (l < r){
            ll mid = (l + r + 1) / 2;
            if (check(mid)){
                l = mid;
            }
            else{
                r = mid - 1;
            }
        }
        std::cout << l << '\n';
    }
};

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int test = 1;
    // std::cin >> test;
    while (test --){
        Solver solver;
        solver.solve();
    }
    // floating point number output template
    // std::cout << std::fixed << std::setprecision(18) << 1.0 << '\n';
    return 0;
}

#endif //WORKSPACE_TEMPLATE_H