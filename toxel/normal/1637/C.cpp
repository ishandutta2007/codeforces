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
    int n;
    std::cin >> n;
    std::vector <int> a(n);
    for (int i = 0; i < n; ++ i){
        std::cin >> a[i];
    }
    if (n == 3){
        if (a[1] % 2 == 1){
            std::cout << "-1\n";
            return;
        }
        std::cout << a[1] / 2 << "\n";
        return;
    }
    bool non_one = false;
    for (int i = 1; i < n - 1; ++ i){
        if (a[i] != 1){
            non_one = true;
        }
    }
    if (!non_one){
        std::cout << "-1\n";
        return;
    }
    ll ans = 0;
    for (int i = 1; i < n - 1; ++ i){
        ans += (a[i] + 1) / 2;
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