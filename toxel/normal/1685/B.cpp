//
// Created by  on 2022/5/26.
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
        int a, b, c, d;
        std::cin >> a >> b >> c >> d;
        std::string s;
        std::cin >> s;
        int n = s.size();
        int pre = -1;
        std::vector <pii> vec;
        int cnt[2] = {};
        for (int i = 0; i < n; ++ i){
            ++ cnt[s[i] - 'A'];
        }
        if (cnt[0] != a + c + d || cnt[1] != b + c + d){
            std::cout << "NO\n";
            return;
        }
        for (int i = 0; i < n; ++ i){
            if (i == n - 1 || s[i] == s[i + 1]){
                int len = i - pre;
                vec.emplace_back(len, s[pre + 1] - 'A');
                pre = i;
            }
        }
        int basic = 0, tp[2] = {};
        for (auto [len, type]: vec){
            if (len % 2 == 0){
                tp[type] += len / 2;
            }
            else{
                basic += len / 2;
            }
        }
        if (basic + tp[0] + tp[1] < c + d){
            std::cout << "NO\n";
            return;
        }
        if (std::max(0, c - tp[0]) + std::max(0, d - tp[1]) <= basic){
            std::cout << "YES\n";
            return;
        }
        if (c < tp[0]){
            for (auto &[len, type]: vec){
                type ^= 1;
            }
            std::swap(c, d);
            std::swap(tp[0], tp[1]);
        }
        std::vector <pii> possible;
        for (auto [len, type]: vec){
            if (len % 2 == 0 && type == 1 && len >= 4){
                possible.emplace_back(len / 2, 2);
            }
        }
        std::sort(possible.begin(), possible.end());
        while (d <= tp[1] && !possible.empty()){
            tp[1] -= possible.back().second;
            ++ tp[0];
            possible.back().first -= possible.back().second;
            possible.back().second = 1;
            if (possible.back().first == 0){
                possible.pop_back();
            }
            if (tp[0] + basic >= c && tp[1] >= d){
                std::cout << "YES\n";
                return;
            }
        }
        std::cout << "NO\n";
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