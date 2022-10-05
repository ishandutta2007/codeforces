#include <bits/stdc++.h>

const int N = 100010;
const int BIT = 18;

std::vector <int> e[N];
int fa[N][BIT], dep[N];

void dfs(int u, int fa){
    ::fa[u][0] = fa;
    for (int i = 1; i < BIT; ++ i){
        ::fa[u][i] = ::fa[::fa[u][i - 1]][i - 1];
    }
    for (auto v : e[u]){
        if (v != fa){
            dep[v] = dep[u] + 1;
            dfs(v, u);
        }
    }
}

int calc(int u, int v){
    int uu = u, vv = v;
    if (dep[u] < dep[v]){
        std::swap(u, v);
    }
    for (int i = 0; i < BIT; ++ i){
        if ((dep[u] - dep[v]) >> i & 1){
            u = fa[u][i];
        }
    }
    if (u != v){
        for (int i = BIT - 1; i >= 0; -- i){
            if (fa[u][i] != fa[v][i]){
                u = fa[u][i];
                v = fa[v][i];
            }
        }
        u = fa[u][0], v = fa[v][0];
    }
    return dep[uu] + dep[vv] - 2 * dep[u];
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0, u, v; i < n - 1; ++ i){
        scanf("%d%d", &u, &v);
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    dfs(1, 0);
    int q;
    scanf("%d", &q);
    while (q --){
        int x, y, a, b, k;
        scanf("%d%d%d%d%d", &x, &y, &a, &b, &k);
        int dis = calc(a, b);
        if (k >= dis && k % 2 == dis % 2){
            puts("YES");
            continue;
        }
        dis = std::min(calc(a, x) + calc(b, y), calc(a, y) + calc(b, x)) + 1;
        if (k >= dis && k % 2 == dis % 2){
            puts("YES");
            continue;
        }
        puts("NO");
    }
    return 0;
}