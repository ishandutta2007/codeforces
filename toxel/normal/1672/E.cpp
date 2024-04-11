//
// Created by  on 2022/4/23.
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
    int ask(int w){
        std::cout << "? " << w << '\n';
        std::cout.flush();
        int ans;
        std::cin >> ans;
        return ans;
    }

    void solve(){
        int n;
        std::cin >> n;
        int l = 1, r = 1e7;
        while (l < r){
            int mid = (l + r) / 2;
            if (ask(mid) != 1){
                l = mid + 1;
            }
            else{
                r = mid;
            }
        }
        int ans = l;
        for (int i = 2; i <= n; ++ i){
            int x = ask(l / i);
            if (x <= i && x != 0){
                ans = std::min(ans, i * (l / i));
            }
        }
        std::cout << "! " << ans << '\n';
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
    std::cout << std::fixed << std::setprecision(18) << '\n';
    return 0;
}

#endif //WORKSPACE_TEMPLATE_H