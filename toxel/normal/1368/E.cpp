#include <bits/stdc++.h>

const int N = 200010;

std::vector<int> e[N];
int dep[N], vis[N];

void solve(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n; ++ i){
        e[i].clear();
        dep[i] = 0;
        vis[i] = false;
    }
    for (int i = 0, u, v; i < m; ++ i){
        scanf("%d%d", &u, &v);
        e[u].emplace_back(v);
    }
    for (int i = 1; i <= n; ++ i){
        if (dep[i] == 2){
            vis[i] = true;
            continue;
        }
        for (auto v : e[i]){
            dep[v] = std::max(dep[v], dep[i] + 1);
        }
    }
    std::vector<int> ans;
    for (int i = 1; i <= n; ++ i){
        if (vis[i]){
            ans.emplace_back(i);
        }
    }
    int sz = ans.size();
    printf("%d\n", sz);
    for (int i = 0; i < sz; ++ i){
        printf("%d%c", ans[i], " \n"[i == sz - 1]);
    }
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}