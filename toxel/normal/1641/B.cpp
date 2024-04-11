//
// Created by  on 2022/2/23.
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

class Solver{
public:
    void solve(){
        int n;
        std::cin >> n;
        std::vector <int> a(n);
        std::map <int, int> cnt;
        for (int i = 0; i < n; ++ i){
            std::cin >> a[i];
            ++ cnt[a[i]];
        }
        for (auto [u, v]: cnt){
            if (v % 2 == 1){
                std::cout << "-1\n";
                return;
            }
        }
        std::vector <pii> ans1;
        std::vector <int> ans2;
        int prefix = 0;
        while (!a.empty()){
            int sz = a.size();
            std::set <int> vis;
            int pos = -1;
            for (int i = 0; i < sz; ++ i){
                if (vis.count(a[i])){
                    pos = i;
                    break;
                }
                vis.emplace(a[i]);
            }
            int pos1 = -1;
            for (int i = 0; i < pos; ++ i){
                if (a[i] == a[pos]){
                    pos1 = i;
                    break;
                }
            }
            if (pos1 != 0){
                for (int i = 0; i <= pos1; ++ i){
                    ans1.emplace_back(prefix + pos1 + 1 + i, a[i]);
                }
                prefix += 2 * (pos1 + 1);
                ans2.emplace_back(2 * (pos1 + 1));
                std::reverse(a.begin(), a.begin() + pos1 + 1);
            }
            if (pos > 1){
                for (int i = 1; i < pos; ++ i){
                    ans1.emplace_back(prefix + pos + i, a[i]);
                }
                prefix += pos * 2;
                ans2.emplace_back(2 * pos);
                std::reverse(a.begin() + 1, a.begin() + pos + 1);
            }
            else{
                ans2.emplace_back(2);
                prefix += 2;
            }
            a.erase(a.begin());
            a.erase(a.begin());
        }
        std::cout << ans1.size() << "\n";
        for (auto u : ans1){
            std::cout << u.first << " " << u.second << "\n";
        }
        int sz = ans2.size();
        std::cout << sz << "\n";
        for (int i = 0; i < sz; ++ i){
            std::cout << ans2[i] << " \n"[i == sz - 1];
        }
    }
};

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int test;
    std::cin >> test;
    while (test --){
        Solver solver;
        solver.solve();
    }
    return 0;
}

#endif //WORKSPACE_TEMPLATE_H