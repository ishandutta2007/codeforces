//
// Created by  on 2022/9/30.
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
    void solve(){
        const int N = 110;
        int n;
        std::cin >> n;
        std::vector <int> a(n);
        int cnt[2] = {};
        for (int i = 0; i < n; ++ i){
            std::cin >> a[i];
            a[i] &= 1;
            ++ cnt[a[i]];
        }
        std::vector <std::array <bool, N>> dp[2][2];
        for (int i = 0; i < 2; ++ i){
            for (int j = 0; j < 2; ++ j){
                dp[i][j].resize(n + 10);
            }
        }
        for (int k = 0; k <= n; ++ k){
            for (int u = 0; u <= n; ++ u){
                for (int i = 0; i < 2; ++ i){
                    for (int j = 0; j < 2; ++ j){
                        if (k == 0 && u == 0){
                            if (i == 0){
                                dp[i][j][k][u] = j == 0;
                            }
                            else{
                                dp[i][j][k][u] = j == 1;
                            }
                        }
                        else{
                            if (k > 0){
                                int ni = i;
                                if (!dp[ni][j ^ 1][k - 1][u]){
                                    dp[i][j][k][u] = true;
                                }
                            }
                            if (u > 0){
                                int ni = i ^ (j == 0 ? 1 : 0);
                                if (!dp[ni][j ^ 1][k][u - 1]){
                                    dp[i][j][k][u] = true;
                                }
                            }
                        }
                    }
                }
            }
        }
        std::cout << (dp[0][0][cnt[0]][cnt[1]] ? "Alice\n" : "Bob\n");
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