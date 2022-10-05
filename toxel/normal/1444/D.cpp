//
// Created by  on 2022/3/12.
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

const int MAX = 1000010;

class Solver{
public:
    using vi = std::vector <int>;

    std::pair <vi, vi> split(const vi &vec)const{
        int sum = 0;
        for (auto u : vec){
            sum += u;
        }
        if (sum % 2 == 1){
            return {{}, {}};
        }
        sum /= 2;
        std::bitset <MAX> dp;
        dp.set(0);
        std::vector <int> pre(sum + 1, -1);
        int sz = vec.size();
        for (int i = 0; i < sz; ++ i){
            int u = vec[i];
            auto dp1 = dp << u | dp;
            auto update = dp1 ^ dp;
            for (int j = update._Find_first(); j <= sum; j = update._Find_next(j)){
                pre[j] = i;
            }
            dp = dp1;
        }
        if (pre[sum] == -1){
            return {{}, {}};
        }
        std::vector <int> vis(sz);
        while (sum > 0){
            vis[pre[sum]] = 1;
            sum -= vec[pre[sum]];
        }
        std::vector <int> vec1, vec2;
        for (int i = 0; i < sz; ++ i){
            (vis[i] ? vec1 : vec2).emplace_back(vec[i]);
        }
        if (vec1.size() > vec2.size()){
            vec1.swap(vec2);
        }
        return {vec1, vec2};
    }

    void solve(){
        int h;
        std::cin >> h;
        std::vector <int> vec1(h);
        for (int i = 0; i < h; ++ i){
            std::cin >> vec1[i];
        }
        int v;
        std::cin >> v;
        std::vector <int> vec2(v);
        for (int i = 0; i < v; ++ i){
            std::cin >> vec2[i];
        }
        if (h != v){
            std::cout << "No\n";
            return;
        }
        auto [v1, v2] = split(vec1);
        auto [v3, v4] = split(vec2);
        if (v1.empty() || v3.empty()){
            std::cout << "No\n";
            return;
        }
        std::vector <int> v5, v6;
        for (auto u : v1){
            v5.emplace_back(u);
        }
        for (auto u : v2){
            v5.emplace_back(u);
        }
        for (auto u : v3){
            v6.emplace_back(u);
        }
        for (auto u : v4){
            v6.emplace_back(u);
        }
        std::vector <pii> vec;
        for (int i = 0; i < h; ++ i){
            vec.emplace_back(v5[i], v6[i]);
        }
        if (v1.size() <= v3.size()){
            int sz = std::min(v1.size(), v3.size());
            std::sort(vec.begin(), vec.begin() + sz, [&](const pii &p1, const pii &p2){
                return p1.first * p2.second > p1.second * p2.first;
            });
            int sz1 = std::min(v2.size(), v4.size());
            for (int i = sz; i < h - sz1; ++ i){
                vec[i].first = -vec[i].first;
            }
            std::sort(vec.end() - sz1, vec.end(), [&](const pii &p1, const pii &p2){
                return p1.first * p2.second > p1.second * p2.first;
            });
            for (int i = h - sz1; i < h; ++ i){
                vec[i].first = -vec[i].first;
                vec[i].second = -vec[i].second;
            }
            int x = 0, y = 0;
            std::cout << "Yes\n";
            for (int i = 0; i < h; ++ i){
                std::cout << x << " " << y << "\n";
                x += vec[i].first;
                std::cout << x << " " << y << "\n";
                y += vec[i].second;
            }
        }
        else{
            int sz = std::min(v1.size(), v3.size());
            std::sort(vec.begin(), vec.begin() + sz, [&](const pii &p1, const pii &p2){
                return p1.first * p2.second < p1.second * p2.first;
            });
            int sz1 = std::min(v2.size(), v4.size());
            for (int i = sz; i < h - sz1; ++ i){
                vec[i].second = -vec[i].second;
            }
            std::sort(vec.end() - sz1, vec.end(), [&](const pii &p1, const pii &p2){
                return p1.first * p2.second < p1.second * p2.first;
            });
            for (int i = h - sz1; i < h; ++ i){
                vec[i].first = -vec[i].first;
                vec[i].second = -vec[i].second;
            }
            int x = 0, y = 0;
            std::cout << "Yes\n";
            for (int i = 0; i < h; ++ i){
                std::cout << x << " " << y << "\n";
                y += vec[i].second;
                std::cout << x << " " << y << "\n";
                x += vec[i].first;
            }
        }
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