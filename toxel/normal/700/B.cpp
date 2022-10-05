#include<bits/stdc++.h>

typedef long long ll;
const int N = 200010;

std::vector <int> e[N];
bool flag[N];
int sz[N];

void dfs(int u, int fa){
    sz[u] = flag[u];
    for (auto v : e[u]){
        if (v == fa) continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
}

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0, x; i < 2 * k; ++ i){
        scanf("%d", &x);
        flag[x] = true;
    }
    for (int i = 0; i < n - 1; ++ i){
        int u, v;
        scanf("%d%d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    ll ans = 0;
    for (int i = 1; i <= n; ++ i){
        ans += std::min(sz[1] - sz[i], 2 * k - (sz[1] - sz[i]));
    }
    printf("%lld\n", ans);
    return 0;
}