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
using ull = unsigned long long;

class Solver{
public:
    void solve(){
        int n, m;
        std::cin >> n >> m;
        std::vector <ull> vec;
        for (int i = 0; i < n; ++ i){
            ull pre = 0, tot = 0;
            for (int j = 0; j < m; ++ j){
                ull x;
                std::cin >> x;
                pre += x;
                tot += pre;
            }
            vec.emplace_back(tot);
        }
        int cnt = 0, pos = 0;
        for (int i = 1; i < n; ++ i){
            if (vec[0] != vec[i]){
                ++ cnt;
                pos = i;
            }
        }
        if (cnt == n - 1){
            std::cout << "1 " << vec[1] - vec[0] << '\n';
        }
        else{
            std::cout << pos + 1 << " " << vec[0] - vec[pos] << '\n';
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