//
// Created by  on 2022/6/25.
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

const int N = 110;

bool vis[N][N][N];
int dis[N][N];
bool vis1[N];

class Solver{
public:
    std::vector <int> e[N];
    bool global_flag;

    void dfs(int u, int rt, int fa){
        if (vis1[u]){
            global_flag = false;
            return;
        }
        vis1[u] = true;
        for (auto v : e[u]){
            if (v == fa){
                continue;
            }
            dis[rt][v] = dis[rt][u] + 1;
            dfs(v, rt, u);
        }
    }

    void solve(){
        int n;
        std::cin >> n;
        for (int i = 1; i < n; ++ i){
            for (int j = i + 1; j <= n; ++ j){
                std::string str;
                std::cin >> str;
                for (int k = 0; k < n; ++ k){
                    vis[j][i][k + 1] = vis[i][j][k + 1] = str[k] - '0';
                }
            }
        }
        for (int i = 2; i <= n; ++ i){
            for (int j = 0; j < N; ++ j){
                e[j].clear();
            }
            std::vector <int> fa(n + 1), queue;
            for (int j = 2; j <= n; ++ j){
                if (vis[i][j][1] || i == j){
                    fa[j] = 1;
                    queue.emplace_back(j);
                    e[1].emplace_back(j);
                    e[j].emplace_back(1);
                }
            }
            bool flag = true;
            while (!queue.empty()){
                int u = queue.back();
                queue.pop_back();
                for (int k = 1; k <= n; ++ k){
                    if (k == fa[u]){
                        continue;
                    }
                    if (vis[k][fa[u]][u]){
                        if (fa[k]){
                            flag = false;
                            break;
                        }
                        fa[k] = u;
                        e[u].emplace_back(k);
                        e[k].emplace_back(u);
                        queue.emplace_back(k);
                    }
                }
                if (!flag){
                    break;
                }
            }
            if (!flag){
                continue;
            }
            int sz = 0;
            for (int i = 1; i <= n; ++ i){
                sz += e[i].size();
            }
            if (sz != 2 * (n - 1)){
                goto end;
            }
            global_flag = true;
            for (int i = 1; i <= n; ++ i){
                dis[i][i] = 0;
                memset(vis1, 0, sizeof vis1);
                dfs(i, i, 0);
            }
            if (!global_flag){
                goto end;
            }
            for (int i = 1; i < n; ++ i){
                for (int j = i + 1; j <= n; ++ j){
                    for (int k = 1; k <= n; ++ k){
                        if ((dis[i][k] == dis[j][k]) != vis[i][j][k]){
                            goto end;
                        }
                    }
                }
            }
            std::cout << "Yes\n";
            for (int i = 1; i <= n; ++ i){
                for (auto v : e[i]){
                    if (i < v){
                        std::cout << i << " " << v << "\n";
                    }
                }
            }
            return;
            end:;
        }
        std::cout << "No\n";
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