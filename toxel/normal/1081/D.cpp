#include<bits/stdc++.h>

const int N = 100010;
typedef std::pair <int, int> pii;
typedef std::pair <int, pii> piii;

int fa[N], sz[N];
piii p[N];
int x[N];
int k;

int find(int u){
    return u == fa[u] ? u : (fa[u] = find(fa[u]));
}

bool unite(int u, int v){
    u = find(u), v = find(v);
    if (u == v){
        return false;
    }
    if (sz[v] + sz[u] == k){
        return true;
    }
    sz[v] += sz[u];
    fa[u] = v;
    return false;
}

int main(){
    int n, m;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < k; ++ i){
        scanf("%d", &x[i]);
        sz[x[i]] = 1;
    }
    for (int i = 0, u, v, w; i < m; ++ i){
        scanf("%d%d%d", &u, &v, &w);
        p[i] = {w, {u, v}};
    }
    for (int i = 1; i <= n; ++ i){
        fa[i] = i;
    }
    std::sort(p, p + m);
    for (int i = 0; i < m; ++ i){
        int u = p[i].second.first, v = p[i].second.second;
        if (unite(u, v)){
            for (int j = 0; j < k; ++ j){
                printf("%d%c", p[i].first, " \n"[j == k - 1]);
            }
            return 0;
        }
    }
    return 0;
}