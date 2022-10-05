//
// Created by  on 2022/4/23.
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
    std::vector <int> get(int n){
        std::vector <int> a(n), vis(n + 1);
        for (int i = 0; i < n; ++ i){
            std::cin >> a[i];
        }
        return a;
    }

    void solve(){
        int n;
        std::cin >> n;
        auto v1 = get(n);
        auto v2 = get(n);
        std::vector <int> need(n + 1);
        for (int i = n - 1, j = n - 1; i >= 0; -- i){
            if (i == n - 1 || v2[i] != v2[i + 1]){
                while (j >= 0 && v1[j] != v2[i]){
                    if (need[v1[j]] == 0){
                        std::cout << "No\n";
                        return;
                    }
                    -- need[v1[j]];
                    -- j;
                }
                if (j < 0){
                    std::cout << "No\n";
                    return;
                }
                -- j;
            }
            else{
                ++ need[v2[i]];
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
    std::cout << std::fixed << std::setprecision(18) << '\n';
    return 0;
}

#endif //WORKSPACE_TEMPLATE_H