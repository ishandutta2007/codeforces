//
// Created by  on 2022/9/6.
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

const int N = 200010;

std::vector <pii> e[N];

class Solver{
public:
    std::vector <int> ans, vis, fa, dep;

    void dfs(int u, int pa){
        vis[u] = 1;
        for (auto [v, id]: e[u]){
            if (vis[v]){
                continue;
            }
            dep[v] = dep[u] + 1;
            ans[id] = 1;
            fa[v] = pa;
            dfs(v, id);
        }
    }

    void solve(){
        int n, m;
        std::cin >> n >> m;
        for (int i = 0; i <= n; ++ i){
            e[i].clear();
        }
        std::vector <int> u(m), v(m);
        for (int i = 0; i < m; ++ i){
            std::cin >> u[i] >> v[i];
            e[u[i]].emplace_back(v[i], i);
            e[v[i]].emplace_back(u[i], i);
        }
        ans.resize(m);
        vis.resize(n + 1);
        fa.resize(n + 1);
        dep.resize(n + 1);
        dfs(1, 0);
        std::vector <int> tmp;
        for (int i = 0; i < m; ++ i){
            if (ans[i] == 0){
                tmp.emplace_back(u[i]);
                tmp.emplace_back(v[i]);
            }
        }
        if (tmp.size() == 6){
            std::sort(tmp.begin(), tmp.end());
            if (tmp[0] == tmp[1] && tmp[2] == tmp[3] && tmp[4] == tmp[5]){
                for (int i = 0; i < m; ++ i){
                    if (ans[i] == 0){
                        if (dep[u[i]] < dep[v[i]]){
                            std::swap(u[i], v[i]);
                        }
                        std::swap(ans[i], ans[fa[u[i]]]);
                        break;
                    }
                }
            }
        }
        for (int i = 0; i < m; ++ i){
            std::cout << ans[i];
        }
        std::cout << '\n';
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