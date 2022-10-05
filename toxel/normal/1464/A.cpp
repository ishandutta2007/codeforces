#include <bits/stdc++.h>

const int N = 100010;

std::vector<int> e[N];
bool vis[N];
int cnt;
bool ring;

void dfs(int u, int fa){
    ++ cnt;
    vis[u] = true;
    for (auto v : e[u]){
        if (v == fa){
            continue;
        }
        if (!vis[v]){
            dfs(v, u);
        }
        else{
            ring = true;
        }
    }
}

void solve(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n; ++ i){
        e[i].clear();
        vis[i] = false;
    }
    for (int i = 1; i <= m; ++ i){
        int x, y;
        scanf("%d%d", &x, &y);
        e[x].emplace_back(y);
        e[y].emplace_back(x);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++ i){
        if (!vis[i]){
            cnt = 0;
            ring = false;
            dfs(i, 0);
            if (cnt == 1){
                continue;
            }
            if (ring){
                ans += cnt + 1;
            }
            else{
                ans += cnt - 1;
            }
        }
    }
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