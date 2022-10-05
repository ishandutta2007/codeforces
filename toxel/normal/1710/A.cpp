//
// Created by  on 2022/7/24.
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
    std::vector <int> a;

    bool check(int n, int m){
        int k = a.size();
        int max = std::min(k, n / 2);
        std::vector <int> b;
        for (int i = 0; i < k; ++ i){
            int x = a[i] / m;
            b.emplace_back(x == 1 ? 0 : x);
        }
        std::sort(b.begin(), b.end(), std::greater<>());
        ll sum = 0;
        for (int i = 0; i < max; ++ i){
            sum += b[i];
        }
        return sum >= n;
    }

    void solve(){
        int n, m, k;
        std::cin >> n >> m >> k;
        a.resize(k);
        for (int i = 0; i < k; ++ i){
            std::cin >> a[i];
        }
        std::cout << (check(n, m) || check(m, n) ? "Yes\n" : "No\n");
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