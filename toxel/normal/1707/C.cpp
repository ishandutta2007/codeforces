//
// Created by  on 2022/7/16.
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

//
// Created by  on 2022/1/23.
//

#ifndef WORKSPACE_DISJOINTSET_H
#define WORKSPACE_DISJOINTSET_H

#include <bits/stdc++.h>

class DisjointSet{
public:
    std::vector <int> fa, sz;

    explicit DisjointSet(int n){
        n += 10;
        fa.resize(n);
        sz.resize(n);
        for (int i = 0; i < n; ++ i){
            fa[i] = i;
            sz[i] = 1;
        }
    }

    int find(int u){
        return fa[u] == u ? u : (fa[u] = find(fa[u]));
    }

    void unite(int u, int v){
        u = find(u), v = find(v);
        if (u == v) return;
        fa[u] = v;
        sz[v] += sz[u];
    }
};

#endif //WORKSPACE_DISJOINTSET_H

//
// Created by  on 2022/3/2.
//

#ifndef WORKSPACE_DFSORDER_H
#define WORKSPACE_DFSORDER_H

#include <bits/stdc++.h>

class DfsOrder{
public:
    std::vector <std::vector <int>> e;
    std::vector <int> dfn, right, dep, pa, pref;
    int dfn_cnt;
    int n, root;

    explicit DfsOrder(int sz, int root):n(sz), dfn_cnt(0), root(root){
        sz += 10;
        e.resize(sz);
        dfn.resize(sz);
        right.resize(sz);
        dep.resize(sz);
        pa.resize(sz);
        pref.resize(sz);
    }

    void add_edge(int u, int v){
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }

    void dfs(int u, int fa){
        pa[u] = fa;
        dfn[u] = ++ dfn_cnt;
        for (auto v : e[u]){
            if (v == fa){
                continue;
            }
            dep[v] = dep[u] + 1;
            dfs(v, u);
        }
        right[u] = dfn_cnt;
    }

    void solve(){
        dfs(root, 0);
        for (int i = 1; i <= n; ++ i){
            std::sort(e[i].begin(), e[i].end(), [&](const int &p1, const int &p2){
                return dfn[p1] < dfn[p2];
            });
        }
    }

    bool is_son(int u, int v){
        return dfn[u] <= dfn[v] && right[v] <= right[u];
    }

    int get_other(int u, int v){
        if (!is_son(u, v)){
            return pa[u];
        }
        auto it = std::lower_bound(e[u].begin(), e[u].end(), v, [&](const int &id, const int &val){
            return dfn[id] <= dfn[v];
        }) - 1;
        return *it;
    }

    void add(int u, int v){
        ++ pref[dfn[u]];
        -- pref[right[u] + 1];
        if (is_son(u, v)){
            int pos = get_other(u, v);
            -- pref[dfn[pos]];
            ++ pref[right[pos] + 1];
            ++ pref[1];
            -- pref[dfn[u]];
            ++ pref[right[u] + 1];
            -- pref[n + 1];
        }
    }
};

#endif //WORKSPACE_DFSORDER_H

const int N = 200010;

int u[N], v[N];
bool valid[N];

class Solver{
public:
    void solve(){
        int n, m;
        std::cin >> n >> m;
        std::map <pii, int> value;
        for (int i = 0; i < m; ++ i){
            std::cin >> u[i] >> v[i];
            value[{u[i], v[i]}] = value[{v[i], u[i]}] = i;
        }
        DisjointSet set(n);
        DfsOrder dfsOrder(n, 1);
        int bad_cnt = 0;
        for (int i = 0; i < m; ++ i){
            if (set.find(u[i]) == set.find(v[i])){
                valid[i] = false;
                ++ bad_cnt;
            }
            else{
                valid[i] = true;
                dfsOrder.add_edge(u[i], v[i]);
                set.unite(u[i], v[i]);
            }
        }
        dfsOrder.solve();
        for (int i = 0; i < m; ++ i){
            if (!valid[i]){
                int u_other = dfsOrder.get_other(u[i], v[i]);
                int v_other = dfsOrder.get_other(v[i], u[i]);
                if (value[{u[i], u_other}] < i && value[{v[i], v_other}] < i){
                    dfsOrder.add(u[i], v[i]);
                    dfsOrder.add(v[i], u[i]);
                }
            }
        }
        for (int i = 1; i <= n; ++ i){
            dfsOrder.pref[i] += dfsOrder.pref[i - 1];
        }
        for (int i = 1; i <= n; ++ i){
            if (dfsOrder.pref[dfsOrder.dfn[i]] == bad_cnt){
                std::cout << '1';
            }
            else{
                std::cout << '0';
            }
        }
        std::cout << '\n';
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