//
// Created by  on 2022/3/5.
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

class Solver{
public:
    void solve(){
        int n;
        std::cin >> n;
        std::vector <int> a(n);
        for (int i = 0; i < n; ++ i){
            std::cin >> a[i];
        }
        std::vector <std::vector <int>> dp(n, std::vector <int>(n));
        std::vector <int> next(n, n);
        for (int i = 0; i < n; ++ i){
            for (int j = i + 1; j < n; ++ j){
                if (a[i] == a[j]){
                    next[i] = j;
                    break;
                }
            }
        }
        for (int len = 2; len <= n; ++ len){
            for (int i = 0; i < n; ++ i){
                int j = i + len - 1;
                if (j >= n){
                    break;
                }
                dp[i][j] = dp[i + 1][j];
                for (int k = next[i]; k <= j; k = next[k]){
                    dp[i][j] = std::max(dp[i][j], 1 + dp[i + 1][k - 1] + dp[k][j]);
                }
            }
        }
        std::cout << n - 1 - dp[0][n - 1] << '\n';
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