//
// Created by  on 2022/10/23.
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
    Solver(){}

    void solve(){
        int n;
        std::cin >> n;
        std::vector <int> a(n + 1);
        for (int i = 1; i <= n; ++ i){
            std::cin >> a[i];
        }
        std::vector <std::array <int, 2>> pre(n + 1), dp(n + 1, {-1, -1});
        int sum = 0;
        for (int i = 1; i <= n; ++ i){
            sum += a[i];
        }
        bool reverse = false;
        if (sum < 0){
            for (int i = 1; i <= n; ++ i){
                a[i] = -a[i];
            }
            sum = -sum;
            reverse = true;
        }
        if (sum % 2 == 1){
            std::cout << -1 << '\n';
            return;
        }
        dp[1][0] = 0;
        for (int i = 2; i <= n; ++ i){
            for (int j = 0; j < 2; ++ j){
                if (dp[i - 1][j] == -1){
                    continue;
                }
                for (int k = 0; k < 2; ++ k){
                    if (k == 1 && a[i] != 1){
                        continue;
                    }
                    if (j + k == 2){
                        continue;
                    }
                    int value = dp[i - 1][j] + k;
                    if (value > dp[i][k]){
                        dp[i][k] = value;
                        pre[i][k] = j;
                    }
                }
            }
        }
        std::vector <int> ans(n + 1, 1);
        for (int _ = 0; _ < 2; ++ _){
            if (dp[n][_] >= sum / 2){
                int count = sum / 2;
                int cur = n, take = _;
                while (count > 0){
                    if (take == 1){
                        ans[cur] = 0;
                        -- count;
                    }
                    take = pre[cur][take];
                    -- cur;
                }
                std::vector <pii> output;
                for (int i = 1; i <= n; ){
                    if (i < n && ans[i + 1] == 0){
                        output.emplace_back(i, i + 1);
                        i += 2;
                    }
                    else{
                        output.emplace_back(i, i);
                        i += 1;
                    }
                }
                std::cout << output.size() << "\n";
                for (auto [l, r]: output){
                    std::cout << l << " " << r << "\n";
                }
                return;
            }
        }
        std::cout << -1 << "\n";
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