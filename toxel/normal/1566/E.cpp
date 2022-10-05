#include <bits/stdc++.h>

const int N = 200010;

std::vector <int> e[N];
int ans;

bool dfs(int u, int fa){
    int son = 0;
    for (auto v : e[u]){
        if (v == fa){
            continue;
        }
        bool flag = dfs(v, u);
        if (!flag){
            ++ son;
        }
    }
    if (u == 1){
        ans += std::max(son, 1);
    }
    else{
        ans += std::max(0, son - 1);
    }
    return son > 0;
}

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i <= n; ++ i){
        e[i].clear();
    }
    for (int i = 0, u, v; i < n - 1; ++ i){
        scanf("%d%d", &u, &v);
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    ans = 0;
    dfs(1, 0);
    printf("%d\n", ans);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}