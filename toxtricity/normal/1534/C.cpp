#include <bits/stdc++.h>

const int N = 500010;
const int moder = 1'000'000'007;

int fa[N];

int find(int u){
    return fa[u] == u ? u : (fa[u] = find(fa[u]));
}

void unite(int u, int v){
    u = find(u), v = find(v);
    if (u == v) return;
    fa[u] = v;
}

int p[N], q[N];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &p[i]);
    }
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &q[i]);
    }
    for (int i = 1; i <= n; ++ i){
        fa[i] = i;
    }
    for (int i = 1; i <= n; ++ i){
        unite(p[i], q[i]);
    }
    int ans = 1;
    for (int i = 1; i <= n; ++ i){
        if (find(i) == i){
            ans = 2ll * ans % moder;
        }
    }
    printf("%d\n", ans);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}