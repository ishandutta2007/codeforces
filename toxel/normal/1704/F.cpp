//
// Created by  on 2022/7/31.
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

const int MAX = 500'010;
int sg[MAX] = {};
int sg1[MAX] = {};

class Solver{
public:
    void solve(){
        int n;
        std::string str;
        std::cin >> n >> str;
        int cnt[2] = {};
        for (int i = 0; i < n; ++ i){
            if (str[i] == 'R'){
                ++ cnt[0];
            }
            else{
                ++ cnt[1];
            }
        }
        if (cnt[0] >= cnt[1] + 1){
            std::cout << "Alice\n";
        }
        else if (cnt[1] >= cnt[0] + 1){
            std::cout << "Bob\n";
        }
        else{
            int count = 0, sg_value = 0;
            for (int i = 1; i <= n; ++ i){
                if (i < n && str[i] != str[i - 1]){
                    ++ count;
                }
                else{
                    sg_value ^= sg1[count + 1];
                    count = 0;
                }
            }
            std::cout << (sg_value ? "Alice\n" : "Bob\n");
        }
    }
};

int main(){
    /*for (int i = 2; i < MAX; ++ i){
        std::set <int> set;
        for (int j = 0; j + 2 <= i; ++ j){
            set.emplace(sg[j] ^ sg[i - j - 2]);
        }
        for (int j = 0; ; ++ j){
            if (!set.count(j)){
                sg[i] = j;
                break;
            }
        }
        std::cout << "sg[" << i << "] = " << sg[i] << '\n';
    }*/
    int vis[20];
    // int max = 0;
    /*for (int i = 2; i < MAX; ++ i){
        memset(vis, 0, sizeof vis);
        for (int j = 0; j <= 100 && j + 2 <= i; ++ j){
            vis[sg[j] ^ sg[i - j - 2]] = 1;
        }
        for (int j = 0; ; ++ j){
            if (!vis[j]){
                sg[i] = j;
                break;
            }
        }
    }*/
    for (int i = 2; i < MAX; ++ i){
        memset(vis, 0, sizeof vis);
        for (int j = 0; j <= 80 && j + 2 <= i; ++ j){
            vis[sg1[j] ^ sg1[i - j - 2]] = 1;
        }
        for (int j = 0; ; ++ j){
            if (!vis[j]){
                sg1[i] = j;
                break;
            }
        }
        // max = std::max(max, sg1[i]);
        // assert(sg[i] == sg1[i]);
    }
    // std::cout << max << '\n';
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