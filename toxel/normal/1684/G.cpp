//
// Created by  on 2022/5/20.
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
// using Mint = Mod<int, UNDEFINED>;

// <TeX>
// $O(\sqrt{V}E)$
// </TeX>

const int MAXN = 5010;

namespace HK {
    int match[MAXN], d[MAXN], dis;
    bool vis[MAXN];
    std::vector<int> vec[MAXN], left;
    bool bfs() {
        std::queue<int> q; dis = INT_MAX;
        memset(d, -1, sizeof(d));
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
        memset(match, -1, sizeof(match));
        int ret = 0;
        while (bfs()) {
            memset(vis, 0, sizeof(vis));
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

class Solver{
public:
    std::vector <int> list;

    int gcd(int u, int v){
        if (u < v){
            std::swap(u, v);
        }
        if (v == 0){
            return v;
        }
        int r = u % v;
        if (r > 0){
            list.emplace_back(r);
        }
        return gcd(v, r);
    }

    void solve(){
        int n, m;
        std::cin >> n >> m;
        std::vector <int> p(n + 1), type(n + 1);
        for (int i = 1; i <= n; ++ i){
            std::cin >> p[i];
            if (3ll * p[i] <= m){
                type[i] = 0;
            }
            else{
                type[i] = 1;
            }
        }
        for (int i = 1; i <= n; ++ i){
            for (int j = 1; j <= n; ++ j){
                if (type[i] == 1 && type[j] == 0 && 2ll * p[i] + p[j] <= m && p[i] % p[j] == 0){
                    HK::addedge(i, j);
                    // std::cerr << i << " " << j << '\n';
                }
            }
            if (type[i] == 1){
                HK::left.emplace_back(i);
            }
        }
        HK::hk();
        for (int i = 1; i <= n; ++ i){
            if (type[i] == 1 && HK::match[i] == -1){
                std::cout << "-1\n";
                return;
            }
        }
        std::vector <pii> ans;
        for (int i = 1; i <= n; ++ i){
            int j = HK::match[i];
            if (type[i] == 1){
                ans.emplace_back(2 * p[i] + p[j], p[i] + p[j]);
            }
            else{
                if (j == -1){
                    ans.emplace_back(3 * p[i], 2 * p[i]);
                }
            }
        }
        std::sort(ans.begin(), ans.end());
        std::cout << ans.size() << '\n';
        for (auto [u, v]: ans){
            std::cout << u << " " << v << '\n';
        }
        std::sort(p.begin(), p.end());
        for (auto [u, v]: ans){
            gcd(u, v);
        }
        list.emplace_back(0);
        std::sort(list.begin(), list.end());
        assert(p == list);
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