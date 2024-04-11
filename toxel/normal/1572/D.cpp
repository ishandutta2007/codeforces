//
// Created by  on 2022/3/5.
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

// <TeX>
// Min cost feasible flow or max flow. modified to long long: inf, dis[], sum, cost, memset(dis, inf)*2, edge.w, addedge(w)
// </TeX>
const int max_N = 100010;
const int INF = 3e6;

namespace primal_dual {
    const int inf = 0x3f3f3f3f; // larger than all dis
    int M, dis[max_N], vis[max_N], sum, flow, cost;
    struct edge {
        int v, c, w; //vertex, capacity, weight
    };
    std::vector<edge> e; //all edges
    std::vector<int> vec[max_N]; // edge indexes
    int ans = 0;
    void adjust(int s) {
        for (int it = 0; it < M; it += 2) {
            int u = e[it ^ 1].v, v = e[it].v;
            e[it].w += dis[v] - dis[u];
            e[it ^ 1].w += dis[u] - dis[v];
        }
        sum += dis[s];
    }
    void spfa(int n, int s, int t) {
        static int Q[max_N];
        int head = 0, tail = 0;
        memset(dis + 1, 0x3f, n * sizeof(int));
        memset(vis + 1, 0, n * sizeof(int));
        dis[t] = 0, vis[t] = 1, Q[tail++] = t;
        while (head != tail) {
            int u = Q[head++]; vis[u] = 0;
            if (head == max_N) head = 0;
            for (auto it : vec[u]) {
                if (!e[it ^ 1].c) continue;
                int v = e[it].v;
                auto tmp = dis[u] + e[it ^ 1].w;
                if (dis[v] > tmp) {
                    dis[v] = tmp;
                    if (!vis[v]) {
                        vis[v] = 1, Q[tail++] = v;
                        if (tail == max_N) tail = 0;
                    }}}}
        if (dis[s] == inf) return;
        adjust(s);
    }
    bool dijkstra(int n, int s, int t) {
        std::priority_queue<std::pair<int, int>> pq;
        memset(dis + 1, 0x3f, n * sizeof(int));
        memset(vis + 1, 0, n * sizeof(int));
        dis[t] = 0, pq.push({0, t});
        while (!pq.empty()) {
            int u = pq.top().second; pq.pop();
            if (vis[u]) continue;
            vis[u] = 1;
            for (auto it : vec[u]) {
                if (!e[it ^ 1].c) continue;
                int v = e[it].v;
                auto tmp = dis[u] + e[it ^ 1].w;
                if (dis[v] > tmp) {
                    dis[v] = tmp; pq.push({-dis[v], v});
                }
            }
        }
        if (!vis[s]) return false;
        return adjust(s), true;
    }
    int dfs(int t, int u, int a) {
        if (u == t) return a;
        vis[u] = 1;
        int ret = 0, tmp;
        for (auto it : vec[u]) {
            int v = e[it].v;
            if (e[it].w || vis[v] || !e[it].c) continue;
            tmp = dfs(t, v, std::min(a - ret, e[it].c));
            if (tmp) {
                e[it].c -= tmp;
                e[it ^ 1].c += tmp;
                if ((ret += tmp) == a) break;
            }
        }
        return ret;
    }
    void addEdge(int u, int v, int c, int w) {
        e.push_back({v, c, w}); vec[u].push_back(M++);
        e.push_back({u, 0, -w}); vec[v].push_back(M++);
    }
    void minCost(int n, int s, int t) {
        int a = ~0U >> 1; spfa(n, s, t);
        do {
            while (a) {
                memset(vis + 1, 0, n * sizeof(int));
                int adt = dfs(t, s, a);
                if (!adt) break;
                a -= adt; flow += adt; cost += adt * sum;
                ans = std::max(flow * INF - cost, ans);
            }
        } while (dijkstra(n, s, t)); //max flow
    }
    void clear(int n) {
        e.clear();
        for (int i = 1; i <= n; ++i)
            std::vector<int>().swap(vec[i]);
        M = sum = flow = cost = 0;
    }
}

class Solver{
public:
    void solve(){
        int n, k;
        std::cin >> n >> k;
        std::vector <int> a(1 << n);
        for (int i = 0; i < 1 << n; ++ i){
            std::cin >> a[i];
        }
        std::vector <piii> e;
        for (int i = 0; i < 1 << n; ++ i){
            int cnt = __builtin_popcount(i);
            if (cnt % 2 == 1){
                continue;
            }
            for (int j = 0; j < n; ++ j){
                int x = i ^ (1 << j);
                e.emplace_back(INF - (a[i] + a[x]), i, x);
            }
        }
        int num = e.size();
        num = std::min(num, (2 * n - 1) * (k - 1) + 1);
        std::nth_element(e.begin(), e.begin() + num, e.end());
        std::vector <int> c;
        for (int i = 0; i < num; ++ i){
            auto [w, u, v] = e[i];
            c.emplace_back(u);
            c.emplace_back(v);
        }
        std::sort(c.begin(), c.end());
        c.erase(std::unique(c.begin(), c.end()), c.end());
        for (int i = 0; i < num; ++ i){
            auto [w, u, v] = e[i];
            u = std::lower_bound(c.begin(), c.end(), u) - c.begin() + 1;
            v = std::lower_bound(c.begin(), c.end(), v) - c.begin() + 1;
            primal_dual::addEdge(u, v, 1, w);
        }
        int sz = c.size();
        int s = sz + 1;
        int s1 = sz + 2;
        int t = sz + 3;
        primal_dual::addEdge(s, s1, k, 0);
        for (int i = 0; i < sz; ++ i){
            int cnt = __builtin_popcount(c[i]);
            if (cnt % 2 == 0){
                primal_dual::addEdge(s1, i + 1, 1, 0);
            }
            else{
                primal_dual::addEdge(i + 1, t, 1, 0);
            }
        }
        primal_dual::minCost(t, s, t);
        std::cout << primal_dual::ans << '\n';
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
    // floating point number output template
    // std::cout << std::fixed << std::setprecision(18) << 1.0 << '\n';
    return 0;
}

#endif //WORKSPACE_TEMPLATE_H