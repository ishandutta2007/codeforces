#include<bits/stdc++.h>

const int N = 1 << 22;

bool vis[N][2], vis2[N];
int a[N];
int n, m;

void dfs(int u1, int u2){
    if (vis[u1][u2] || !u2 && !vis2[u1]){
        return;
    }
    vis[u1][u2] = true;
    if (u2){
        dfs(~u1 & ((1 << n) - 1), 0);
        for (int i = 0; i < n; ++ i){
            if (!(u1 >> i & 1)){
                dfs(u1 ^ 1 << i, 1);
            }
        }
        return;
    }
    dfs(u1, 1);
}

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++ i){
        scanf("%d", &a[i]);
        vis2[a[i]] = true;
    }
    int cnt = 0;
    for (int i = 0; i < m; ++ i){
        if (!vis[a[i]][0]){
            ++ cnt;
            dfs(a[i], 0);
        }
    }
    printf("%d\n", cnt);
    return 0;
}