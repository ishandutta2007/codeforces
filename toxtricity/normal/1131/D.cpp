#include <bits/stdc++.h>

const int N = 2010;

char s[N][N];
int fa[N];
std::vector <int> e[N];
bool vis[N], instack[N];
int deg[N], dfn[N], dfncnt;
int ans[N];

int find(int u){
    return fa[u] == u ? u : (fa[u] = find(fa[u]));
}

void unite(int u, int v){
    u = find(u), v = find(v);
    if (u == v) return;
    fa[u] = v;
}

void dfs(int u){
    dfn[u] = dfncnt ++;
    if (vis[u]) return;
    vis[u] = instack[u] = true;
    for (auto v : e[u]){
        if (instack[v] && dfn[u] >= dfn[v]) {
            puts("No");
            exit(0);
        }
        dfs(v);
    }
    instack[u] = false;
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++ i){
        scanf("%s", s[i]);
    }
    for (int i = 0; i < N; ++ i){
        fa[i] = i;
    }
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            if (s[i][j] == '='){
                unite(i + m + 1, j + 1);
            }
        }
    }
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            int x = find(i + m + 1), y = find(j + 1);
            if (s[i][j] == '>'){
                e[x].push_back(y);
                ++ deg[y];
            }
            else if (s[i][j] == '<'){
                e[y].push_back(x);
                ++ deg[x];
            }
        }
    }
    for (int i = 1; i <= n + m; ++ i){
        if (!vis[i]){
            dfs(i);
        }
    }
    puts("Yes");
    int left = n + m;
    int cnt = 0;
    memset(vis, 0, sizeof(vis));
    while (left){
        std::vector <int> vec;
        for (int i = 1; i <= n + m; ++ i){
            if (!vis[i] && !deg[i]){
                -- left;
                vec.push_back(i);
                vis[i] = true;
            }
        }
        for (auto u : vec){
            ans[u] = cnt;
            for (auto v : e[u]){
                -- deg[v];
            }
        }
        ++ cnt;
    }
    for (int i = m + 1; i <= m + n; ++ i){
        printf("%d%c", cnt - ans[find(i)], " \n"[i == m + n]);
    }
    for (int i = 1; i <= m; ++ i){
        printf("%d%c", cnt - ans[find(i)], " \n"[i == m]);
    }
    return 0;
}