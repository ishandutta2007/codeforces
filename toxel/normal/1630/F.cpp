//
// Created by  on 2022/2/26.
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

const int MAXN = 200010;

namespace HK {
    int match[MAXN], d[MAXN], dis;
    bool vis[MAXN];
    std::vector<int> vec[MAXN], left;
    int n;

    void clear(){
        memset(match, 0, sizeof(match[0]) * (n + 1));
        memset(d, 0, sizeof(d[0]) * (n + 1));
        dis = 0;
        memset(vis, 0, sizeof(vis[0]) * (n + 1));
        for (int i = 0; i <= n; ++ i){
            vec[i].clear();
        }
        left.clear();
    }

    bool bfs() {
        std::queue<int> q; dis = INT_MAX;
        memset(d, -1, sizeof(d[0]) * (n + 1));
        for (auto u : left)
            if (match[u] == -1) {d[u] = 0; q.push(u);}
        while (!q.empty()) {
            int u = q.front(); q.pop();
            if (d[u] > dis) break;
            for (auto v : vec[u]) {
                if (d[v] != -1) continue;
                d[v] = d[u] + 1;
                if (match[v] == -1) dis = d[v];
                else {
                    d[match[v]] = d[v] + 1; q.push(match[v]);
                }}}
        return dis != INT_MAX;
    }
    bool dfs(int u) {
        for (auto v : vec[u])
            if (!vis[v] && d[v] == d[u] + 1) {
                vis[v] = true;
                if (match[v] != -1 && d[v] == dis) continue;
                if (match[v] == -1 || dfs(match[v])) {
                    match[v] = u; match[u] = v;
                    return true;
                }
            }
        return false;
    }
    int hk() {
        memset(match, -1, sizeof(match[0]) * (n + 1));
        int ret = 0;
        while (bfs()) {
            memset(vis, 0, sizeof(vis[0]) * (n + 1));
            for (auto u : left)
                if (match[u] == -1 && dfs(u)) ++ret;
        }
        return ret;
    }
    void addedge(int u, int v){
        vec[u].emplace_back(v);
        vec[v].emplace_back(u);
    }
}

int inv[MAXN], a[MAXN];

class Solver{
public:
    void solve(){
        int n;
        std::cin >> n;
        HK::n = 4 * n + 5;
        const int SQRT = 230;
        for (int i = 1; i <= n; ++ i){
            std::cin >> a[i];
            inv[a[i]] = i;
        }
        for (int i = 1; i <= n; ++ i){
            if (a[i] <= SQRT){
                for (int j = 1; j <= n; ++ j){
                    if (a[j] > a[i] && a[j] % a[i] == 0){
                        HK::addedge(i, j + 2 * n);
                        HK::addedge(i + n, j + 3 * n);
                        HK::addedge(i, j + 3 * n);
                    }
                }
            }
            else{
                for (int j = 2 * a[i]; j <= 50'000; j += a[i]){
                    if (inv[j]){
                        int x = inv[j];
                        HK::addedge(i, x + 2 * n);
                        HK::addedge(i + n, x + 3 * n);
                        HK::addedge(i, x + 3 * n);
                    }
                }
            }
            HK::addedge(i, i + 3 * n);
            HK::left.emplace_back(i);
            HK::left.emplace_back(i + n);
        }
        int antichain = 2 * n - HK::hk();
        std::cout << n - antichain << '\n';
        for (int i = 1; i <= n; ++ i){
            inv[a[i]] = 0;
        }
        HK::clear();
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