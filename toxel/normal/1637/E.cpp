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

void solve(){
    int n, m;
    std::cin >> n >> m;
    std::vector <int> a(n);
    std::map <int, int> cnt;
    for (int i = 0; i < n; ++ i){
        std::cin >> a[i];
        ++ cnt[a[i]];
    }
    std::map <int, std::vector <int>> ban;
    for (int i = 0; i < m; ++ i){
        int x, y;
        std::cin >> x >> y;
        ban[x].emplace_back(y);
    }
    for (auto &p : ban){
        std::sort(p.second.begin(), p.second.end());
    }
    std::map <int, std::vector <int>> map;
    for (auto [u, v]: cnt){
        map[v].emplace_back(u);
    }
    std::vector <std::pair <int, std::vector <int>>> to_check;
    for (auto &[u, v]: map){
        to_check.emplace_back(u, v);
    }
    ll ans = 0;
    for (auto [x, cnt_x]: cnt){
        auto &ban_y = ban[x];
        for (auto &[cnt_y, check_y]: to_check){
            int sz1 = ban_y.size(), sz2 = check_y.size();
            for (int i = sz2 - 1, j = sz1 - 1; i >= 0 && check_y[i] > x; -- i){
                while (j >= 0 && ban_y[j] > check_y[i]){
                    -- j;
                }
                if (j >= 0 && ban_y[j] == check_y[i]){
                    continue;
                }
                int y = check_y[i];
                ans = std::max(ans, 1ll * (cnt_x + cnt_y) * (x + y));
                break;
            }
        }
    }
    std::cout << ans << "\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int test;
    std::cin >> test;
    while (test --){
        solve();
    }
    return 0;
}

#endif //WORKSPACE_TEMPLATE_H