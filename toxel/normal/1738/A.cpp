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
        int n;
        std::cin >> n;
        std::vector <int> a(n), b(n);
        for (int i = 0; i < n; ++ i){
            std::cin >> a[i];
        }
        for (int i = 0; i < n; ++ i){
            std::cin >> b[i];
        }
        std::vector <int> vec[2];
        for (int i = 0; i < n; ++ i){
            vec[a[i]].emplace_back(b[i]);
        }
        for (int i = 0; i < 2; ++ i){
            std::sort(vec[i].begin(), vec[i].end(), std::greater<>());
        }
        int sz0 = vec[0].size(), sz1 = vec[1].size();
        ll ans = 0;
        if (sz0 == sz1){
            for (int i = 0; i < sz0; ++ i){
                ans += vec[0][i] + vec[1][i];
            }
            ans *= 2;
            ans -= std::min(vec[0].back(), vec[1].back());
        }
        else{
            for (int i = 0; i < std::min(sz0, sz1); ++ i){
                ans += vec[0][i] + vec[1][i];
            }
            ans *= 2;
            for (int i = std::min(sz0, sz1); i < sz0; ++ i){
                ans += vec[0][i];
            }
            for (int i = std::min(sz0, sz1); i < sz1; ++ i){
                ans += vec[1][i];
            }
        }
        std::cout << ans << '\n';
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