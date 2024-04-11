//
// Created by  on 2022/3/6.
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

const int N = 100010;
std::vector <int> e1[N], e2[N];

class Solver{
public:
    ll calc(std::vector <int> *e){
        ll ans = 0;
        for (int i = 0; i < N; ++ i){
            if (e[i].empty()){
                continue;
            }
            std::sort(e[i].begin(), e[i].end());
            int sz = e[i].size();
            for (int j = 0; j < sz; ++ j){
                ans += 1ll * e[i][j] * (2 * j - (sz - 1));
            }
        }
        return ans;
    }

    void solve(){
        int n, m;
        std::cin >> n >> m;
        for (int i = 0; i < n; ++ i){
            for (int j = 0; j < m; ++ j){
                int col;
                std::cin >> col;
                e1[col].emplace_back(i);
                e2[col].emplace_back(j);
            }
        }
        std::cout << calc(e1) + calc(e2) << '\n';
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