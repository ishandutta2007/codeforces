//
// Created by  on 2022/10/7.
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
    std::vector <std::vector <int>> e;
    void solve(){
        int n, m;
        std::cin >> n >> m;
        std::vector <int> u(m), v(m), w(m);
        e.resize(n + 1);
        for (int i = 0; i < m; ++ i){
            std::cin >> u[i] >> v[i] >> w[i];
            e[u[i]].emplace_back(v[i]);
            e[v[i]].emplace_back(u[i]);
        }
        std::vector <std::array <int, 501>> dis(n + 1);
        for (int i = 1; i <= n; ++ i){
            memset(&dis[i], -1, sizeof(dis[i][0]) * (n + 1));
            std::queue <int> queue;
            queue.emplace(i);
            dis[i][i] = 0;
            while (!queue.empty()){
                int u = queue.front();
                queue.pop();
                for (auto v: e[u]){
                    if (dis[i][v] != -1){
                        continue;
                    }
                    dis[i][v] = dis[i][u] + 1;
                    queue.emplace(v);
                }
            }
        }
        ll ans = LLONG_MAX;
        for (int i = 0; i < m; ++ i){
            int num = std::min(dis[1][u[i]] + dis[n][v[i]], dis[n][u[i]] + dis[1][v[i]]) + 1;
            ans = std::min(ans, 1ll * num * w[i]);
            for (int j = 1; j <= n; ++ j){
                num = std::min(dis[j][u[i]], dis[j][v[i]]) + 1 + dis[1][j] + dis[n][j] + 1;
                ans = std::min(ans, 1ll * num * w[i]);
            }
        }
        std::cout << ans << '\n';
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