#include<bits/stdc++.h>

const int N = 400010;

int fa[N];

int find(int u){
    return fa[u] == u ? u : (fa[u] = find(fa[u]));
}

void unite(int u, int v){
    u = find(u), v = find(v);
    if (u == v) return;
    fa[u] = v;
}

int main(){
    for (int i = 1; i < N; ++ i){
        fa[i] = i;
    }
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    while (q --){
        int u, v;
        scanf("%d%d", &u, &v);
        unite(u, v + n);
    }
    int ans = 0;
    for (int i = 1; i <= n + m; ++ i){
        if (find(i) == i){
            ++ ans;
        }
    }
    printf("%d\n", ans - 1);
    return 0;
}