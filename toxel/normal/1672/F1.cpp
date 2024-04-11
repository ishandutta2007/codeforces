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
    void solve(){
        int n;
        std::cin >> n;
        std::vector <int> a(n), cnt(n + 1);
        for (int i = 0; i < n; ++ i){
            std::cin >> a[i];
            ++ cnt[a[i]];
        }
        std::vector <pii> p(n);
        for (int i = 0; i < n; ++ i){
            p[i] = {a[i], i};
        }
        std::sort(p.begin(), p.end(), [&](const pii &p1, const pii &p2){
            return pii{cnt[p1.first], p1.first} < pii{cnt[p2.first], p2.first};
        });
        std::vector <int> ans(n);
        int most = cnt[p.back().first];
        for (int i = 0; i < n; ++ i){
            ans[p[i].second] = p[(i + most) % n].first;
        }
        for (int i = 0; i < n; ++ i){
            std::cout << ans[i] << " \n"[i == n - 1];
        }
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