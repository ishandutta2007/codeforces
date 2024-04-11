//
// Created by  on 2022/2/3.
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

const int N = 1010;
std::vector <int> e[N];
int a[N], b[N];

bool check(int mid, int n){
    std::vector <int> vis(n + 1), pre(n + 1);
    vis[1] = true;
    int sz = 1;
    while (sz < n){
        std::queue <int> q;
        std::vector <bool> vis1(n + 1);
        ll sum = mid;
        for (int i = 1; i <= n; ++ i){
            if (vis[i]){
                q.emplace(i);
                vis1[i] = true;
                sum += b[i];
            }
        }
        std::vector <ll> dis(n + 1, sum);
        bool found = false;
        int x = -1, y = -1;
        while (!q.empty()){
            int u = q.front();
            q.pop();
            for (auto v : e[u]){
                if (vis[u] && vis[v]){
                    continue;
                }
                if (v == pre[u]){
                    continue;
                }
                if (dis[u] <= a[v]){
                    continue;
                }
                if (vis1[v]){
                    x = v, y = u;
                    found = true;
                    break;
                }
                vis1[v] = true;
                q.push(v);
                dis[v] = dis[u] + b[v];
                pre[v] = u;
            }
            if (found){
                break;
            }
        }
        if (!found){
            break;
        }
        while (x){
            vis[x] = 1;
            x = pre[x];
        }
        while (y){
            vis[y] = 1;
            y = pre[y];
        }
        sz = 0;
        for (int i = 1; i <= n; ++ i){
            sz += vis[i];
        }
    }
    return sz == n;
}

void solve(){
    int n, m;
    std::cin >> n >> m;
    for (int i = 2; i <= n; ++ i){
        std::cin >> a[i];
    }
    for (int i = 2; i <= n; ++ i){
        std::cin >> b[i];
    }
    for (int i = 0; i < N; ++ i){
        e[i].clear();
    }
    for (int i = 0; i < m; ++ i){
        int u, v;
        std::cin >> u >> v;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    int l = 0, r = int(1e9) + 1;
    while (l < r){
        int mid = (l + r) / 2;
        if (check(mid, n)){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    std::cout << l << '\n';
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int test;
    std::cin >> test;
    while (test --){
        solve();
    }
    return 0;
}

#endif //WORKSPACE_TEMPLATE_H