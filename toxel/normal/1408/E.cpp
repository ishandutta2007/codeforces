#include <bits/stdc++.h>

using ll = long long;
const int N = 500010;

struct Edge{
    int u, v, w;

    bool operator <(const Edge &e)const{
        return w > e.w;
    }
};

int a[N], b[N];
Edge e[N];
int fa[N];

int find(int u){
    return fa[u] == u ? u : (fa[u] = find(fa[u]));
}

void unite(int u, int v){
    u = find(u), v = find(v);
    fa[u] = v;
}

int main(){
    int m, n;
    scanf("%d%d", &m, &n);
    for (int i = 0; i < m; ++ i){
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; ++ i){
        scanf("%d", &b[i]);
    }
    ll tot = 0;
    int ecnt = 0;
    for (int i = 0; i < m; ++ i){
        int num;
        scanf("%d", &num);
        for (int j = 0; j < num; ++ j){
            int x;
            scanf("%d", &x);
            tot += a[i] + b[x - 1];
            e[ecnt].u = i;
            e[ecnt].v = x - 1 + m;
            e[ecnt].w = a[i] + b[x - 1];
            ++ ecnt;
        }
    }
    std::sort(e, e + ecnt);
    for (int i = 0; i < N; ++ i){
        fa[i] = i;
    }
    for (int i = 0; i < ecnt; ++ i){
        if (find(e[i].u) == find(e[i].v)){
            continue;
        }
        tot -= e[i].w;
        unite(e[i].u, e[i].v);
    }
    printf("%lld\n", tot);
}