//
// Created by  on 2022/5/19.
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
        int n, m;
        std::cin >> n >> m;
        bool flag = true;
        pii ans = {-1, -1};
        std::vector <std::vector <int>> vec(n);
        for (int i = 0; i < n; ++ i){
            vec[i].resize(m);
            for (int j = 0; j < m; ++ j){
                std::cin >> vec[i][j];
            }
        }
        for (int i = 0; i < n; ++ i){
            std::vector <int> vec1 = vec[i], bad;
            std::sort(vec1.begin(), vec1.end());
            for (int j = 0; j < m; ++ j){
                if (vec[i][j] != vec1[j]){
                    bad.emplace_back(j);
                }
            }
            if (bad.empty()){
                continue;
            }
            int sz = bad.size();
            if (sz >= 3){
                std::cout << "-1\n";
                return;
            }
            else{
                ans = {bad[0], bad[1]};
            }
        }
        if (ans.first == -1){
            std::cout << "1 1\n";
        }
        else{
            for (int i = 0; i < n; ++ i){
                std::swap(vec[i][ans.first], vec[i][ans.second]);
                for (int j = 0; j < m - 1; ++ j){
                    if (vec[i][j] > vec[i][j + 1]){
                        std::cout << "-1\n";
                        return;
                    }
                }
            }
            std::cout << ans.first + 1 << " " << ans.second + 1 << '\n';
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