#include <bits/stdc++.h>

const int N = 100010;

std::vector<int> e[N];
int p[N], h[N];
int good[N], bad[N], sz[N];
bool flag;

void dfs(int u, int fa){
    sz[u] = p[u];
    for (auto v : e[u]){
        if (v == fa){
            continue;
        }
        dfs(v, u);
        sz[u] += sz[v];
    }
    if ((sz[u] & 1) != (h[u] & 1)){
        flag = false;
        return;
    }
    good[u] = (sz[u] + h[u]) / 2;
    bad[u] = sz[u] - good[u];
    if (good[u] < 0 || bad[u] < 0){
        flag = false;
    }
}

void check(int u, int fa){
    int sum = 0;
    for (auto v : e[u]){
        if (v == fa){
            continue;
        }
        check(v, u);
        sum += good[v];
    }
    sum += std::max(p[u] - bad[u], 0);
    if (sum > good[u]){
        flag = false;
    }
}

void solve(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n; ++ i){
        e[i].clear();
    }
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &p[i]);
    }
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &h[i]);
    }
    for (int i = 0, u, v; i < n - 1; ++ i){
        scanf("%d%d", &u, &v);
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    flag = true;
    dfs(1, 0);
    if (flag == false){
        puts("NO");
        return;
    }
    check(1, 0);
    puts(flag ? "YES" : "NO");
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}