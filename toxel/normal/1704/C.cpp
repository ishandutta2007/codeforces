//
// Created by  on 2022/7/31.
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
// using Mint = Mod<int, UNDEFINED>;

class Solver{
public:
    void solve(){
        int n, m;
        std::cin >> n >> m;
        std::vector <int> a(m), diff(m);
        for (int i = 0; i < m; ++ i){
            std::cin >> a[i];
        }
        std::sort(a.begin(), a.end());
        for (int i = 0; i < m - 1; ++ i){
            diff[i] = a[i + 1] - a[i] - 1;
        }
        diff[m - 1] = n - a[m - 1] + a[0] - 1;
        std::sort(diff.begin(), diff.end(), std::greater());
        int ans = 0;
        for (int i = 0; i < m; ++ i){
            int sub = 4 * i;
            if (diff[i] <= sub){
                break;
            }
            ans += std::max(1, diff[i] - sub - 1);
        }
        std::cout << n - ans << '\n';
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