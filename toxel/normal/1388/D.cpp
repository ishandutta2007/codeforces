#include <bits/stdc++.h>

using ll = long long;
const int N = 200010;

ll a[N];
int b[N];
std::vector<int> ans;
std::vector<int> e[N];
bool vis[N];
ll ans1;

void dfs(int u){
    for (auto v : e[u]){
        dfs(v);
    }
    if (a[u] > 0){
        ans.emplace_back(u);
        vis[u] = true;
        ans1 += a[u];
        if (b[u] != -1){
            a[b[u]] += a[u];
        }
    }
}

void dfs1(int u){
    if (!vis[u]){
        ans.emplace_back(u);
        ans1 += a[u];
    }
    for (auto v : e[u]){
        dfs1(v);
    }
}

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        scanf("%lld", &a[i]);
    }
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &b[i]);
        if (b[i] != -1){
            e[b[i]].emplace_back(i);
        }
    }
    for (int i = 1; i <= n; ++ i){
        if (b[i] == -1){
            dfs(i);
            dfs1(i);
        }
    }
    printf("%lld\n", ans1);
    for (int i = 0; i < n; ++ i){
        printf("%d%c", ans[i], " \n"[i == n - 1]);
    }
}

int main(){
    solve();
    return 0;
}