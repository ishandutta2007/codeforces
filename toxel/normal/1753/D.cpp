//
// Created by  on 2022/10/23.
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
    std::vector <std::string> s;
    int n, m;

    std::vector <std::vector <pll>> e;

    int encode(int i, int j){
        return i * m + j;
    }

    void add_edge(int i1, int j1, int i2, int j2, ll w){
        if (0 <= i2 && i2 < n && 0 <= j2 && j2 < m){
            if (s[i2][j2] != '#'){
                e[encode(i2, j2)].emplace_back(encode(i1, j1), w);
            }
        }
    }

    Solver(){}

    void solve(){
        std::cin >> n >> m;
        ll p, q;
        std::cin >> p >> q;
        s.resize(n);
        for (int i = 0; i < n; ++ i){
            std::cin >> s[i];
        }
        e.resize(n * m + 1);
        for (int i = 0; i < n; ++ i){
            for (int j = 0; j < m; ++ j){
                if (s[i][j] == 'L'){
                    add_edge(i, j + 1, i, j - 1, q);
                    add_edge(i, j, i, j + 2, q);
                    add_edge(i, j + 1, i - 1, j, p);
                    add_edge(i, j + 1, i + 1, j, p);
                    add_edge(i, j, i - 1, j + 1, p);
                    add_edge(i, j, i + 1, j + 1, p);
                }
                else if (s[i][j] == 'U'){
                    add_edge(i + 1, j, i - 1, j, q);
                    add_edge(i, j, i + 2, j, q);
                    add_edge(i + 1, j, i, j - 1, p);
                    add_edge(i + 1, j, i, j + 1, p);
                    add_edge(i, j, i + 1, j - 1, p);
                    add_edge(i, j, i + 1, j + 1, p);
                }
            }
        }
        const ll INF = 1e18;
        std::vector <ll> dis(n * m + 1, INF), vis(n * m + 1);
        for (int i = 0; i < n; ++ i){
            for (int j = 0; j < m; ++ j){
                if (s[i][j] == '.'){
                    dis[encode(i, j)] = 0;
                }
            }
        }
        std::priority_queue <pll> pq;
        for (int i = 0; i < n * m; ++ i){
            pq.emplace(-dis[i], i);
        }
        for (int i = 0; i < n * m; ++ i){
            int u = -1;
            while (!pq.empty()){
                auto [di, id] = pq.top();
                pq.pop();
                if (!vis[id]){
                    u = id;
                    break;
                }
            }
            for (auto [v, w]: e[u]){
                if (vis[v]){
                    continue;
                }
                ll value = dis[u] + w;
                if (value < dis[v]){
                    dis[v] = value;
                    pq.emplace(-dis[v], v);
                }
            }
        }
        ll ans = INF;
        for (int i = 0; i < n; ++ i){
            for (int j = 0; j < m - 1; ++ j){
                ll v1 = dis[encode(i, j)];
                ll v2 = dis[encode(i, j + 1)];
                if (v1 != INF && v2 != INF){
                    ans = std::min(ans, v1 + v2);
                }
            }
        }
        for (int i = 0; i < n - 1; ++ i){
            for (int j = 0; j < m; ++ j){
                ll v1 = dis[encode(i, j)];
                ll v2 = dis[encode(i + 1, j)];
                if (v1 != INF && v2 != INF){
                    ans = std::min(ans, v1 + v2);
                }
            }
        }
        if (ans == INF){
            std::cout << "-1\n";
            return;
        }
        std::cout << ans << '\n';
    }
};

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int test = 1;
    // std::cin >> test;
    // floating point number output template
    std::cout << std::fixed << std::setprecision(18);
    while (test --){
        Solver solver;
        solver.solve();
    }
    return 0;
}

#endif //WORKSPACE_TEMPLATE_H