//
// Created by  on 2022/3/2.
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
        std::vector <std::vector <int>> e(n + 1);
        std::vector <int> c(n + 1), deg(n + 1);
        for (int i = 1; i <= n; ++ i){
            std::cin >> c[i];
        }
        for (int i = 0, u, v; i < n - 1; ++ i){
            std::cin >> u >> v;
            ++ deg[u], ++ deg[v];
            e[u].emplace_back(v);
            e[v].emplace_back(u);
        }
        if (n == 1){
            std::cout << "1\n";
            return;
        }
        int min = INT_MAX;
        for (int start = 0; start < 2; ++ start){
            auto deg_copy = deg;
            std::queue <int> q[3];
            std::vector <int> vis(n + 1);
            for (int i = 1; i <= n; ++ i){
                if (deg_copy[i] == 1){
                    q[c[i]].emplace(i);
                    deg_copy[i] = -1;
                }
            }
            int cur = start, ans = 0;
            while (!q[0].empty() || !q[1].empty() || !q[2].empty()){
                ++ ans;
                int ids[2] = {0, cur + 1};
                for ( ; !q[ids[0]].empty() || !q[ids[1]].empty(); ){
                    int u;
                    if (!q[ids[0]].empty()){
                        u = q[ids[0]].front();
                        q[ids[0]].pop();
                    }
                    else{
                        u = q[ids[1]].front();
                        q[ids[1]].pop();
                    }
                    for (auto v : e[u]){
                        -- deg_copy[v];
                        if (deg_copy[v] == 1){
                            q[c[v]].emplace(v);
                            deg_copy[v] = -1;
                        }
                    }
                }
                cur ^= 1;
            }
            min = std::min(min, ans);
        }
        std::cout << min << '\n';
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