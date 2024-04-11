#include <bits/stdc++.h>

const int N = 500010;

int u[N], v[N], w[N];
int a[N], b[N], p[N];
std::vector <int> e[N];
int fa[N], pa[N], pa_edge[N];
int col[N];

void dfs(int uu, int ffa){
    pa[uu] = ffa;
    for (auto edge : e[uu]){
        int vv = u[edge] ^ v[edge] ^ uu;
        if (vv == ffa){
            continue;
        }
        pa_edge[vv] = edge;
        dfs(vv, uu);
    }
}

int find(int u){
    return fa[u] == u ? u : (fa[u] = find(fa[u]));
}

bool unite(int u, int v, int n){
    int oppov = v > n ? v - n : v + n;
    if (find(u) == find(oppov)){
        return false;
    }
    int oppou = u > n ? u - n : u + n;
    u = find(u), v = find(v);
    fa[u] = v;
    u = find(oppou), v = find(oppov);
    fa[u] = v;
    return true;
}

void solve(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n; ++ i){
        e[i].clear();
    }
    for (int i = 1; i <= 2 * n; ++ i){
        fa[i] = i;
    }
    for (int i = 0; i < n - 1; ++ i){
        scanf("%d%d%d", &u[i], &v[i], &w[i]);
        e[u[i]].emplace_back(i);
        e[v[i]].emplace_back(i);
    }
    for (int i = 0; i < m; ++ i){
        scanf("%d%d%d", &a[i], &b[i], &p[i]);
    }
    for (int i = 0; i < n - 1; ++ i){
        if (w[i] == -1){
            continue;
        }
        int bitcnt = __builtin_popcount(w[i]) & 1;
        if (bitcnt){
            if (!unite(u[i], v[i] + n, n)){
                puts("NO");
                return;
            }
        }
        else{
            if (!unite(u[i], v[i], n)){
                puts("NO");
                return;
            }
        }
    }
    for (int i = 0; i < m; ++ i){
        if (p[i] == 0){
            if (!unite(a[i], b[i], n)){
                puts("NO");
                return;
            }
        }
        else{
            if (!unite(a[i], b[i] + n, n)){
                puts("NO");
                return;
            }
        }
    }
    for (int i = 1; i <= n; ++ i){
        if (find(i) > n){
            col[i] = 0;
        }
        else{
            col[i] = 1;
        }
    }
    dfs(1, 0);
    for (int i = 2; i <= n; ++ i){
        int id = pa_edge[i];
        if (w[id] != -1){
            continue;
        }
        w[id] = col[i] ^ col[pa[i]];
    }
    puts("YES");
    for (int i = 0; i < n - 1; ++ i){
        printf("%d %d %d\n", u[i], v[i], w[i]);
    }
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}