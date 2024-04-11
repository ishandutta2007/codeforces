//
// Created by  on 2022/8/16.
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

class Solver{
public:
    void solve(){
        int k;
        std::cin >> k;
        std::vector <ll> num(k);
        ll sum = 0;
        for (int i = 0; i < k; ++ i){
            std::cin >> num[i];
            sum += num[i];
        }
        const int N = 60;
        std::vector <ll> fib(N);
        fib[0] = fib[1] = 1;
        for (int i = 2; i < N; ++ i){
            fib[i] = fib[i - 1] + fib[i - 2];
        }
        // std::cout << fib.back() << '\n';
        ll tot = 0;
        int n = 0;
        for (int i = 0; i < N; ++ i){
            tot += fib[i];
            if (tot == sum){
                n = i + 1;
                break;
            }
        }
        if (n == 0){
            std::cout << "NO\n";
            return;
        }
        std::vector <int> cnt(N);
        std::vector <int> cnt1(N);
        for (int i = 0; i < k; ++ i){
            for (int j = N - 1; j >= 0; -- j){
                if (num[i] > fib[j]){
                    ++ cnt[j];
                    num[i] -= fib[j];
                }
                else if (num[i] == fib[j]){
                    if (j % 2 == 0){
                        ++ cnt[j];
                    }
                    else{
                        ++ cnt1[j];
                    }
                    break;
                }
            }
        }
        for (int i = 0; i < N; ++ i){
            if (cnt[i] >= 2 || cnt[i] + cnt1[i] > 2){
                std::cout << "NO\n";
                return;
            }
        }
        for (int i = N - 1; i >= 0; -- i){
            if (cnt1[i] == 2){
                ++ cnt[i];
                for (int j = i - 1; j >= 0; j -= 2){
                    ++ cnt[j];
                }
            }
            else if (cnt1[i] == 1){
                if (cnt[i] == 0 && i < n){
                    ++ cnt[i];
                }
                else{
                    for (int j = i - 1; j >= 0; j -= 2){
                        ++ cnt[j];
                    }
                }
            }
        }
        for (int i = 0; i < n; ++ i){
            if (cnt[i] != 1){
                std::cout << "NO\n";
                return;
            }
        }
        for (int i = n; i < N; ++ i){
            if (cnt[i] != 0){
                std::cout << "NO\n";
                return;
            }
        }
        std::cout << "YES\n";
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