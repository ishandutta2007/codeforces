//
// Created by  on 2022/2/4.
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
        fa[u] = v;
        sz[v] += sz[u];
    }
};

#endif //WORKSPACE_DISJOINTSET_H

//
// Created by  on 2022/2/4.
//

#ifndef WORKSPACE_BINARYLIFTING_H

#include <bits/stdc++.h>

class BinaryLifting{
public:
    using T = int; // value type
    using pii = std::pair <int, T>;

    std::vector <std::vector <pii>> e;
    std::vector <std::vector <int>> fa;
    std::vector <std::vector <T>> sum;
    std::vector <int> dep;
    int n, root, bit;

    explicit BinaryLifting(int sz, int root):n(sz), root(root){
        sz += 10;
        e.resize(sz);
        bit = 0;
        while ((1 << bit) < sz){
            ++ bit;
        }
        ++ bit;
        fa.resize(sz, std::vector <int>(bit));
        sum.resize(sz, std::vector <T>(bit));
        dep.resize(sz);
    }

    void add_edge(int u, int v, T w){
        e[u].emplace_back(v, w);
        e[v].emplace_back(u, w);
    }

    void dfs(int u, int pa, T w){
        fa[u][0] = pa;
        sum[u][0] = w;
        for (int i = 1; i < bit; ++ i){
            fa[u][i] = fa[fa[u][i - 1]][i - 1];
            sum[u][i] = std::max(sum[u][i - 1], sum[fa[u][i - 1]][i - 1]);
        }
        for (auto [v, w]: e[u]){
            if (v == pa){
                continue;
            }
            dep[v] = dep[u] + 1;
            dfs(v, u, w);
        }
    }

    pii lca(int u, int v){
        if (dep[u] < dep[v]){
            std::swap(u, v);
        }
        T tot = 0;
        for (int i = 0; i < bit; ++ i){
            if ((dep[u] - dep[v]) >> i & 1){
                tot = std::max(tot, sum[u][i]);
                u = fa[u][i];
            }
        }
        if (u == v){
            return {u, tot};
        }
        for (int i = bit - 1; i >= 0; -- i){
            if (fa[u][i] != fa[v][i]){
                tot = std::max({tot, sum[u][i], sum[v][i]});
                u = fa[u][i];
                v = fa[v][i];
            }
        }
        tot = std::max({tot, sum[u][0], sum[v][0]});
        u = fa[u][0];
        v = fa[v][0];
        return {u, tot};
    }

    void solve(){
        dfs(root, 0, 0);
    }
};

#define WORKSPACE_BINARYLIFTING_H

#endif //WORKSPACE_BINARYLIFTING_H

void solve(){
    int n, q;
    std::cin >> n >> q;
    std::vector <pii> ans(q + 1);
    std::vector <int> e(n + 1);
    for (int i = 1; i <= n; ++ i){
        std::cin >> e[i];
    }
    BinaryLifting bl(n, 1);
    std::vector <piiii> vec;
    for (int i = 0; i < n - 1; ++ i){
        int a, b, c, t;
        std::cin >> a >> b >> c >> t;
        bl.add_edge(a, b, t);
        vec.emplace_back(c, a, b, t);
    }
    bl.solve();
    std::sort(vec.begin(), vec.end());
    std::vector <piii> query;
    for (int i = 0; i < q; ++ i){
        int v, x;
        std::cin >> v >> x;
        query.emplace_back(v, i, x);
    }
    std::sort(query.begin(), query.end());
    std::vector <int> top(n + 1), value(n + 1), result(n + 1);
    for (int i = 1; i <= n; ++ i){
        top[i] = i;
        value[i] = e[i];
        result[i] = 0;
    }
    DisjointSet ds(n);
    for (int i = int(query.size()) - 1, j = int(vec.size()) - 1; i >= 0; -- i){
        while (j >= 0 && std::get <0>(vec[j]) >= std::get <0>(query[i])){
            auto [c, a, b, t] = vec[j];
            int u = ds.find(a), v = ds.find(b);
            if (value[u] > value[v]){
                std::tie(top[v], value[v], result[v]) = std::tuple(top[u], value[u], result[u]);
            }
            else if (value[u] < value[v]){
            }
            else{
                auto [tp, res] = bl.lca(top[u], top[v]);
                std::tie(top[v], result[v]) = std::tuple(tp, std::max({res, result[u], result[v]}));
            }
            ds.fa[u] = v;
            -- j;
        }
        auto [v, id, x] = query[i];
        int rt = ds.find(x);
        auto [tp, res] = bl.lca(top[rt], x);
        ans[id] = {value[rt], std::max({res, result[rt]})};
    }
    for (int i = 0; i < q; ++ i){
        std::cout << ans[i].first << ' ' << ans[i].second << '\n';
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int test = 1;
    // std::cin >> test;
    while (test --){
        solve();
    }
    return 0;
}

#endif //WORKSPACE_TEMPLATE_H