//
// Created by  on 2022/4/19.
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
        int n;
        std::cin >> n;
        std::vector <int> a(n);
        for (int i = 0; i < n; ++ i){
            std::cin >> a[i];
        }
        ll ans = LLONG_MAX;
        for (int i = 0; i <= n; ++ i){
            ll cur = -1, sum = 0;
            for (int j = i; j < n; ++ j){
                ll n_cur = cur / a[j] * a[j];
                while (n_cur <= cur){
                    n_cur += a[j];
                }
                sum += n_cur / a[j];
                cur = n_cur;
            }
            cur = 0;
            for (int j = i - 1; j >= 0; -- j){
                ll n_cur = -(-cur / a[j]) * a[j];
                while (n_cur >= cur){
                    n_cur -= a[j];
                }
                sum += -n_cur / a[j];
                cur = n_cur;
            }
            ans = std::min(ans, sum);
        }
        std::cout << ans << '\n';
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