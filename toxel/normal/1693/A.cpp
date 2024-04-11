//
// Created by  on 2022/6/16.
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
        int n;
        std::cin >> n;
        std::vector <ll> a(n), diff(n - 1);
        ll sum = 0;
        for (int i = 0; i < n; ++ i){
            std::cin >> a[i];
            sum += a[i];
        }
        if (sum != 0){
            std::cout << "NO\n";
            return;
        }
        for (int i = 0; i < n - 1; ++ i){
            diff[i] = a[i];
            if (i > 0){
                diff[i] += diff[i - 1];
            }
        }
        for (int i = 0; i < n - 1; ++ i){
            if (diff[i] < 0){
                std::cout << "NO\n";
                return;
            }
        }
        for (int i = 1; i < n - 1; ++ i){
            if (diff[i] && !diff[i - 1]){
                std::cout << "NO\n";
                return;
            }
        }
        std::cout << "YES\n";
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