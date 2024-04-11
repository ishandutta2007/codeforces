//
// Created by  on 2022/10/15.
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
// using Mint = Mod<UNDEFINED>;

class Solver{
public:
    int n;

    constexpr static int magic[16][2] = {
            {0,1,},
            {0,1,},
            {0,2,},
            {1,2,},
            {0,2,},
            {0,3,},
            {2,3,},
            {2,3,},
            {0,1,},
            {0,1,},
            {0,3,},
            {1,3,},
            {1,2,},
            {1,3,},
            {2,3,},
            {2,3,},
    };

    Solver(){}

    bool answer(int x){
        std::cout << "! " << x << "\n";
        std::cout.flush();
        std::string ok;
        std::cin >> ok;
        return ok == ":)";
    }

    int ask(int bit){
        std::vector <int> to_ask;
        for (int i = 1; i <= n; ++ i){
            if (i >> bit & 1){
                to_ask.emplace_back(i);
            }
        }
        std::cout << "? " << to_ask.size();
        for (auto u: to_ask){
            std::cout << " " << u;
        }
        std::cout << "\n";
        std::cout.flush();
        std::string ans;
        std::cin >> ans;
        return ans == "YES" ? 1 : 0;
    }

    void solve(){
        std::cin >> n;
        if (n == 1){
            answer(1);
            return;
        }
        const int BIT = 17;
        std::vector <int> ans(BIT);
        int rely[BIT] = {}, sign[BIT] = {};
        for (int i = 0; i < BIT; ++ i){
            ans[i] = -1;
            rely[i] = -1;
        }
        int cur_bit = 0;
        for (int i = 1; i < BIT; ++ i){
            int a = 0;
            a |= ask(cur_bit) << 0;
            a |= ask(i) << 1;
            a |= ask(i) << 2;
            a |= ask(cur_bit) << 3;
            int result = magic[a][0] ^ magic[a][1];
            if (result == 3){
                rely[cur_bit] = i;
                sign[cur_bit] = magic[a][0];
                cur_bit = i;
            }
            else if (result == 1){
                ans[i] = (magic[a][0] & magic[a][1]) >> 1;
            }
            else{
                ans[cur_bit] = magic[a][0] & magic[a][1];
                cur_bit = i;
            }
        }
        for (int i = 0; i < 2; ++ i){
            auto ans_backup = ans;
            ans[cur_bit] = i;
            for (int j = BIT - 1; j >= 0; -- j){
                if (rely[j] != -1){
                    ans[j] = ans[rely[j]] ^ sign[j];
                }
            }
            int result = 0;
            for (int j = 0; j < BIT; ++ j){
                result |= ans[j] << j;
            }
            if (1 <= result && result <= n){
                if (answer(result)){
                    return;
                }
            }
            ans = ans_backup;
        }
    }

    static void test(){
        const int ASK = 4;
        std::vector <int> ans[1 << ASK];
        int ask[ASK] = {0, 1, 1, 0};
        /*for (int i = 0; i < ASK; ++ i){
            ask[i] = basic >> i & 1;
        }*/
        for (int i = 0; i < 4; ++ i){
            for (int j = 0; j < 1 << ASK; ++ j){
                bool flag = true;
                for (int k = 0; k < ASK - 1; ++ k){
                    if ((j >> k & 1) == 1 && (j >> (k + 1) & 1) == 1){
                        flag = false;
                        break;
                    }
                }
                if (flag){
                    int result = 0;
                    for (int k = 0; k < ASK; ++ k){
                        int real = i >> ask[k] & 1;
                        real ^= j >> k & 1;
                        result |= real << k;
                    }
                    ans[result].emplace_back(i);
                }
            }
        }
        for (int i = 0; i < 1 << ASK; ++ i){
            // std::cout << i;
            std::cout << "{";
            for (auto u: ans[i]){
                std::cout << u << ",";
            }
            std::cout << "},\n";
            /*if (ans[i].size() >= 2){
                // std::cout << "BAD\n";
                return;
            }*/
        }
        // std::cout << "GOOD\n";
    }
};

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int test = 1;
    // std::cin >> test;
    // floating point number output template
    // Solver::test();
    std::cout << std::fixed << std::setprecision(18);
    while (test --){
        Solver solver;
        solver.solve();
    }
    return 0;
}

#endif //WORKSPACE_TEMPLATE_H