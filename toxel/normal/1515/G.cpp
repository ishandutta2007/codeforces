//
// Created by  on 2022/1/13.
//

//
// Created by  on 2022/1/6.
//

#include <bits/stdc++.h>
#define mp std::make_pair
#define scanf dont_use_scanf
#define printf dont_use_printf
#define endl dont_use_endl

using ll = int64_t;
using pii = std::pair <int, int>;
using piii = std::tuple <int, int, int>;

namespace SCC {
    const int max_N = (int) 2e5 + 21;

    int n, m, dfn[max_N], low[max_N], cnt;

    int sccno[max_N], scc_cnt, st[max_N], top;

    std::vector<pii> vec[max_N];
    std::vector <int> scc[max_N];

    ll value[max_N], gcd[max_N];

    void dfs(int u) {
        st[++top] = u;
        dfn[u] = low[u] = ++cnt;

        for (auto [v, w] : vec[u]) {
            if (!dfn[v]) {
                value[v] = value[u] + w;
                dfs(v);
                low[u] = std::min(low[u], low[v]);
            } else if (!sccno[v]) {
                low[u] = std::min(low[u], dfn[v]);
                gcd[u] = std::gcd(gcd[u], value[u] + w - value[v]);
            }
        }

        if (dfn[u] != low[u]) return;

        sccno[u] = ++scc_cnt;
        while (st[top] != u) {
            scc[scc_cnt].push_back(st[top]);
            sccno[st[top--]] = scc_cnt;
        }
        scc[scc_cnt].push_back(u);
        --top;
    }

    void solve(int n) {
        for (int i = 1; i <= n; ++i) if (!dfn[i]) dfs(i);
    }
};

const int N = 200010;

ll gcd[N];

void solve(){
    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < m; ++ i){
        int a, b, l;
        std::cin >> a >> b >> l;
        SCC::vec[a].emplace_back(b, l);
    }
    SCC::solve(n);
    for (int i = 1; i <= n; ++ i){
        ll &u = gcd[SCC::sccno[i]];
        u = std::gcd(u, SCC::gcd[i]);
    }
    int q;
    std::cin >> q;
    while (q --){
        int v;
        ll s, t;
        std::cin >> v >> s >> t;
        t = std::gcd(gcd[SCC::sccno[v]], t);
        std::cout << (s % t == 0 ? "YES" : "NO") << '\n';
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