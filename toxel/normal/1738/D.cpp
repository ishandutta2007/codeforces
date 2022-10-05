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
        std::vector <int> b(n + 1);
        std::vector <std::vector <int>> vec(n + 2);
        for (int i = 1; i <= n; ++ i){
            std::cin >> b[i];
            vec[b[i]].emplace_back(i);
        }
        std::vector <int> repr;
        if (!vec[0].empty()){
            repr.emplace_back(0);
        }
        else{
            repr.emplace_back(n + 1);
        }
        while (true){
            int elem = repr.back();
            bool found = false;
            for (auto u: vec[elem]){
                if (!vec[u].empty()){
                    repr.emplace_back(u);
                    found = true;
                    break;
                }
            }
            if (!found){
                break;
            }
        }
        std::vector <int> ans;
        std::vector <int> bin[2];
        int cur = 0;
        for (auto u: repr){
            for (auto v: vec[u]){
                if (vec[v].empty()){
                    ans.emplace_back(v);
                }
            }
            for (auto v: vec[u]){
                if (!vec[v].empty()){
                    ans.emplace_back(v);
                }
            }
            for (auto v: vec[u]){
                bin[cur].emplace_back(v);
            }
            cur ^= 1;
        }
        for (int i = 0; i < 2; ++ i){
            std::sort(bin[i].begin(), bin[i].end());
        }
        int k;
        if (bin[0].empty() || bin[1].empty()){
            if (vec[0].empty()){
                k = n;
            }
            else{
                k = 0;
            }
        }
        else{
            if (bin[0] > bin[1]){
                std::swap(bin[0], bin[1]);
            }
            k = bin[0].back();
        }
        std::cout << k << '\n';
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