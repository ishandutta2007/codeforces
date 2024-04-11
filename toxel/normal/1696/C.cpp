//
// Created by  on 2022/6/25.
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
    std::vector <pll> solve(const std::vector <int> &a, int m){
        std::vector <pll> stack;
        int n = a.size();
        for (int i = 0; i < n; ++ i){
            int x = a[i], cnt = 1;
            while (x % m == 0){
                x /= m;
                cnt *= m;
            }
            if (!stack.empty() && stack.back().first == x){
                stack.back().second += cnt;
            }
            else{
                stack.emplace_back(x, cnt);
            }
        }
        return stack;
    }

    void solve(){
        int n, m;
        std::cin >> n >> m;
        std::vector <int> a(n);
        for (int i = 0; i < n; ++ i){
            std::cin >> a[i];
        }
        auto vec1 = solve(a, m);
        int k;
        std::cin >> k;
        std::vector <int> b(k);
        for (int i = 0; i < k; ++ i){
            std::cin >> b[i];
        }
        auto vec2 = solve(b, m);
        std::cout << (vec1 == vec2 ? "Yes\n" : "No\n");
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