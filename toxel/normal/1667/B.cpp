//
// Created by  on 2022/4/19.
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

    BIT(int size):sz(size + 10), vec(sz + 10, INT_MIN), sum(0){}

    void add(int sit, T value){
        for (sit += 1; sit < sz; sit += sit & -sit){
            vec[sit] = std::max(vec[sit], value);
        }
    }

    T query(int sit){
        T ret = INT_MIN;
        for (sit += 1; sit; sit -= sit & -sit){
            ret = std::max(ret, vec[sit]);
        }
        return ret;
    }
};

#endif //WORKSPACE_BIT_H

class Solver{
public:
    void solve(){
        int n;
        std::cin >> n;
        std::vector <ll> a(n + 1), pre(n + 1);
        for (int i = 1; i <= n; ++ i){
            std::cin >> a[i];
            pre[i] = pre[i - 1] + a[i];
        }
        std::vector <int> dp(n + 1, INT_MIN);
        dp[0] = 0;
        std::vector <ll> vec;
        for (int i = 0; i <= n; ++ i){
            vec.emplace_back(pre[i]);
        }
        std::sort(vec.begin(), vec.end());
        vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
        BIT <int> bit(n);
        bit.add(std::lower_bound(vec.begin(), vec.end(), 0) - vec.begin(), 0);
        for (int i = 1; i <= n; ++ i){
            int sgn = (a[i] > 0) - (a[i] < 0);
            dp[i] = std::max(dp[i], dp[i - 1] + sgn);
            int pos = std::lower_bound(vec.begin(), vec.end(), pre[i]) - vec.begin();
            dp[i] = std::max(dp[i], bit.query(pos - 1) + i);
            bit.add(pos, dp[i] - i);
        }
        std::cout << dp[n] << '\n';
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
    std::cout << std::fixed << std::setprecision(18) << '\n';
    return 0;
}

#endif //WORKSPACE_TEMPLATE_H