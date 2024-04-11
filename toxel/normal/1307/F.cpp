#include <bits/stdc++.h>

const int N = 500010;
const int BIT = 21;

std::vector <int> e[N];
int c[N], fa[N], top[N][BIT], dis[N], dep[N];

void addedge(int u, int v){
    e[u].emplace_back(v);
    e[v].emplace_back(u);
}

int find(int u){
    return fa[u] == u ? u : (fa[u] = find(fa[u]));
}

void unite(int u, int v){
    u = find(u), v = find(v);
    if (u == v){
        return;
    }
    fa[u] = v;
}

void dfs(int u, int fa){
    top[u][0] = fa;
    for (int i = 1; i < BIT; ++ i){
        top[u][i] = top[top[u][i - 1]][i - 1];
    }
    for (auto v : e[u]){
        if (v == fa){
            continue;
        }
        dep[v] = dep[u] + 1;
        dfs(v, u);
    }
}

int getlca(int u, int v){
    if (dep[u] < dep[v]){
        std::swap(u, v);
    }
    for (int i = 0; i < BIT; ++ i){
        if (dep[u] - dep[v] >> i & 1){
            u = top[u][i];
        }
    }
    if (u == v){
        return u;
    }
    for (int i = BIT - 1; i >= 0; -- i){
        if (top[u][i] != top[v][i]){
            u = top[u][i];
            v = top[v][i];
        }
    }
    return top[u][0];
}

int jump(int u, int len){
    for (int i = 0; i < BIT; ++ i){
        if (len >> i & 1){
            u = top[u][i];
        }
    }
    return u;
}

int main(){
    int n, k, r;
    scanf("%d%d%d", &n, &k, &r);
    for (int i = 0, u, v; i < n - 1; ++ i){
        scanf("%d%d", &u, &v);
        addedge(u, i + 1 + n);
        addedge(v, i + 1 + n);
    }
    dfs(1, 0);
    memset(dis, -1, sizeof(dis));
    n += n - 1;
    for (int i = 1; i <= n; ++ i){
        fa[i] = i;
    }
    std::queue <int> queue;
    for (int i = 0; i < r; ++ i){
        scanf("%d", &c[i]);
        dis[c[i]] = 0;
        queue.emplace(c[i]);
    }
    while (!queue.empty()){
        int u = queue.front();
        queue.pop();
        for (auto v : e[u]){
            if (dis[u] < k){
                unite(u, v);
            }
            if (dis[v] == -1){
                dis[v] = dis[u] + 1;
                queue.emplace(v);
            }
        }
    }
    int test;
    scanf("%d", &test);
    while (test --){
        int u, v;
        scanf("%d%d", &u, &v);
        int lca = getlca(u, v);
        int dis = dep[u] + dep[v] - 2 * dep[lca];
        if (dis <= 2 * k){
            puts("YES");
            continue;
        }
        if (dep[u] - dep[lca] < k){
            u = jump(v, dis - k);
            v = jump(v, k);
        }
        else if (dep[v] - dep[lca] < k){
            v = jump(u, dis - k);
            u = jump(u, k);
        }
        else{
            u = jump(u, k);
            v = jump(v, k);
        }
        puts(find(u) == find(v) ? "YES" : "NO");
    }
    return 0;
}