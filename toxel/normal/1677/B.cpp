//
// Created by  on 2022/5/8.
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
        std::string str;
        std::cin >> str;
        std::vector <int> pre(n * m + 1), have1(m + 1);
        for (int i = 0; i < n * m; ++ i){
            pre[i + 1] = pre[i] + (str[i] == '1');
        }
        std::vector <int> ans(n * m + 10), ans1(n * m + 10);
        for (int r = 1; r <= n * m; ++ r){
            int pos = r - m;
            int have = pre[r] - (pos < 0 ? 0 : pre[pos]);
            if (have){
                ++ ans[r];
            }
            if (str[r - 1] == '1'){
                ++ have1[r % m];
            }
            if (have1[r % m]){
                ++ ans1[r];
                pos = r + m;
                if (pos <= n * m){
                    -- ans1[pos];
                }
            }
        }
        for (int i = 1; i <= n * m; ++ i){
            ans1[i] += ans1[i - 1];
        }
        for (int i = m; i <= n * m; ++ i){
            ans[i] += ans[i - m];
        }
        for (int i = 1; i <= n * m; ++ i){
            std::cout << ans[i] + ans1[i] << " \n"[i == n * m];
        }
    }
};

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int test;
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