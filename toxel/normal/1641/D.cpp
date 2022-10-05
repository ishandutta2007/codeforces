//
// Created by  on 2022/2/23.
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

class Solver{
public:
    void solve(){
        const int N = 100010;
        std::map <int, std::bitset <N>> map;
        std::map <int, std::vector <int>> map1;
        using piv = std::pair <int, std::vector <int>>;
        int n, m;
        std::cin >> n >> m;
        std::vector <piv> vec(n);
        for (int i = 0; i < n; ++ i){
            vec[i].second.resize(m);
            for (int j = 0; j < m; ++ j){
                std::cin >> vec[i].second[j];
            }
            std::cin >> vec[i].first;
        }
        std::sort(vec.begin(), vec.end());
        for (int i = 0; i < n; ++ i){
            for (int j = 0; j < m; ++ j){
                map1[vec[i].second[j]].emplace_back(i);
            }
        }
        const int SQRT = 1000;
        for (const auto &[u, v]: map1){
            if (v.size() > SQRT){
                map[u] = std::bitset <N>();
                for (auto w : v){
                    map[u].set(w);
                }
            }
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; ++ i){
            std::bitset <N> set;
            for (int j = 0; j < m; ++ j){
                int u = vec[i].second[j];
                if (map1[u].size() <= SQRT){
                    for (auto v : map1[u]){
                        set.set(v);
                    }
                }
                else{
                    set |= map[u];
                }
            }
            set = ~set;
            int x = set._Find_first();
            if (x < n){
                ans = std::min(ans, vec[i].first + vec[x].first);
            }
        }
        if (ans == INT_MAX){
            ans = -1;
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
    return 0;
}

#endif //WORKSPACE_TEMPLATE_H