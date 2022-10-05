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
        int n, k;
        std::cin >> n >> k;
        std::vector <ll> s(n + 1), a(n + 1);
        for (int i = n - k + 1; i <= n; ++ i){
            std::cin >> s[i];
        }
        if (k == 1){
            std::cout << "Yes\n";
            return;
        }
        for (int i = n - k + 2; i <= n; ++ i){
            a[i] = s[i] - s[i - 1];
        }
        for (int i = n - k + 2; i < n; ++ i){
            if (a[i] > a[i + 1]){
                std::cout << "No\n";
                return;
            }
        }
        std::cout << (a[n - k + 2] * (n - k + 1) >= s[n - k + 1] ? "Yes\n" : "No\n");
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