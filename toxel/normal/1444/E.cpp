//
// Created by  on 2022/3/12.
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

const int N = 110;

std::vector <int> e[N];
i128 dp[N];

class Solver{
public:
    std::map <pii, int> col;
    std::vector <int> ban;

    bool check(int u, i128 mid, const std::vector <int> &vec, const std::vector <i128> &value){
        using pi128i = std::pair <i128, int>;
        int sz = vec.size();
        std::priority_queue <pi128i> pq;
        for (int i = 0; i < sz; ++ i){
            pq.emplace(value[i], vec[i]);
        }
        for (int i = N - 1; i >= 0 && !pq.empty(); -- i){
            auto p = pq.top();
            auto bound = i128(1) << i;
            if (mid >> i & 1){
                if (p.first >= bound){
                    pq.pop();
                    if (!pq.empty() && pq.top().first >= bound){
                        return false;
                    }
                    p.first ^= bound;
                    pq.emplace(p);
                }
                else{
                    col[{u, p.second}] = col[{p.second, u}] = i;
                    pq.pop();
                }
            }
            else{
                if (p.first >= (i128(1) << i)){
                    return false;
                }
            }
        }
        return pq.empty();
    }

    void dfs(int u, int fa){
        std::vector <int> vec;
        std::vector <i128> value;
        for (auto v : e[u]){
            if (v == fa){
                continue;
            }
            dfs(v, u);
            vec.emplace_back(v);
            value.emplace_back(dp[v]);
        }
        dp[u] = (i128(1) << N) - 1;
        for (int i = N - 1; i >= 0; -- i){
            if (check(u, dp[u] ^ (i128(1) << i), vec, value)){
                dp[u] ^= i128(1) << i;
            }
        }
        check(u, dp[u], vec, value);
    }

    std::vector <piii> edges;

    void dfs1(int u, int fa){
        for (auto v : e[u]){
            if (ban[v] || v == fa){
                continue;
            }
            dfs1(v, u);
            edges.emplace_back(col[{v, u}], v, u);
        }
    }

    void solve(int u){
        edges.clear();
        dfs1(u, 0);
        std::sort(edges.begin(), edges.end());
        if (edges.empty()){
            std::cout << "! " << u << "\n";
            std::cout.flush();
            return;
        }
        auto [w, u1, v1] = edges.back();
        std::cout << "? " << u1 << " " << v1 << "\n";
        std::cout.flush();
        int node;
        std::cin >> node;
        ban[u1 ^ v1 ^ node] = 1;
        solve(node);
    }

    void solve(){
        int n;
        std::cin >> n;
        for (int i = 0; i < n - 1; ++ i){
            int u, v;
            std::cin >> u >> v;
            e[u].emplace_back(v);
            e[v].emplace_back(u);
        }
        dfs(1, 0);
        ban.resize(n + 1);
        solve(1);
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