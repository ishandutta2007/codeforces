//
// Created by  on 2022/10/15.
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

using ll = long long;
using i128 = __int128_t;
using pii = std::pair <int, int>;
using piii = std::tuple <int, int, int>;
using piiii = std::tuple <int, int, int, int>;
using pll = std::pair <ll, ll>;
using plll = std::tuple <ll, ll, ll>;
using pllll = std::tuple <ll, ll, ll, ll>;
// using Mint = Mod<UNDEFINED>;

class Solver{
public:
    std::vector <std::vector <int>> e;
    std::vector <pll> dp;
    std::vector <int> base, s;

    Solver(){}

    ll *get(int node, int num){
        if (base[node] == -1){
            base[node] = num;
            return &dp[node].first;
        }
        if (base[node] == num){
            return &dp[node].first;
        }
        return &dp[node].second;
    }

    void dfs(int u, int k){
        ll *dp_value = get(u, k);
        if (*dp_value != -1){
            return;
        }
        int deg = e[u].size();
        if (deg > 0){
            int big = k % deg;
            *dp_value = 1ll * k * s[u];
            std::vector <ll> diff;
            for (auto v: e[u]){
                dfs(v, k / deg);
                dfs(v, (k + deg - 1) / deg);
                *dp_value += *get(v, k / deg);
                if (big > 0){
                    diff.emplace_back(*get(v, k / deg + 1) - *get(v, k / deg));
                }
            }
            if (big > 0){
                std::sort(diff.begin(), diff.end(), std::greater<>());
                for (int i = 0; i < big; ++ i){
                    *dp_value += diff[i];
                }
            }
        }
        else{
            *dp_value = 1ll * k * s[u];
        }
    }

    void solve(){
        int n, k;
        std::cin >> n >> k;
        e.resize(n + 1);
        for (int i = 2; i <= n; ++ i){
            int p;
            std::cin >> p;
            e[p].emplace_back(i);
        }
        s.resize(n + 1);
        for (int i = 1; i <= n; ++ i){
            std::cin >> s[i];
        }
        dp.resize(n + 1, {-1, -1});
        base.resize(n + 1, -1);
        dfs(1, k);
        std::cout << *get(1, k) << '\n';
    }
};

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int test = 1;
    std::cin >> test;
    // floating point number output template
    std::cout << std::fixed << std::setprecision(18);
    while (test --){
        Solver solver;
        solver.solve();
    }
    return 0;
}

#endif //WORKSPACE_TEMPLATE_H