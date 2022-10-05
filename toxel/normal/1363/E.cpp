#include <bits/stdc++.h>

const int N = 200010;
using ll = long long;

int a[N], b[N], c[N];
std::vector<int> e[N];
int type1[N], type2[N];
ll ans = 0;

void dfs(int u, int fa){
    if (b[u] == 1 && c[u] == 0){
        type1[u] = 1;
    }
    if (b[u] == 0 && c[u] == 1){
        type2[u] = 1;
    }
    for (auto v : e[u]){
        if (v == fa){
            continue;
        }
        a[v] = std::min(a[v], a[u]);
        dfs(v, u);
        type1[u] += type1[v];
        type2[u] += type2[v];
    }
    int x = std::min(type1[u], type2[u]);
    ans += 1ll * x * a[u];
    type1[u] -= x, type2[u] -= x;
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        scanf("%d%d%d", &a[i], &b[i], &c[i]);
    }
    for (int i = 0; i < n - 1; ++ i){
        int u, v;
        scanf("%d%d", &u, &v);
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    dfs(1, 0);
    if (type1[1] != type2[1]){
        puts("-1");
        return 0;
    }
    printf("%lld\n", 2 * ans);
    return 0;
}