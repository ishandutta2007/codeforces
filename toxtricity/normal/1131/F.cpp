#include<bits/stdc++.h>

const int N = 1000010;

std::vector <int> e[N];
int fa[N], ans[N], dfn;
int n;

int find(int u){
    return fa[u] == u ? u : (fa[u] = find(fa[u]));
}

void unite(int u, int v){
    u = find(u), v = find(v);
    fa[u] = v;
}

void dfs(int u){
    for (auto v : e[u]){
        dfs(v);
    }
    if (u <= n) {
        ans[++ dfn] = u;
    }
}

int main(){
    for (int i = 0; i < N; ++ i){
        fa[i] = i;
    }
    scanf("%d", &n);
    int cnt = n;
    for (int i = 0, x, y; i < n - 1; ++ i){
        scanf("%d%d", &x, &y);
        ++ cnt;
        e[cnt].push_back(find(x));
        e[cnt].push_back(find(y));
        unite(x, cnt);
        unite(y, cnt);
    }
    dfs(cnt);
    for (int i = 1; i <= n; ++ i){
        printf("%d%c", ans[i], " \n"[i == n]);
    }
    return 0;
}