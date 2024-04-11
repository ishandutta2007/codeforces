//
// Created by  on 2022/3/20.
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

const int BIT = 20;
std::vector <int> vec[BIT];

class Solver{
public:
    void solve(){
        int n;
        std::string s;
        std::cin >> n >> s;
        for (int i = 0; i < 1 << n; ++ i){
            vec[0].emplace_back(s[i] - 'a');
        }
        for (int i = 0; i < n; ++ i){
            vec[i + 1].resize(1 << n);
            std::vector <pii> tmp;
            for (int j = 0; j < 1 << n; j += 2){
                tmp.emplace_back(vec[i][j], vec[i][j + 1]);
                tmp.emplace_back(vec[i][j + 1], vec[i][j]);
            }
            std::sort(tmp.begin(), tmp.end());
            tmp.erase(std::unique(tmp.begin(), tmp.end()), tmp.end());
            for (int j = 0; j < 1 << i; ++ j){
                for (int k = 0; k < 2; ++ k){
                    for (int u = 0; u < 1 << (n - i); u += 2){
                        int pos1 = u + (j << (n - i)), pos2 = pos1 + 1;
                        vec[i + 1][(j << (n - i)) + u / 2] =
                                std::lower_bound(tmp.begin(), tmp.end(), mp(vec[i][pos1], vec[i][pos2])) - tmp.begin();
                        vec[i + 1][(j << (n - i)) + u / 2 + (1 << (n - i - 1))] =
                                std::lower_bound(tmp.begin(), tmp.end(), mp(vec[i][pos2], vec[i][pos1])) - tmp.begin();
                    }
                }
            }
        }
        int min_p = std::min_element(vec[n].begin(), vec[n].end()) - vec[n].begin();
        int tmp1 = min_p;
        min_p = 0;
        for (int i = 0; i < n; ++ i){
            min_p |= (tmp1 >> (n - 1 - i) & 1) << i;
        }
        for (int i = 0; i < 1 << n; ++ i){
            std::cout << s[i ^ min_p];
        }
        std::cout << '\n';
    }
};

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int test = 1;
    // std::cin >> test;
    while (test --){
        Solver solver;
        solver.solve();
    }
    // floating point number output template
    // std::cout << std::fixed << std::setprecision(18) << 1.0 << '\n';
    return 0;
}

#endif //WORKSPACE_TEMPLATE_H