#include <bits/stdc++.h>

const int N = 200010;
using ll = long long;

std::vector <int> e[N];
int dep[N], son[N], maxdep[N], top[N];
bool leaf[N];

void dfs(int u, int fa){
    leaf[u] = true;
    for (auto v : e[u]){
        if (v == fa){
            continue;
        }
        dep[v] = dep[u] + 1;
        leaf[u] = false;
        dfs(v, u);
        if (son[u] == 0 || maxdep[v] > maxdep[u]){
            son[u] = v;
        }
        maxdep[u] = std::max(maxdep[u], maxdep[v]);
    }
    maxdep[u] += 1;
}

void gettop(int u, int fa, int tp){
    top[u] = tp;
    if (son[u]){
        gettop(son[u], u, tp);
    }
    for (auto v : e[u]){
        if (v == fa || v == son[u]){
            continue;
        }
        gettop(v, u, v);
    }
}

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n - 1; ++ i){
        int u, v;
        scanf("%d%d", &u, &v);
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    dfs(1, 0);
    gettop(1, 0, 1);
    std::vector <int> vec;
    for (int i = 1; i <= n; ++ i){
        if (leaf[i]){
            vec.emplace_back(dep[i] - dep[top[i]] + 1);
        }
    }
    std::sort(vec.begin(), vec.end(), std::greater <int>());
    int sz = vec.size();
    int cur = 0;
    ll ans = LLONG_MIN;
    for (int i = 0; i <= k; ++ i){
        if (1 <= i && i <= sz){
            cur += vec[i - 1];
        }
        int bmax = n - cur;
        bmax = std::min(bmax, n / 2);
        ans = std::max(ans, 1ll * bmax * bmax - 1ll * n * bmax + 1ll * (n - i) * i);
    }
    printf("%lld\n", ans);
    return 0;
}