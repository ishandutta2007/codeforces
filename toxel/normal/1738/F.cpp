//
// Created by  on 2022/10/1.
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
    int ask(int u){
        std::cout << "? " << u << '\n';
        std::cout.flush();
        int result;
        std::cin >> result;
        return result;
    }

    void solve(){
        int n;
        std::cin >> n;
        std::vector <int> d(n + 1);
        for (int i = 1; i <= n; ++ i){
            std::cin >> d[i];
        }
        std::vector <int> id(n);
        for (int i = 0; i < n; ++ i){
            id[i] = i + 1;
        }
        std::sort(id.begin(), id.end(), [&](const int &p1, const int &p2){return d[p1] > d[p2];});
        std::vector <std::vector <int>> e(n + 1);
        std::vector <int> vis(n + 1);
        for (auto u: id){
            if (vis[u]){
                continue;
            }
            vis[u] = 1;
            for (int i = 0; i < d[u]; ++ i){
                int v = ask(u);
                e[u].emplace_back(v);
                e[v].emplace_back(u);
                if (vis[v]){
                    break;
                }
                vis[v] = 1;
            }
        }
        std::fill(vis.begin(), vis.end(), 0);
        std::vector <int> c(n + 1);
        std::function <void(int, int)> dfs = [&](int u, int col){
            if (vis[u]){
                return;
            }
            vis[u] = 1;
            c[u] = col;
            for (auto v: e[u]){
                dfs(v, col);
            }
        };
        int cnt = 0;
        for (int i = 1; i <= n; ++ i){
            if (!vis[i]){
                ++ cnt;
                dfs(i, cnt);
            }
        }
        std::cout << "!";
        for (int i = 1; i <= n; ++ i){
            std::cout << " " << c[i];
        }
        std::cout << '\n';
        std::cout.flush();
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