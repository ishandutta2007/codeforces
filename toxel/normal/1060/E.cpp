#include<bits/stdc++.h>

const int N = 200010;
typedef long long ll;

int sz[N], dep[N], cnt[2];
std::vector <int> e[N];
ll ans;
int n;

void dfs(int u, int fa){
    sz[u] = 1;
    ++ cnt[dep[u] & 1];
    for (auto v : e[u]){
        if (v == fa) continue;
        dep[v] = dep[u] + 1;
        dfs(v, u);
        sz[u] += sz[v];
        ans += 1ll * sz[v] * (n - sz[v]);
    }
}

int main(){
    scanf("%d", &n);
    for (int i = 0, u, v; i < n - 1; ++ i){
        scanf("%d%d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    ans += 1ll * cnt[0] * cnt[1];
    printf("%lld\n", ans >> 1);
    return 0;
}