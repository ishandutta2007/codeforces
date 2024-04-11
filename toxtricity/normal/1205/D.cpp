#include <bits/stdc++.h>

const int N = 1010;

std::vector <int> e[N];
int sz[N], max[N];
int n;
int dp[N][N], pre[N][N];

void dfs(int u, int fa){
    sz[u] = 1;
    for (auto v : e[u]){
        if (v == fa){
            continue;
        }
        dfs(v, u);
        sz[u] += sz[v];
        max[u] = std::max(max[u], sz[v]);
    }
    max[u] = std::max(max[u], n - sz[u]);
}

int dfs1cnt = 0, dfs2cnt = 0, tot;

void dfs1(int u, int fa, int pre){
    ++ dfs1cnt;
    int value = dfs1cnt - pre;
    printf("%d %d %d\n", u, fa, value);
    for (auto v : e[u]){
        if (v == fa){
            continue;
        }
        dfs1(v, u, pre + value);
    }
}

void dfs2(int u, int fa, int pre){
    dfs2cnt += tot;
    int value = dfs2cnt - pre;
    printf("%d %d %d\n", u, fa, value);
    for (auto v : e[u]){
        if (v == fa){
            continue;
        }
        dfs2(v, u, pre + value);
    }
}

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n - 1; ++ i){
        int u, v;
        scanf("%d%d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    int cent = 0;
    for (int i = 1; i <= n; ++ i){
        if (cent == 0 || max[i] < max[cent]){
            cent = i;
        }
    }
    dfs(cent, 0);
    dp[0][0] = 1;
    for (int i = 0; i < (int) e[cent].size(); ++ i){
        memcpy(dp[i + 1], dp[i], sizeof(dp[i]));
        memset(pre[i + 1], -1, sizeof(pre[i + 1]));
        for (int j = 0; j < N - sz[e[cent][i]]; ++ j){
            if (dp[i][j] == 1){
                dp[i + 1][j + sz[e[cent][i]]] = 1;
                pre[i + 1][j + sz[e[cent][i]]] = e[cent][i];
            }
        }
    }
    int pos = -1;
    for (int i = (n - 1) / 2; i >= 0; -- i){
        if (dp[e[cent].size()][i]){
            pos = i;
            break;
        }
    }
    tot = pos + 1;
    std::vector <int> vec;
    for (int i = (int) e[cent].size(); i >= 1; -- i){
        if (pre[i][pos] == -1){
            continue;
        }
        vec.push_back(pre[i][pos]);
        pos -= sz[pre[i][pos]];
    }
    std::set <int> set;
    for (auto u : vec){
        dfs1(u, cent, 0);
        set.insert(u);
    }
    for (auto u : e[cent]){
        if (!set.count(u)){
            dfs2(u, cent, 0);
        }
    }
    return 0;
}