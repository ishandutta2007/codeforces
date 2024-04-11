//
// Created by  on 2022/5/8.
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
// using Mint = Mod<int, UNDEFINED>;

class Solver{
public:
    void solve(){
        int n;
        std::cin >> n;
        std::vector <int> a(n + 1), b(n + 1);
        for (int i = 1; i <= n; ++ i){
            std::cin >> a[i];
        }
        for (int i = 1; i <= n; ++ i){
            std::cin >> b[i];
        }
        std::vector <int> p(n + 1);
        for (int i = 1; i <= n; ++ i){
            p[a[i]] = b[i];
        }
        std::vector <int> vis(n + 1);
        int tot = 0;
        for (int i = 1; i <= n; ++ i){
            int x = i, cnt = 0;
            while (!vis[x]){
                vis[x] = 1;
                ++ cnt;
                x = p[x];
            }
            tot += cnt / 2;
        }
        ll ans = -1ll * tot * (tot + 1) / 2 + 1ll * (n - tot + 1 + n) * tot / 2;
        std::cout << ans * 2 << '\n';
    }
};

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int test;
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