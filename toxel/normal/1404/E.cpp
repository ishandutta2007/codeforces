//
// Created by  on 2022/2/25.
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

const int MAXN = 80010;

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
}

const int N = 210;

char s[N][N];

class Solver{
public:
    std::map <piiii, int> map;

    int get_id(pii p1, pii p2){
        if (p1.first > p2.first){
            std::swap(p1, p2);
        }
        else if (p1.second > p2.second){
            std::swap(p1, p2);
        }
        piiii p = {p1.first, p1.second, p2.first, p2.second};
        if (map.count(p)){
            return map[p];
        }
        int x = map.size();
        return map[p] = x + 1;
    }

    void solve(){
        int n, m;
        std::cin >> n >> m;
        for (int i = 1; i <= n; ++ i){
            std::cin >> (s[i] + 1);
        }
        const int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        std::set <int> left;
        int cnt1 = 0, cnt2 = 0;
        for (int i = 1; i <= n; ++ i){
            for (int j = 1; j <= m; ++ j){
                if (s[i][j] != '#'){
                    continue;
                }
                ++ cnt1;
                if (s[i + 1][j] == '#'){
                    ++ cnt2;
                }
                if (s[i][j + 1] == '#'){
                    ++ cnt2;
                }
                for (int k = 0; k < 4; ++ k){
                    int x1 = i + dir[k][0], y1 = j + dir[k][1];
                    int x2 = i + dir[(k + 1) % 4][0], y2 = j + dir[(k + 1) % 4][1];
                    if (s[x1][y1] != '#' || s[x2][y2] != '#'){
                        continue;
                    }
                    int id1 = get_id({i, j}, {x1, y1});
                    int id2 = get_id({i, j}, {x2, y2});
                    HK::vec[id1].emplace_back(id2);
                    HK::vec[id2].emplace_back(id1);
                    if (i == x1){
                        left.emplace(id1);
                    }
                    if (i == x2){
                        left.emplace(id2);
                    }
                }
            }
        }
        for (auto u : left){
            HK::left.emplace_back(u);
        }
        int match = HK::hk();
        std::cout << cnt1 - (cnt2 - match) << "\n";
    }
};

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int test = 1;
    // std::cin >> test;
    while (test --){
        Solver solver;
        solver.solve();
    }
    return 0;
}

#endif //WORKSPACE_TEMPLATE_H