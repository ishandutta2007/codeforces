//
// Created by  on 2022/10/7.
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
        int n;
        std::cin >> n;
        int r[3], c[3];
        for (int i = 0; i < 3; ++ i){
            std::cin >> r[i] >> c[i];
        }
        int x, y;
        std::cin >> x >> y;
        int mid_x = r[0] ^ r[1] ^ r[2], mid_y = c[0] ^ c[1] ^ c[2];
        for (int i = 0; i < 3; ++ i){
            if (mid_x != r[i]){
                mid_x = r[i];
                break;
            }
        }
        for (int i = 0; i < 3; ++ i){
            if (mid_y != c[i]){
                mid_y = c[i];
                break;
            }
        }
        if ((mid_x == 1 || mid_x == n) && (mid_y == 1 || mid_y == n)){
            std::cout << (x == mid_x || y == mid_y ? "YES" : "NO") << '\n';
            return;
        }
        for (int i = 0; i < 3; ++ i){
            if (r[i] % 2 == x % 2 && c[i] % 2 == y % 2){
                std::cout << "YES\n";
                return;
            }
        }
        std::cout << "NO\n";
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