//
// Created by  on 2022/3/13.
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

class Solver{
public:
    void solve(){
        int n;
        std::cin >> n;
        std::string s, t;
        std::cin >> s >> t;
        const int BIT = 20;
        const int N = 1 << BIT;
        std::vector <int> e(N);
        DisjointSet set(BIT);
        for (int i = 0; i < n; ++ i){
            if (s[i] != t[i]){
                int x = s[i] - 'a', y = t[i] - 'a';
                set.unite(x, y);
                e[x] |= 1 << y;
            }
        }
        std::bitset <N> dp;
        dp[0] = true;
        for (int i = 0; i < N - 1; ++ i){
            if (!dp[i]){
                continue;
            }
            for (int j = 0; j < BIT; ++ j){
                if (!(i >> j & 1) && (e[j] & i) == 0){
                    dp[i | 1 << j] = true;
                }
            }
        }
        int max = 0;
        for (int i = 0; i < N; ++ i){
            if (dp[i]){
                max = std::max(max, __builtin_popcount(i));
            }
        }
        int ans = 2 * BIT - max;
        for (int i = 0; i < BIT; ++ i){
            if (set.find(i) == i){
                -- ans;
            }
        }
        std::cout << ans << '\n';
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