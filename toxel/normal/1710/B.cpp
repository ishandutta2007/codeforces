//
// Created by  on 2022/7/24.
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



#include <bits/stdc++.h>

template <typename T>
class Discretization{
public:
    std::vector <T> c;

    void add(T x){
        c.emplace_back(x);
    }

    void add(T l, T r){
        c.emplace_back(l);
        c.emplace_back(r + 1);
    }

    void process(){
        std::sort(c.begin(), c.end());
        c.erase(std::unique(c.begin(), c.end()), c.end());
    }

    int get(T x){
        return std::lower_bound(c.begin(), c.end(), x) - c.begin();
    }

    T get_v(int pos){
        return c[pos];
    }
};


class Solver{
public:
    void solve(){
        int n, m;
        std::cin >> n >> m;
        std::vector <int> x(n), p(n);
        Discretization <int> dis;
        for (int i = 0; i < n; ++ i){
            std::cin >> x[i] >> p[i];
            dis.add(x[i]);
        }
        dis.process();
        std::vector <piii> events;
        for (int i = 0; i < n; ++ i){
            events.emplace_back(x[i] - p[i], 1, -x[i] + p[i]);
            events.emplace_back(x[i], -1, x[i] - p[i]);
            events.emplace_back(x[i], -1, x[i] + p[i]);
            events.emplace_back(x[i] + p[i], 1, -x[i] - p[i]);
        }
        std::sort(events.begin(), events.end());
        int sz1 = dis.c.size(), sz2 = events.size();
        ll k = 0, b = 0;
        ll constraint1 = LLONG_MIN, constraint2 = LLONG_MIN;
        for (int i = 0, j = 0; i < sz1 && j < sz2; ++ i){
            int x1 = dis.c[i];
            while (j < sz2 && std::get <0>(events[j]) <= x1){
                auto [pos, k1, b1] = events[j];
                k += k1, b += b1;
                ++ j;
            }
            ll value = k * x1 + b;
            if (value > m){
                ll need = value - m;
                constraint1 = std::max(need - x1, constraint1);
                constraint2 = std::max(need + x1, constraint2);
            }
        }
        if (constraint1 == LLONG_MIN){
            for (int i = 0; i < n; ++ i){
                std::cout << '1';
            }
            std::cout << '\n';
            return;
        }
        for (int i = 0; i < n; ++ i){
            if (x[i] + constraint1 <= p[i] && -x[i] + constraint2 <= p[i]){
                std::cout << '1';
            }
            else{
                std::cout << '0';
            }
        }
        std::cout << '\n';
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