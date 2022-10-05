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

const int N = 200010;

std::vector <int> e[N];

class Solver{
public:
    std::vector <int> topo, vis, inv;

    void dfs(int u){
        vis[u] = 1;
        for (auto v : e[u]){
            if (!vis[v]){
                dfs(v);
            }
        }
        topo.emplace_back(u);
        inv[u] = int(topo.size());
    }
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
        int most = p.back().first;
        std::vector <int> b(n);
        for (int i = 0; i < n; ++ i){
            std::cin >> b[i];
        }
        for (int i = 0; i <= n; ++ i){
            e[i].clear();
        }
        for (int i = 0; i < n; ++ i){
            if (a[i] == most || b[i] == most){
                continue;
            }
            e[a[i]].emplace_back(b[i]);
        }
        vis.resize(n + 1);
        inv.resize(n + 1);
        for (int i = 1; i <= n; ++ i){
            if (!vis[i]){
                dfs(i);
            }
        }
        for (int i = 1; i <= n; ++ i){
            for (auto v : e[i]){
                if (inv[v] >= inv[i]){
                    std::cout << "WA\n";
                    return;
                }
            }
        }
        std::cout << "AC\n";
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