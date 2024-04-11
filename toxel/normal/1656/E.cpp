//
// Created by  on 2022/3/24.
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

const int N = 100010;

std::vector <int> e[N];
int col[N];

void dfs(int u, int fa){
    for (auto v : e[u]){
        if (v == fa){
            continue;
        }
        col[v] = col[u] ^ 1;
        dfs(v, u);
    }
}

class Solver{
public:
    void solve(){
        int n;
        std::cin >> n;
        for (int i = 1; i <= n; ++ i){
            e[i].clear();
        }
        for (int i = 0; i < n - 1; ++ i){
            int u, v;
            std::cin >> u >> v;
            e[u].emplace_back(v);
            e[v].emplace_back(u);
        }
        col[1] = 0;
        dfs(1, 0);
        for (int i = 1; i <= n; ++ i){
            std::cout << (col[i] ? -int(e[i].size()) : int(e[i].size())) << " \n"[i == n];
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
    // std::cout << std::fixed << std::setprecision(18) << 1.0 << '\n';
    return 0;
}

#endif //WORKSPACE_TEMPLATE_H