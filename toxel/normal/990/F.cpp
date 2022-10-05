#include<bits/stdc++.h>

const int N = 200010;
typedef std::pair <int, int> pii;

pii p[N];
std::vector <pii> e[N];
int s[N];
int fa[N];
int ans[N];

int find(int u){
    return fa[u] == u ? u : (fa[u] = find(fa[u]));
}

void dfs(int u, int fa, int id, bool rev){
    int sum = 0;
    for (auto v : e[u]){
        if (v.first == fa) continue;
        dfs(v.first, u, v.second, p[v.second].first != u);
        sum += p[v.second].first == u ? ans[v.second] : -ans[v.second];
    }
    if (id != -1){
        ans[id] = sum + s[u];
        if (rev){
            ans[id] = -ans[id];
        }
    }
}

bool unite(int u, int v){
    u = find(u), v = find(v);
    if (u == v) return false;
    fa[u] = v;
    return true;
}

int main(){
    int n;
    scanf("%d", &n);
    int sum = 0;
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &s[i]);
        sum += s[i];
    }
    if (sum){
        puts("Impossible");
        return 0;
    }
    for (int i = 1; i <= n; ++ i){
        fa[i] = i;
    }
    int m;
    scanf("%d", &m);
    for (int i = 0, u, v; i < m; ++ i){
        scanf("%d%d", &u, &v);
        p[i] = {u, v};
        if (unite(u, v)){
            e[u].push_back({v, i});
            e[v].push_back({u, i});
        }
    }
    dfs(1, 0, -1, false);
    puts("Possible");
    for (int i = 0; i < m; ++ i){
        printf("%d\n", ans[i]);
    }
    return 0;
}