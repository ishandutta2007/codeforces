#include <bits/stdc++.h>

const int N = 200010;
const int BIT = 18;
using ll = long long;

std::vector <int> e[N];
int p[N], a[N], b[N], fa[N], father[N][BIT];
ll fa_value[N][BIT];
ll w[N], dp[N], diff[N];
int dep[N], dfn[N], dfncnt;
bool vis[N];

void dfs(int u){
    dfn[u] = ++ dfncnt;
    dp[u] = w[u];
    for (auto v : e[u]){
        dep[v] = dep[u] + 1;
        dfs(v);
        dp[u] += dp[v];
    }
    dp[u] = std::min(0ll, dp[u]);
}

void dfs1(int u, int fat){
    father[u][0] = fat;
    fa_value[u][0] = diff[u];
    for (int i = 1; i < BIT; ++ i){
        if (father[u][i - 1] == -1){
            father[u][i] = -1;
            fa_value[u][i] = fa_value[u][i - 1];
            continue;
        }
        father[u][i] = father[father[u][i - 1]][i - 1];
        fa_value[u][i] = fa_value[u][i - 1] + fa_value[father[u][i - 1]][i - 1];
    }
    for (auto v : e[u]){
        dfs1(v, u);
    }
}

int lca(int u, int v){
    if (dep[u] < dep[v]){
        std::swap(u, v);
    }
    for (int i = 0; i < BIT; ++ i){
        if ((dep[u] - dep[v]) >> i & 1){
            u = father[u][i];
        }
    }
    if (u == v) return u;
    for (int i = BIT - 1; i >= 0; -- i){
        if (father[u][i] != father[v][i]){
            u = father[u][i], v = father[v][i];
        }
    }
    return father[u][0];
}

struct Compare{
    bool operator () (const int &p1, const int &p2)const{
        return dfn[p1] < dfn[p2];
    }
};

int main(){
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &p[i]);
    }
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &b[i]);
    }
    std::vector <int> stack;
    p[0] = n + 1;
    for (int i = 0; i <= n; ++ i){
        while (!stack.empty() && p[stack.back()] < p[i]){
            stack.pop_back();
        }
        if (i){
            e[stack.back()].emplace_back(i);
            fa[i] = stack.back();
        }
        stack.emplace_back(i);
    }
    for (int i = 0; i <= n; ++ i){
        w[i] = a[i] - b[i];
        for (auto u : e[i]){
            w[i] += b[u];
        }
    }
    dfs(0);
    for (int i = 0; i <= n; ++ i){
        diff[i] = -dp[i] + w[i];
        for (auto u : e[i]){
            diff[i] += dp[u];
        }
    }
    dfs1(0, -1);
    ll cur = dp[0] + diff[0];
    std::map <int, int, Compare> map;
    map[0] = 1;
    while (q --){
        int node;
        scanf("%d", &node);
        int coe = vis[node] ? -1 : 1;
        if (!vis[node]){
            vis[node] = true;
            node = fa[node];
            map[node] += 1;
            if (map[node] >= 2){
                printf("%lld\n", cur);
                continue;
            }
        }
        else{
            vis[node] = false;
            node = fa[node];
            map[node] -= 1;
            if (map[node] >= 1){
                printf("%lld\n", cur);
                continue;
            }
            map.erase(node);
        }
        auto u = map.upper_bound(node);
        int x = u == map.end() ? -1 : u -> first;
        u = map.lower_bound(node);
        int y = u == map.begin() ? -1 : std::prev(u) -> first;
        if (x != -1){
            x = lca(x, node);
        }
        if (y != -1){
            y = lca(y, node);
        }
        if (x == -1 && y == -1){
            cur = dp[0] + diff[0];
            printf("%lld\n", cur);
            continue;
        }
        if (x == -1 || (y != -1 && dep[x] < dep[y])){
            x = y;
        }
        if (x == node){
            printf("%lld\n", cur);
            continue;
        }
        int dep_diff = dep[node] - dep[x];
        for (int i = 0; i < BIT; ++ i){
            if (dep_diff >> i & 1){
                cur += coe * fa_value[node][i];
                node = father[node][i];
            }
        }
        printf("%lld\n", cur);
    }
    return 0;
}