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
        int n, x;
        std::cin >> n >> x;
        std::map <int, std::array <int, 40>> map;
        for (int i = 0; i < n; ++ i){
            int y;
            std::cin >> y;
            int cnt = 0;
            while (y % x == 0){
                y /= x;
                ++ cnt;
            }
            ++ map[y][cnt];
        }
        int ans = 0;
        for (const auto &[u, vec]: map){
            auto a = vec;
            for (int i = 0; i < 39; ++ i){
                if (a[i] > a[i + 1]){
                    ans += a[i] - a[i + 1];
                    a[i] = a[i + 1] = 0;
                }
                else{
                    a[i + 1] -= a[i];
                    a[i] = 0;
                }
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
    return 0;
}

#endif //WORKSPACE_TEMPLATE_H