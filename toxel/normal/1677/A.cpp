//
// Created by  on 2022/5/8.
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
// using Mint = Mod<int, UNDEFINED>;

const int N = 5010;

int cntl[N][N], cntr[N][N];

class Solver{
public:
    void solve(){
        int n;
        std::cin >> n;
        std::vector <int> a(n + 1);
        for (int i = 1; i <= n; ++ i){
            std::cin >> a[i];
        }
        for (int i = 0; i <= n + 1; ++ i){
            for (int j = 0; j <= n + 1; ++ j){
                cntl[i][j] = cntr[i][j] = 0;
            }
        }
        for (int i = 1; i <= n; ++ i){
            for (int j = 1; j <= n; ++ j){
                cntl[i][j] = cntl[i - 1][j] + (j >= a[i]);
            }
        }
        for (int i = n; i >= 1; -- i){
            for (int j = 1; j <= n; ++ j){
                cntr[i][j] = cntr[i + 1][j] + (j >= a[i]);
            }
        }
        ll ans = 0;
        for (int i = 1; i <= n; ++ i){
            for (int j = i + 1; j <= n; ++ j){
                ans += cntl[i - 1][a[j] - 1] * cntr[j + 1][a[i] - 1];
            }
        }
        std::cout << ans << '\n';
    }
};

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int test;
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