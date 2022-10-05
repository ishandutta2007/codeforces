//
// Created by  on 2022/3/2.
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
// Created by  on 2022/3/2.
//

#ifndef WORKSPACE_DFSORDER_H
#define WORKSPACE_DFSORDER_H

#include <bits/stdc++.h>

class DfsOrder{
public:
    std::vector <std::vector <int>> e;
    std::vector <int> dfn, right, dep;
    int dfn_cnt;
    int n, root;

    explicit DfsOrder(int sz, int root):n(sz), dfn_cnt(0), root(root){
        sz += 10;
        e.resize(sz);
        dfn.resize(sz);
        right.resize(sz);
        dep.resize(sz);
    }

    void add_edge(int u, int v){
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }

    void dfs(int u, int fa){
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
    }
};

#endif //WORKSPACE_DFSORDER_H

//
// Created by  on 2022/1/6.
//

#ifndef WORKSPACE_BIT_H
#define WORKSPACE_BIT_H

#include <bits/stdc++.h>

template <typename T>
class BIT{
public:
    int sz;
    std::vector <T> vec;
    T sum;

    BIT(int size):sz(size + 10), vec(sz + 10), sum(0){}

    void add(int sit, T value){
        sum += value;
        for (sit += 1; sit < sz; sit += sit & -sit){
            vec[sit] += value;
        }
    }

    T query(int sit){
        T ret = 0;
        for (sit += 1; sit; sit -= sit & -sit){
            ret += vec[sit];
        }
        return ret;
    }

    T query_up(int sit){
        return sum - query(sit - 1);
    }

    T query(int l, int r){
        return query(r) - query(l - 1);
    }
};

#endif //WORKSPACE_BIT_H

class Solver{
public:
    void solve(){
        int n, m;
        std::cin >> n >> m;
        DfsOrder dfs(n, 1);
        for (int i = 2, p; i <= n; ++ i){
            std::cin >> p;
            dfs.add_edge(p, i);
        }
        dfs.solve();
        std::vector <pii> type1, type2;
        for (int i = 0; i < m; ++ i){
            int x, y;
            std::cin >> x >> y;
            if (dfs.dep[x] > dfs.dep[y]){
                std::swap(x, y);
            }
            if (dfs.dfn[x] <= dfs.dfn[y] && dfs.right[y] <= dfs.right[x]){
                type1.emplace_back(x, y);
            }
            else{
                type2.emplace_back(x, y);
            }
        }
        BIT <int> bit(n);
        std::sort(type1.begin(), type1.end(), [&](pii p1, pii p2){
            return dfs.dep[p1.first] > dfs.dep[p2.first];
        });
        int ans = 0;
        std::map <int, std::vector <pii>> map;
        for (int i = 1; i <= n; ++ i){
            for (auto v : dfs.e[i]){
                if (v > i){
                    map[i].emplace_back(dfs.dfn[v], v);
                }
            }
        }
        for (auto [x, y]: type1){
            auto &vec = map[x];
            int pos = std::prev(std::upper_bound(vec.begin(), vec.end(), pii{dfs.dfn[y], INT_MAX})) -> second;
            if (pos == y){
                std::cout << "-1\n";
                return;
            }
            int l = dfs.dfn[pos], r = dfs.dfn[y] - 1;
            int num = 0;
            if (l <= r){
                num += bit.query(l, r);
            }
            l = dfs.right[y] + 1, r = dfs.right[pos];
            if (l <= r){
                num += bit.query(l, r);
            }
            if (num == 0){
                bit.add(dfs.dfn[pos], 1);
                ++ ans;
            }
        }
        for (auto [x, y]: type2){
            int num = bit.query(dfs.dfn[x], dfs.right[x]);
            num += bit.query(dfs.dfn[y], dfs.right[y]);
            if (ans == num){
                ++ ans;
                break;
            }
        }
        std::cout << ans << "\n";
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