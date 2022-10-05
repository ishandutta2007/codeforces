#include <bits/stdc++.h>

const int N = 100010;
const int M = 30;

bool vis[M][M];
char a[N], b[N];
int fa[M];

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

void solve(){
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < M; ++ i){
        fa[i] = i;
    }
    int n;
    scanf("%d%s%s", &n, a, b);
    for (int i = 0; i < n; ++ i){
        if (a[i] > b[i]){
            puts("-1");
            return;
        }
        vis[a[i] - 'a'][b[i] - 'a'] = true;
    }
    for (int i = 0; i < M; ++ i){
        for (int j = i + 1; j < M; ++ j){
            if (vis[i][j]){
                unite(i, j);
            }
        }
    }
    for (int i = 0; i < M; ++ i){
        find(i);
    }
    int ans = 0;
    for (int i = 0; i < M; ++ i){
        int cnt = 0;
        for (int j = 0; j < M; ++ j){
            if (find(j) == i){
                ++ cnt;
            }
        }
        if (cnt >= 1){
            ans += cnt - 1;
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