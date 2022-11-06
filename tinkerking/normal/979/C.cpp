#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 3e5 + 10;
int sz[MAXN], fa[MAXN];
vector<int> E[MAXN];
int n, x, y;

void dfs(int u, int f){
    fa[u] = f;
    sz[u] = 1;
    for (auto &v : E[u])
        if (v != f){
            dfs(v, u);
            sz[u] += sz[v];
        }
}

int main(){
    scanf("%d%d%d", &n, &x, &y);
    for (int i = 1; i < n; ++i){
        int u, v;
        scanf("%d%d", &u, &v);
        E[u].push_back(v);
        E[v].push_back(u);
    }
    dfs(x, 0);
    ll ans = 1ll * n * (n - 1);
    int z = y;
    while (fa[z] != x)
        z = fa[z];
    ans -= 1ll * (n - sz[z]) * sz[y];
    printf("%lld\n", ans);
    return 0;
}