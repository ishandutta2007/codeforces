//
// Created by  on 2022/8/16.
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

class Solver{
public:
    void solve(){
        int n;
        std::cin >> n;
        std::vector <int> a(n + 1), pre(n + 1);
        for (int i = 1; i <= n; ++ i){
            std::cin >> a[i];
            pre[i] = pre[i - 1] ^ a[i];
        }
        std::vector <int> dp(n + 1);
        std::map <int, int> map;
        map[0] = 0;
        std::multiset <int> set;
        set.emplace(0);
        for (int i = 1; i <= n; ++ i){
            auto it = map.find(pre[i]);
            if (it == map.end()){
                dp[i] = *std::prev(set.end());
                map[pre[i]] = dp[i];
                set.emplace(dp[i]);
            }
            else{
                dp[i] = it -> second + 1;
                set.erase(set.find(it -> second));
                if (!set.empty()){
                    dp[i] = std::max(dp[i], *std::prev(set.end()));
                }
                it -> second = dp[i];
                set.emplace(it -> second);
            }
        }
        std::cout << n - dp[n] << '\n';
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