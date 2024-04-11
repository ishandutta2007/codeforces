//
// Created by  on 2022/3/3.
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
        int k;
        std::cin >> k;
        const int BIT = 6;
        std::vector <ll> value(BIT);
        for (int i = 0; i < BIT; ++ i){
            std::cin >> value[i];
        }
        std::vector <int> power(BIT);
        power[0] = 1;
        for (int i = 1; i < BIT; ++ i){
            power[i] = 10 * power[i - 1];
        }
        const int UP = power.back() * 10;
        std::vector <ll> dp(UP, -1);
        dp[0] = 0;
        for (int i = 0; i < BIT; ++ i){
            std::vector <ll> ndp(UP, -1);
            // k 9 or (k - 1) 9
            for (int j = 0; j < UP; ++ j){
                if (dp[j] == -1){
                    continue;
                }
                for (int K = 0; K <= 9; ++ K){
                    ll num = j + 1ll * power[i] * (9 * (k - 1) + K);
                    if (num < UP){
                        ll val = (k - 1) * 3 * value[i] + (K % 3 == 0 ? (K / 3) * value[i] : 0);
                        ndp[num] = std::max(ndp[num], dp[j] + val);
                    }
                }
            }
            if (k >= 2){
                // <= (k - 2) 9
                std::vector <ll> nndp(UP, -1);
                for (int j = 0; j < UP; ++ j){
                    if (dp[j] == -1){
                        continue;
                    }
                    for (int K = 0; K <= 9; K += 3){
                        for (int u = 0; u <= 9; ++ u){
                            int num = j + power[i] * (K + u);
                            if (num < UP){
                                ll val = (K / 3) * value[i] + (u % 3 == 0 ? (u / 3) * value[i] : 0);
                                nndp[num] = std::max(nndp[num], dp[j] + val);
                            }
                        }
                    }
                }
                int w = 9 * power[i];
                ll v = 3 * value[i];
                for (int j = 0; j < w; ++ j){
                    std::deque <int> deque;
                    for (int K = j; K < UP; K += w){
                        if (!deque.empty() && deque.front() == K - 1ll * (k - 2 + 1) * w){
                            deque.pop_front();
                        }
                        if (nndp[K] != -1){
                            while (!deque.empty()){
                                int pos = deque.back();
                                if (nndp[pos] - (pos / w) * v <= nndp[K] - (K / w) * v){
                                    deque.pop_back();
                                }
                                else{
                                    break;
                                }
                            }
                            deque.emplace_back(K);
                        }
                        if (!deque.empty()){
                            int pos = deque.front();
                            ndp[K] = std::max(ndp[K], nndp[pos] + ((K - pos) / w) * v);
                        }
                    }
                }
            }
            dp = ndp;
        }
        int test;
        std::cin >> test;
        while (test --){
            int num;
            std::cin >> num;
            std::cout << dp[num] << '\n';
        }
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