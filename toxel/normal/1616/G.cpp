//
// Created by  on 2022/2/27.
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

const int N = 200010;

std::set <int> e[N], e1[N];

class Solver{
public:
    void solve(){
        int n, m;
        std::cin >> n >> m;
        for (int i = 0; i < N; ++ i){
            e[i].clear();
            e1[i].clear();
        }
        for (int i = 0, u, v; i < m; ++ i){
            std::cin >> u >> v;
            e[u].emplace(v);
            e1[v].emplace(u);
        }
        int none = 0;
        for (int i = 1; i < n; ++ i){
            if (!e[i].count(i + 1)){
                none = i;
                break;
            }
        }
        if (none == 0){
            std::cout << 1ll * n * (n - 1) / 2 << '\n';
            return;
        }
        std::vector <int> right(n + 1);
        std::vector <std::array <int, 2>> dp(n + 1);
        dp[none][0] = 1;
        for (int i = n; i >= 1; -- i){
            if (e[i].count(i + 1)){
                right[i] = right[i + 1];
            }
            else{
                right[i] = i;
            }
        }
        for (int i = none; i < n; ++ i){
            for (auto v : e[i]){
                if (v - i >= 2 && v - 1 <= right[i + 1]){
                    for (int j = 0; j < 2; ++ j){
                        if (dp[i][j]){
                            dp[v - 1][j ^ 1] = 1;
                        }
                    }
                }
            }
        }
        std::vector <int> left(n + 1);
        for (int i = 1; i <= n; ++ i){
            if (e1[i].count(i - 1)){
                left[i] = left[i - 1];
            }
            else{
                left[i] = i;
            }
        }
        for (int i = none; i >= 1; -- i){
            for (auto v : e1[i + 1]){
                if (i + 1 - v >= 2 && v + 1 >= left[i]){
                    for (int j = 0; j < 2; ++ j){
                        if (dp[i][j]){
                            dp[v][j ^ 1] = 1;
                        }
                    }
                }
            }
        }
        int cnt[2][3] = {};
        for (int i = none; i <= n; ++ i){
            if (right[i + 1] == n){
                for (int j = 0; j < 2; ++ j){
                    if (dp[i][j]){
                        ++ cnt[1][j];
                    }
                }
                if (dp[i][0] && dp[i][1]){
                    ++ cnt[1][2];
                }
            }
        }
        for (int i = 1; i <= none; ++ i){
            if (left[i] == 1){
                for (int j = 0; j < 2; ++ j){
                    if (dp[i][j]){
                        ++ cnt[0][j];
                    }
                }
                if (dp[i][0] && dp[i][1]){
                    ++ cnt[0][2];
                }
            }
        }
        std::set <pii> special;
        if (right[none + 1] == n){
            special.emplace(n, 1);
        }
        for (int i = none; i <= n; ++ i){
            for (int j = 0; j < 2; ++ j){
                if (cnt[0][j] && dp[i][j ^ 1] && right[i + 1] == n){
                    special.emplace(i, 1);
                }
            }
        }
        for (int i = 1; i <= none; ++ i){
            for (int j = 0; j < 2; ++ j){
                if (cnt[1][j] && dp[i][j ^ 1] && left[i] == 1){
                    special.emplace(n, i + 1);
                }
            }
        }
        ll ans = 1ll * cnt[0][0] * cnt[1][0] + 1ll * cnt[0][1] * cnt[1][1] - 1ll * cnt[0][2] * cnt[1][2];
        if (right[none + 1] == n){
            -- ans;
        }
        if (ans > 0){
            special.emplace(n, 1);
        }
        ans += special.size();
        std::cout << ans << '\n';
    }
};

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int test;
    std::cin >> test;
    while (test --){
        Solver solver;
        solver.solve();
    }
    // floating point number output template
    // std::cout << std::fixed << std::setprecision(18) << 1.0 << '\n';
    return 0;
}

#endif //WORKSPACE_TEMPLATE_H