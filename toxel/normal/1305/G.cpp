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

const int N = 200010;

std::vector <int> vec[N];

class Solver{
public:
    void solve(){
        const int BIT = 18;
        const int UP = 1 << BIT;
        int n;
        std::cin >> n;
        std::vector <int> a(n + 1);
        for (int i = 1; i <= n; ++ i){
            std::cin >> a[i];
            vec[i].emplace_back(i);
        }
        a[0] = 0;
        DisjointSet set(n);
        ll ans = 0;
        while (true){
            for (int i = 0; i < N; ++ i){
                vec[i].clear();
            }
            std::vector <int> roots;
            for (int i = 0; i <= n; ++ i){
                if (set.find(i) == i){
                    roots.emplace_back(i);
                }
                vec[set.find(i)].emplace_back(i);
            }
            int sz = roots.size();
            if (sz == 1){
                break;
            }
            int bit = 0;
            while ((1 << bit) < sz){
                ++ bit;
            }
            ++ bit;
            std::vector <piii> max(n + 1);
            for (int i = 0; i < bit; ++ i){
                for (int j = 0; j < 2; ++ j){
                    std::vector <pii> dp(UP, {-1, -1});
                    for (int k = 0; k < sz; ++ k){
                        if ((k >> i & 1) == j){
                            for (auto u : vec[roots[k]]){
                                dp[a[u]] = {a[u], u};
                            }
                        }
                    }
                    for (int k = 0; k < BIT; ++ k){
                        for (int u = 0; u < UP; ++ u){
                            if (u >> k & 1){
                                dp[u] = std::max(dp[u], dp[u ^ 1 << k]);
                            }
                        }
                    }
                    for (int k = 0; k < sz; ++ k){
                        if ((k >> i & 1) != j){
                            for (auto u: vec[roots[k]]){
                                int x = dp[(UP - 1) ^ a[u]].second;
                                if (x == -1){
                                    continue;
                                }
                                int y = u;
                                if (x > y){
                                    std::swap(x, y);
                                }
                                piii &v = max[roots[k]];
                                v = std::max(v, piii{a[x] + a[y], x, y});
                            }
                        }
                    }
                }
            }
            for (auto root: roots){
                auto [w, u, v] = max[root];
                if (set.find(u) != set.find(v)){
                    ans += w;
                    set.unite(u, v);
                }
            }
        }
        for (int i = 1; i <= n; ++ i){
            ans -= a[i];
        }
        std::cout << ans << '\n';
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