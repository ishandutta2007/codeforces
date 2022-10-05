//
// Created by  on 2022/3/20.
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
        std::vector <ll> a(n);
        ll sum = 0;
        std::multiset <ll> set;
        for (int i = 0; i < n; ++ i){
            std::cin >> a[i];
            sum += a[i];
            set.emplace(a[i]);
        }
        std::queue <ll> q;
        q.emplace(sum);
        while (!q.empty()){
            if (q.size() > set.size()){
                std::cout << "NO\n";
                return;
            }
            ll u = q.front();
            q.pop();
            auto v = set.find(u);
            if (v == set.end()){
                if (u == 1){
                    std::cout << "NO\n";
                    return;
                }
                q.emplace(u / 2);
                q.emplace((u + 1) / 2);
                continue;
            }
            set.erase(v);
        }
        std::cout << (set.empty() ? "YES" : "NO") << "\n";
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