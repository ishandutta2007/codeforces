//
// Created by  on 2022/2/13.
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
    /*
    pii op[100];
    std::set <std::vector <int>> vis;

    void dfs(std::vector <int> vec, int dep = 0){
        std::sort(vec.begin(), vec.end());
        if (vis.count(vec)){
            return;
        }
        vis.emplace(vec);
        if (vec.back() > 20){
            return;
        }
        if (vec.front() == vec.back()){
            std::cout << vec.front() << '\n';
            for (int i = 0; i < dep; ++ i){
                std::cout << op[i].first << " " << op[i].second << "\n";
            }
            return;
        }
        int sz = vec.size();
        for (int i = 0; i < sz; ++ i){
            for (int j = i + 1; j < sz; ++ j){
                op[dep] = {i, j};
                std::vector <int> nvec = vec;
                nvec[i] = vec[j] - vec[i];
                nvec[j] = vec[j] + vec[i];
                dfs(nvec, dep + 1);
            }
        }
    }*/

    std::multiset <ll> set;
    std::vector <pii> result;

    void operate(ll x, ll y){
        auto u = set.find(x);
        assert(u != set.end());
        set.erase(u);
        u = set.find(y);
        assert(u != set.end());
        set.erase(u);
        set.emplace(std::abs(x - y));
        set.emplace(x + y);
        result.emplace_back(x, y);
    }

    void solve1(int l, int r){
        if (r - l <= l){
            return;
        }
        int x = l;
        while (x < r){
            x <<= 1;
        }
        if (x == r){
            for (int i = l, j = r - l; i < j; i += l, j -= l){
                operate(i, j);
            }
            solve1(l + l, r - l - l);
            return;
        }
        for (int i = x - r, j = r; i < j; i += l, j -= l){
            operate(i, j);
        }
        solve1(l + l, r - (x - r));
        solve1(l, x - r - l);
    }

    void solve(){
        // dfs({4, 8, 8, 8});
        int n;
        std::cin >> n;
        if (n == 2){
            std::cout << "-1\n";
            return;
        }
        for (int i = 1; i <= n; ++ i){
            set.emplace(i);
        }
        solve1(1, n);
        ll max = *std::prev(set.end());
        int cnt = 0;
        for (auto u : set){
            int x = max / u;
            while (x > 1){
                ++ cnt;
                x >>= 1;
            }
        }
        while (true){
            if (*std::next(set.begin()) == max && *(set.begin()) * 2 >= max){
                break;
            }
            int x = *(set.begin());
            int y = *std::next(set.begin());
            if (cnt % 2 == 1 && x == y){
                int bit = __builtin_ctz(x);
                int z = *std::next(std::next(set.begin()));
                if (x == z && bit % 2 == 0){
                    operate(x, y);
                    operate(0, z);
                    cnt = 0;
                    continue;
                }
            }
            operate(x, y);
            operate(std::abs(x - y), x + y);
        }
        /*if (*(set.begin()) < *std::prev(set.end())){
            if (n % 2 == 1){
                for (int i = 0; i < (n + 1) / 2; ++ i){
                    int x = *(set.begin());
                    int y = *std::next(set.begin());
                    operate(x, y);
                    operate(std::abs(x - y), x + y);
                }
            }
            else{
                for (int i = 0; i < 1; ++ i){
                    int x = *(set.begin());
                    int y = *std::next(set.begin());
                    operate(x, y);
                    operate(std::abs(x - y), x + y);
                }
                operate(*(set.begin()), *std::next(set.begin()));
                operate(*(set.begin()), *std::next(set.begin()));
                for (int i = 0; i < n / 2 - 1; ++ i){
                    int x = *(set.begin());
                    int y = *std::next(set.begin());
                    operate(x, y);
                    operate(std::abs(x - y), x + y);
                }
            }
        }*/
        assert(*(set.begin()) == *std::prev(set.end()));
        int sz = result.size();
        std::cout << sz << "\n";
        for (int i = 0; i < sz; ++ i){
            std::cout << result[i].first << " " << result[i].second << "\n";
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