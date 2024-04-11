//
// Created by  on 2022/9/6.
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
    int n;
    std::string str;
    std::vector <int> match;
    int ans;

    void dfs(int l, int r){
        if (l > r){
            return;
        }
        ++ ans;
        for (int i = l; i <= r; i = match[i] + 1){
            dfs(i + 1, match[i] - 1);
        }
    }

    void solve(){
        std::cin >> n >> str;
        std::vector <int> stack;
        match.resize(2 * n);
        for (int i = 0; i < 2 * n; ++ i){
            if (str[i] == '('){
                stack.emplace_back(i);
            }
            else{
                match[stack.back()] = i;
                stack.pop_back();
            }
        }
        ans = 0;
        dfs(0, 2 * n - 1);
        std::cout << ans << '\n';
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