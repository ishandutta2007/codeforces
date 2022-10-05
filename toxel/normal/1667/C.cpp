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

const int N = 100;

int cnt[N][N], vis[N][N];
int ans = INT_MAX;

void dfs(int pos, int n, int cur){
    if (cur >= ans){
        return;
    }
    bool done = true;
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < n; ++ j){
            if (!cnt[i][j]){
                done = false;
            }
        }
    }
    if (done){
        ans = std::min(ans, cur);
        for (int i = 0; i < n; ++ i){
            for (int j = 0; j < n; ++ j){
                std::cout << vis[i][j];
            }
            std::cout << '\n';
        }
        std::cout << '\n';
        return;
    }
    if (pos == n * n){
        return;
    }
    int x = pos / n, y = pos % n;
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < n; ++ j){
            if (i == x || j == y || i - x == j - y){
                ++ cnt[i][j];
            }
        }
    }
    vis[x][y] = 1;
    dfs(pos + 1, n, cur + 1);
    vis[x][y] = 0;
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < n; ++ j){
            if (i == x || j == y || i - x == j - y){
                -- cnt[i][j];
            }
        }
    }
    dfs(pos + 1, n, cur);
}

class Solver{
public:
    void solve(){
        /*dfs(0, 8, 0);
        std::cout << ans << '\n';*/
        int n;
        std::cin >> n;
        std::vector <pii> output;
        if (n % 3 == 1 || n % 3 == 2){
            ans = n / 3 * 2 + 1;
            for (int i = 1, j = 1, cnt = 0; cnt < ans / 2 + 1; i += 1, j += 2, cnt += 1){
                output.emplace_back(i, j);
            }
            for (int i = ans / 2 + 2, j = 2; i < ans / 2 + 2 + ans / 2; i += 1, j += 2){
                output.emplace_back(i, j);
            }
        }
        else{
            ans = n / 3 * 2;
            for (int i = 1, j = 1, cnt = 0; cnt < ans / 2; i += 1, j += 2, cnt += 1){
                output.emplace_back(i, j);
            }
            for (int i = ans / 2 + 1, j = 2; i < ans / 2 + 1 + ans / 2; i += 1, j += 2){
                output.emplace_back(i, j);
            }
        }
        std::cout << output.size() << '\n';
        for (auto [u, v]: output){
            /*-- u, -- v;
            for (int i = 0; i < n; ++ i){
                for (int j = 0; j < n; ++ j){
                    if (i == u || j == v || i - u == j - v){
                        ++ cnt[i][j];
                    }
                }
            }*/
            std::cout << u << " " << v << '\n';
        }
        /*for (int i = 0; i < n; ++ i){
            for (int j = 0; j < n; ++ j){
                assert(cnt[i][j] > 0);
            }
        }*/
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
    std::cout << std::fixed << std::setprecision(18) << '\n';
    return 0;
}

#endif //WORKSPACE_TEMPLATE_H

/*
10000000
00100000
00001000
01000000
00010000
00000000
00000000
00000000
 */