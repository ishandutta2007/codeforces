//
// Created by  on 2022/2/12.
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

const int N = 200010;

std::vector <int> e[N];
int h[N], max_h[N];
ll ans = 0;

void dfs(int u, int fa){
    max_h[u] = 0;
    for (auto v : e[u]){
        if (v == fa){
            continue;
        }
        dfs(v, u);
        max_h[u] = std::max(max_h[u], max_h[v]);
    }
    if (fa > 0 && h[u] > max_h[u]){
        ans += h[u] - max_h[u];
        max_h[u] = h[u];
    }
}

void solve(){
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; ++ i){
        std::cin >> h[i];
    }
    for (int i = 0; i < n - 1; ++ i){
        int u, v;
        std::cin >> u >> v;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    int max = *std::max_element(h + 1, h + n + 1);
    int root = -1;
    for (int i = 1; i <= n; ++ i){
        if (max == h[i]){
            root = i;
            break;
        }
    }
    dfs(root, 0);
    if (e[root].size() == 1){
        ans += h[root] + h[root] - max_h[root];
    }
    else{
        std::vector <int> vec;
        for (auto v : e[root]){
            vec.emplace_back(max_h[v]);
        }
        std::sort(vec.begin(), vec.end(), std::greater());
        ans += h[root] + h[root] - vec[0] - vec[1];
    }
    std::cout << ans << '\n';
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