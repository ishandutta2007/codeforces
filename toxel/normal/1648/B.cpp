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

class Solver{
public:
    void solve(){
        int n, c;
        std::cin >> n >> c;
        std::vector <int> a(n + 1), pre(c + 1);
        for (int i = 1; i <= n; ++ i){
            std::cin >> a[i];
            ++ pre[a[i]];
        }
        for (int i = 1; i <= c; ++ i){
            pre[i] += pre[i - 1];
        }
        for (int i = 1; i <= c; ++ i){
            if (pre[i] > pre[i - 1]){
                for (int j = i; j <= c; j += i){
                    int up = std::min(j + i - 1, c);
                    int pos = j / i;
                    if (pre[up] - pre[j - 1] > 0 && pre[pos] == pre[pos - 1]){
                        std::cout << "No\n";
                        return;
                    }
                }
            }
        }
        std::cout << "Yes\n";
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
    // floating point number output template
    // std::cout << std::fixed << std::setprecision(18) << 1.0 << '\n';
    return 0;
}

#endif //WORKSPACE_TEMPLATE_H