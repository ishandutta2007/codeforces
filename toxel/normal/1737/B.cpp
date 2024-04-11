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
    ll count(ll n, ll add){
        ll l = 0, r = 1.01e9;
        while (l < r){
            ll mid = (l + r + 1) / 2;
            if (mid * (mid + add) <= n){
                l = mid;
            }
            else{
                r = mid - 1;
            }
        }
        return l;
    }

    ll count(ll n){
        return count(n, 0) + count(n, 1) + count(n, 2);
    }

    void solve(){
        ll l, r;
        std::cin >> l >> r;
        std::cout << count(r) - count(l - 1) << '\n';
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