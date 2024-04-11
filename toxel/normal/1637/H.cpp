//
// Created by  on 2022/2/24.
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

//
// Created by  on 2022/1/6.
//

#ifndef WORKSPACE_BIT_H
#define WORKSPACE_BIT_H

#include <bits/stdc++.h>

template <typename T>
class BIT{
public:
    int sz;
    std::vector <T> vec;
    T sum;

    BIT(int size):sz(size + 1), vec(sz + 1), sum(0){}

    void add(int sit, T value){
        sum += value;
        for (sit += 1; sit < sz; sit += sit & -sit){
            vec[sit] += value;
        }
    }

    T query(int sit){
        T ret = 0;
        for (sit += 1; sit; sit -= sit & -sit){
            ret += vec[sit];
        }
        return ret;
    }

    T query_up(int sit){
        return sum - query(sit - 1);
    }

    T query(int l, int r){
        return query(r) - query(l - 1);
    }
};

#endif //WORKSPACE_BIT_H

class Solver{
public:
    void solve(){
        int n;
        std::cin >> n;
        std::vector <int> p(n + 1);
        ll tot = 0;
        BIT <int> bit(n);
        for (int i = 1; i <= n; ++ i){
            std::cin >> p[i];
            tot += bit.query_up(p[i]);
            bit.add(p[i], 1);
        }
        std::vector <int> vec;
        for (int i = 1; i <= n; ++ i){
            vec.emplace_back(2 * p[i] - i - 1);
        }
        std::sort(vec.begin(), vec.end());
        for (int i = 0; i <= n; ++ i){
            std::cout << tot - 1ll * i * (i - 1) / 2  << " \n"[i == n];
            if (i < n){
                tot += vec[i];
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
    return 0;
}

#endif //WORKSPACE_TEMPLATE_H