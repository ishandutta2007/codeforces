//
// Created by  on 2022/7/16.
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
        int n, q;
        std::cin >> n >> q;
        std::vector <int> a(n + 1);
        for (int i = 1; i <= n; ++ i){
            std::cin >> a[i];
        }
        int l = 1, r = n + 1;
        while (l < r){
            int mid = (l + r) / 2;
            int start = q;
            bool flag = true;
            for (int i = mid; i <= n; ++ i){
                if (start == 0){
                    flag = false;
                    break;
                }
                if (a[i] > start){
                    -- start;
                }
            }
            if (flag){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        for (int i = 1; i <= n; ++ i){
            if (i < l){
                if (a[i] <= q){
                    std::cout << '1';
                }
                else{
                    std::cout << '0';
                }
            }
            else{
                std::cout << '1';
                if (a[i] > q){
                    -- q;
                }
            }
        }
        std::cout << '\n';
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