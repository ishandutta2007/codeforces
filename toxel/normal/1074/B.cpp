#include<bits/stdc++.h>

const int N = 1010;

std::vector <int> e[N];
bool vis1[N], vis2[N];

int dfs(int u, int fa){
    if (vis1[u]) return u;
    for (auto v : e[u]){
        if (v == fa) continue;
        int x = dfs(v, u);
        if (x != -1){
            return x;
        }
    }
    return -1;
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        int n;
        scanf("%d", &n);
        for (int i = 0; i <= n; ++ i){
            e[i].clear();
            vis1[i] = vis2[i] = 0;
        }
        for (int i = 0, u, v; i < n - 1; ++ i){
            scanf("%d%d", &u, &v);
            e[u].push_back(v);
            e[v].push_back(u);
        }
        int k1;
        scanf("%d", &k1);
        for (int i = 0, x; i < k1; ++ i){
            scanf("%d", &x);
            vis1[x] = true;
        }
        int k2;
        scanf("%d", &k2);
        int y;
        for (int i = 0, x; i < k2; ++ i){
            scanf("%d", &x);
            vis2[x] = true;
            y = x;
        }
        printf("B %d\n", y);
        fflush(stdout);
        int id;
        scanf("%d", &id);
        if (vis1[id]){
            printf("C %d\n", id);
            fflush(stdout);
            continue;
        }
        int x = dfs(id, 0);
        printf("A %d\n", x);
        fflush(stdout);
        scanf("%d", &id);
        printf("C %d\n", vis2[id] ? x : -1);
        fflush(stdout);
    }
}