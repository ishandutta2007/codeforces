//
// Created by  on 2022/6/3.
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
    int ask(const std::string &str){
        std::cout << "? " << str << '\n';
        std::cout.flush();
        int ans;
        std::cin >> ans;
        return ans;
    }

    void solve(){
        int n, m;
        std::cin >> n >> m;
        std::vector <int> weight;
        std::vector <pii> p;
        for (int i = 0; i < m; ++ i){
            std::string s;
            for (int j = 0; j < m; ++ j){
                s.push_back(j == i ? '1' : '0');
            }
            int w = ask(s);
            weight.emplace_back(w);
            p.emplace_back(w, i);
        }
        std::sort(p.begin(), p.end());
        int cur = 0;
        int ans = 0;
        for (int i = 0; i < m; ++ i){
            std::string s;
            for (int j = 0; j < m; ++ j){
                s.push_back('0');
            }
            for (int j = 0; j <= i; ++ j){
                s[p[j].second] = '1';
            }
            int w = ask(s);
            if (w - cur == p[i].first){
                ans += p[i].first;
            }
            cur = w;
        }
        std::cout << "! " << ans << '\n';
    }
};

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int test = 1;
    // std::cin >> test;
    // floating point number output template
    std::cout << std::fixed << std::setprecision(18);
    while (test --){
        Solver solver;
        solver.solve();
    }
    return 0;
}

#endif //WORKSPACE_TEMPLATE_H