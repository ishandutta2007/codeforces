//
// Created by  on 2022/5/20.
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
// using Mint = Mod<int, UNDEFINED>;

class Solver{
public:
    std::string s;
    std::vector <int> divide;

    int search(int l, int r, int k){
        for (int i = l; i <= r; ++ i){
            k -= s[i] == '1';
            if (k == 0){
                return i;
            }
        }
        return -1;
    }

    void dfs(int l, int r, int n){
        int cnt1 = 0;
        for (int i = l; i <= r; ++ i){
            cnt1 += s[i] == '1';
        }
        if ((cnt1 == 1 || cnt1 == 2 || cnt1 == 4) && (n == -1 || n == cnt1)){
            for (int i = l; i <= r; ++ i){
                divide[i] = 1;
            }
            return;
        }
        if (cnt1 == 5 && n == -1){
            for (int i = l; i <= r - 4; ++ i){
                if (s.substr(i, 5) == "11111"){
                    for (int j = l; j <= r; ++ j){
                        if (j <= i || j >= i + 4){
                            divide[j] = 1;
                        }
                    }
                    return;
                }
            }
            for (int i = l; i <= r - 2; ++ i){
                auto str = s.substr(i, 3);
                if (str == "101" || str == "100"){
                    for (int j = l; j <= r; ++ j){
                        if (j < i || j >= i + 2){
                            divide[j] = 1;
                        }
                    }
                    return;
                }
            }
            return;
        }
        int upper = 1;
        while (upper < cnt1){
            upper <<= 1;
        }
        if (n == -1){
            n = upper;
        }
        if (upper == cnt1){
            if (n == cnt1){
                for (int i = l; i <= r; ++ i){
                    divide[i] = 1;
                }
                return;
            }
            if (n == 2 * cnt1){
                if (cnt1 >= 8){
                    int pos = search(l, r, cnt1 / 2);
                    dfs(l, pos, n / 2);
                    divide[pos] = 1;
                    dfs(pos + 1, r, n / 2);
                    return;
                }
                // cnt1 = 4, n = 8
                int pos = search(l, r, 1);
                std::string str = s.substr(pos, 3);
                divide[pos + 2] = 1;
                if (str == "111"){
                    for (int i = l; i <= r; ++ i){
                        if (i < pos || i >= pos + 2){
                            divide[i] = 1;
                        }
                    }
                }
                else{
                    for (int i = l; i < pos; ++ i){
                        divide[i] = 1;
                    }
                    if (str == "110"){
                        dfs(pos + 3, r, 2);
                    }
                    else if (str == "101"){
                        dfs(pos + 3, r, 3);
                    }
                    else{
                        assert(str == "100");
                        dfs(pos + 3, r, 4);
                    }
                }
                return;
            }
        }
        if (n == 2 * (cnt1 - 1)){
            if (cnt1 > 9){
                int pos = search(l, r, n / 4);
                dfs(l, pos, n / 2);
                divide[pos] = 1;
                dfs(pos + 1, r, n / 2);
                return;
            }
        }
        if (cnt1 >= 12){
            int pos = search(l, r, cnt1 / 2);
            dfs(l, pos, upper / 2);
            divide[pos] = 1;
            dfs(pos + 1, r, upper / 2);
            return;
        }
        if (cnt1 / 2 * 3 + cnt1 % 2 >= n){
            if (cnt1 < n){
                int pos = search(l, r, 1);
                for (int i = l; i < pos; ++ i){
                    divide[i] = 1;
                }
                std::string str = s.substr(pos, 2);
                divide[pos + 1] = 1;
                if (str == "10"){
                    dfs(pos + 2, r, n - 2);
                }
                else if (str == "11"){
                    dfs(pos + 2, r, n - 3);
                }
                else{
                    assert(false);
                }
            }
            else{
                for (int i = l; i <= r; ++ i){
                    divide[i] = 1;
                }
            }
            return;
        }
        if (cnt1 == 9){
            int pos = search(l, r, 1);
            std::string str = s.substr(pos, 3);
            divide[pos + 2] = 1;
            for (int i = l; i < pos; ++ i){
                divide[i] = 1;
            }
            if (str == "111"){
                dfs(pos + 3, r, 9);
            }
            else if (str == "110"){
                dfs(pos + 3, r, 10);
            }
            else if (str == "101"){
                dfs(pos + 3, r, 11);
            }
            else{
                assert(str == "100");
                dfs(pos + 3, r, 12);
            }
            return;
        }
        if (cnt1 == 7 && n == 11){
            int pos = search(l, r, 1);
            std::string str = s.substr(pos, 3);
            divide[pos + 2] = 1;
            for (int i = l; i < pos; ++ i){
                divide[i] = 1;
            }
            if (str == "111"){
                dfs(pos + 3, r, 4);
            }
            else if (str == "110"){
                dfs(pos + 3, r, 5);
            }
            else if (str == "101"){
                dfs(pos + 3, r, 6);
            }
            else{
                assert(str == "100");
                dfs(pos + 3, r, 7);
            }
            return;
        }
        if (cnt1 == 10){
            int pos = search(l, r, 1);
            std::string str = s.substr(pos, 3);
            divide[pos + 2] = 1;
            for (int i = l; i < pos; ++ i){
                divide[i] = 1;
            }
            if (str == "111"){
                dfs(pos + 3, r, 9);
            }
            else if (str == "110"){
                dfs(pos + 3, r, 10);
            }
            else if (str == "101"){
                dfs(pos + 3, r, 11);
            }
            else{
                assert(str == "100");
                dfs(pos + 3, r, 12);
            }
            return;
        }
        assert(false);
    }

    void solve(){
        std::cin >> s;
        int sz = s.size();
        bool has1 = false;
        for (int i = 0; i < sz; ++ i){
            if (s[i] == '1'){
                has1 = true;
                break;
            }
        }
        if (!has1){
            std::cout << "-1\n";
            return;
        }
        divide.resize(sz + 1);
        dfs(0, sz - 1, -1);
        std::vector <int> ans;
        for (int i = 0; i < sz - 1; ++ i){
            if (divide[i]){
                ans.emplace_back(i + 1);
            }
        }
        if (ans.empty()){
            std::cout << "1\n";
            std::cout << 1 << " " << int(s.size()) << '\n';
            return;
        }
        std::vector <pii> ans1;
        sz = ans.size();
        ans1.emplace_back(1, ans.front());
        for (int i = 0; i < sz - 1; ++ i){
            ans1.emplace_back(ans[i] + 1, ans[i + 1]);
        }
        ans1.emplace_back(ans.back() + 1, int(s.size()));
        std::cout << ans1.size() << '\n';
        for (auto [l, r]: ans1){
            std::cout << l << " " << r << '\n';
        }
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