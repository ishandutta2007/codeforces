//
// Created by  on 2022/4/24.
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
        int n, q;
        std::string s;
        std::cin >> n >> q >> s;
        std::vector <int> pre[2];
        pre[0].resize(n + 1);
        pre[1].resize(n + 1);
        for (int i = 2; i <= n; ++ i){
            pre[0][i] = pre[0][i - 1];
            pre[1][i] = pre[1][i - 1];
            if (s[i - 1] == s[i - 2]){
                ++ pre[s[i - 1] - '0'][i];
            }
        }
        while (q --){
            int l, r;
            std::cin >> l >> r;
            std::cout << std::max(pre[0][r] - pre[0][l], pre[1][r] - pre[1][l]) + 1 << '\n';
        }
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
    std::cout << std::fixed << std::setprecision(18) << '\n';
    return 0;
}

#endif //WORKSPACE_TEMPLATE_H