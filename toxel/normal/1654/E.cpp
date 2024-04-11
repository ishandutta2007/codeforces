//
// Created by  on 2022/3/20.
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

const int N = 100010;

ll c[N];
int cnt[N * 2];

class Solver{
public:
    int check(const std::vector <int> &a){
        int n = a.size();
        int max = 2;
        for (int i = 0; i < n; ++ i){
            for (int j = 0; j < n; ++ j){
                if (i == j){
                    continue;
                }
                int x = a[i] - a[j], y = i - j;
                if (x % y){
                    continue;
                }
                int &u = cnt[N + x / y];
                ++ u;
                max = std::max(u + 1, max);
            }
            for (int j = 0; j < n; ++ j){
                if (i == j){
                    continue;
                }
                int x = a[i] - a[j], y = i - j;
                if (x % y){
                    continue;
                }
                int &u = cnt[N + x / y];
                -- u;
            }
        }
        return max;
    }

    void solve(){
        const int SQRT1 = 80;
        const int SQRT = 1300;
        int n;
        std::cin >> n;
        std::vector <int> a(n);
        for (int i = 0; i < n; ++ i){
            std::cin >> a[i];
        }
        if (n == 1){
            std::cout << "0\n";
            return;
        }
        int ans = 2;
        for (int i = -SQRT1; i <= SQRT1; ++ i){
            for (int j = 0; j < n; ++ j){
                c[j] = a[j] + 1ll * i * j;
            }
            std::sort(c, c + n);
            for (int j = 0, k = 0; j < n; j = k){
                while (k < n && c[k] == c[j]){
                    ++ k;
                }
                ans = std::max(k - j, ans);
            }
        }
        for (int i = 0; i < n; i += SQRT){
            std::vector <int> vec;
            for (int j = i; j < i + 2 * SQRT && j < n; ++ j){
                vec.emplace_back(a[j]);
            }
            ans = std::max(ans, check(vec));
        }
        std::vector <int> vec;
        for (int j = std::max(0, n - 2 * SQRT); j < n; ++ j){
            vec.emplace_back(a[j]);
        }
        ans = std::max(ans, check(vec));
        std::cout << n - ans << "\n";
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
    // std::cout << std::fixed << std::setprecision(18) << 1.0 << '\n';
    return 0;
}

#endif //WORKSPACE_TEMPLATE_H