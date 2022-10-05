//
// Created by  on 2022/3/7.
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

    std::vector <std::vector <int>> e;
    std::vector <std::vector <int>> fa;
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
        dep.resize(sz);
    }

    void add_edge(int u, int v){
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }

    void dfs(int u, int pa){
        fa[u][0] = pa;
        for (int i = 1; i < bit; ++ i){
            fa[u][i] = fa[fa[u][i - 1]][i - 1];
        }
        for (auto v: e[u]){
            if (v == pa){
                continue;
            }
            dep[v] = dep[u] + 1;
            dfs(v, u);
        }
    }

    int lca(int u, int v){
        if (dep[u] < dep[v]){
            std::swap(u, v);
        }
        for (int i = 0; i < bit; ++ i){
            if ((dep[u] - dep[v]) >> i & 1){
                u = fa[u][i];
            }
        }
        if (u == v){
            return u;
        }
        for (int i = bit - 1; i >= 0; -- i){
            if (fa[u][i] != fa[v][i]){
                u = fa[u][i];
                v = fa[v][i];
            }
        }
        return fa[u][0];
    }

    void solve(){
        dfs(root, 0);
    }
};

#define WORKSPACE_BINARYLIFTING_H

#endif //WORKSPACE_BINARYLIFTING_H

class Solver{
public:
    void solve(){
        int n, m;
        std::cin >> n >> m;
        std::vector <piii> e;
        std::set <pii> edge_count;
        std::vector <pii> initial_e;
        for (int i = 0; i < m; ++ i){
            int u, v, w;
            std::cin >> u >> v >> w;
            if (u > v){
                std::swap(u, v);
            }
            e.emplace_back(w, u, v);
            edge_count.emplace(u, v);
            initial_e.emplace_back(u, v);
        }
        std::sort(e.begin(), e.end());
        int big_sz = 2 * n + 10;
        DisjointSet set(big_sz), set1(big_sz);
        int ncnt = n;
        std::vector <std::array <int, 2>> ch(big_sz), ch1(big_sz);
        std::vector <pii> node;
        for (auto [w, u, v]: e){
            u = set.find(u), v = set.find(v);
            if (u == v){
                continue;
            }
            ++ ncnt;
            set.unite(u, ncnt);
            set.unite(v, ncnt);
            ch[ncnt] = {u, v};
            node.emplace_back(w, ncnt);
        }
        std::sort(node.begin(), node.end());
        std::vector <std::vector <int>> comp(big_sz), content(big_sz);
        for (int i = 1; i <= n; ++ i){
            comp[i].emplace_back(i);
            content[i].emplace_back(i);
        }
        ncnt = n;
        std::vector <int> w(big_sz);
        std::vector <int> vis(big_sz);
        for (auto [w0, u]: node){
            auto &comp1 = comp[ch[u][0]];
            auto &comp2 = comp[ch[u][1]];
            auto unite = [&](int u, int v, int w0){
                u = set1.find(u), v = set1.find(v);
                if (u == v){
                    return u;
                }
                ++ ncnt;
                set1.unite(u, ncnt);
                set1.unite(v, ncnt);
                ch1[ncnt] = {u, v};
                w[ncnt] = w0;
                content[u].swap(content[ncnt]);
                if (content[ncnt].size() < content[v].size()){
                    content[ncnt].swap(content[v]);
                }
                for (auto x: content[v]){
                    content[ncnt].emplace_back(x);
                }
                return ncnt;
            };
            std::vector <pii> edges_to_add;
            for (auto u : comp1){
                std::vector <int> to_unite;
                for (int i = 0; i < int(comp2.size()); ++ i){
                    bool found = false;
                    for (auto x: content[u]){
                        for (auto y: content[comp2[i]]){
                            int a = x, b = y;
                            if (a > b){
                                std::swap(a, b);
                            }
                            if (!edge_count.count({a, b})){
                                found = true;
                                break;
                            }
                        }
                        if (found){
                            break;
                        }
                    }
                    if (found){
                        edges_to_add.emplace_back(u, comp2[i]);
                        std::swap(comp2[i], comp2.back());
                        to_unite.emplace_back(comp2.back());
                        comp2.pop_back();
                        -- i;
                    }
                }
                if (to_unite.empty()){
                    continue;
                }
                int sz = to_unite.size(), cur = to_unite.front();
                for (int i = 1; i < sz; ++ i){
                    cur = unite(to_unite[i], cur, w0);
                }
                comp2.emplace_back(cur);
            }
            for (auto [x, y]: edges_to_add){
                unite(x, y, w0);
            }
            for (auto x: comp1){
                x = set1.find(x);
                if (!vis[x]){
                    comp[u].emplace_back(x);
                    vis[x] = 1;
                }
            }
            for (auto x: comp2){
                x = set1.find(x);
                if (!vis[x]){
                    comp[u].emplace_back(x);
                    vis[x] = 1;
                }
            }
            for (auto x: comp1){
                x = set1.find(x);
                vis[x] = 0;
            }
            for (auto x: comp2){
                x = set1.find(x);
                vis[x] = 0;
            }
            std::vector <int>().swap(comp1);
            std::vector <int>().swap(comp2);
        }
        BinaryLifting bl(ncnt, ncnt);
        for (int i = n + 1; i <= ncnt; ++ i){
            auto [x, y] = ch1[i];
            bl.add_edge(x, i);
            bl.add_edge(y, i);
        }
        bl.solve();
        for (int i = 0; i < m; ++ i){
            auto [u, v] = initial_e[i];
            std::cout << w[bl.lca(u, v)] << " \n"[i == m - 1];
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