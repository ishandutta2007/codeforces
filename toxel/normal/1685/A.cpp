//
// Created by  on 2022/5/26.
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

class Solver{
public:
    void solve(){
        int n;
        std::cin >> n;
        std::vector <int> a(n);
        for (int i = 0; i < n; ++ i){
            std::cin >> a[i];
        }
        if (n % 2 == 1){
            std::cout << "NO\n";
            return;
        }
        std::map <int, int> map;
        for (int i = 0; i < n; ++ i){
            ++ map[a[i]];
        }
        std::sort(a.begin(), a.end());
        for (auto [k, v]: map){
            if (v > n / 2){
                std::cout << "NO\n";
                return;
            }
            if (v == n / 2 && k != a.front() && k != a.back()){
                std::cout << "NO\n";
                return;
            }
        }
        std::vector <int> ans(n);
        for (int i = 0; i < n / 2; ++ i){
            ans[i * 2] = a[i];
            ans[i * 2 + 1] = a[i + n / 2];
        }
        std::cout << "YES\n";
        for (int i = 0; i < n; ++ i){
            std::cout << ans[i] << " \n"[i == n - 1];
        }
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