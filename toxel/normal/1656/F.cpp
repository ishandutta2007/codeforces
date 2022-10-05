//
// Created by  on 2022/3/24.
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
        int n;
        std::cin >> n;
        std::vector <ll> a(n + 1);
        for (int i = 1; i <= n; ++ i){
            std::cin >> a[i];
        }
        std::sort(a.begin() + 1, a.end());
        std::vector <ll> pre = a;
        for (int i = 1; i <= n; ++ i){
            pre[i] += pre[i - 1];
        }
        ll ans = LLONG_MIN;
        for (int i = 0; i <= n; ++ i){
            ll k = 0, b = 0;
            ll prel = pre[i], prer = pre[n] - pre[i];
            ll min = a[1], max = a[n];
            ll l = i, r = n - i;
            b += prel * max;
            k += l * max + prel;
            b += prer * min;
            k += r * min + prer;
            b -= min * max;
            k -= min + max;
            if (i == 0){
                b = min * (pre[n] - min);
                k = pre[n] - min + min * (n - 1);
                if (k > 0){
                    std::cout << "INF\n";
                    return;
                }
                ans = std::max(ans, k * -min + b);
            }
            else if (i == n){
                b = max * (pre[n] - max);
                k = pre[n] - max + max * (n - 1);
                if (k < 0){
                    std::cout << "INF\n";
                    return;
                }
                ans = std::max(ans, k * -max + b);
            }
            else{
                ans = std::max(ans, k * -a[i] + b);
                ans = std::max(ans, k * -a[i + 1] + b);
            }
        }
        std::cout << ans << "\n";
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
    // floating point number output template
    // std::cout << std::fixed << std::setprecision(18) << 1.0 << '\n';
    return 0;
}

#endif //WORKSPACE_TEMPLATE_H