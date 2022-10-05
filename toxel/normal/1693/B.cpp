//
// Created by  on 2022/6/16.
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

const int N = 200010;

std::vector <int> e[N];

class Solver{
public:
    std::vector <int> p, l, r;
    std::vector <ll> sum;
    int ans;

    void dfs(int u){
        for (auto v: e[u]){
            dfs(v);
            sum[u] += std::max(ll(l[v]), sum[v]);
        }
        if (sum[u] < l[u]){
            ++ ans;
            sum[u] = std::max(ll(r[u]), sum[u]);
        }
        sum[u] = std::min(sum[u], ll(r[u]));
    }

    void solve(){
        int n;
        std::cin >> n;
        for (int i = 0; i <= n; ++ i){
            e[i].clear();
        }
        p.resize(n + 1);
        l.resize(n + 1);
        r.resize(n + 1);
        sum.resize(n + 1);
        for (int i = 2; i <= n; ++ i){
            std::cin >> p[i];
            e[p[i]].emplace_back(i);
        }
        for (int i = 1; i <= n; ++ i){
            std::cin >> l[i] >> r[i];
        }
        ans = 0;
        dfs(1);
        std::cout << ans << '\n';
    }
};

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int test = 1;
    std::cin >> test;
    // floating point number output template
    std::cout << std::fixed << std::setprecision(18);
    while (test --){
        Solver solver;
        solver.solve();
    }
    return 0;
}

#endif //WORKSPACE_TEMPLATE_H