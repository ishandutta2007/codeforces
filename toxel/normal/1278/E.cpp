#include <bits/stdc++.h>

const int N = 500010;

std::vector <int> e[N];
int l[N], r[N], sz[N], son[N];
int ret[2 * N];

void getsz(int u, int fa){
    sz[u] = 1;
    for (auto v : e[u]){
        if (v == fa){
            continue;
        }
        getsz(v, u);
        sz[u] += sz[v];
        if (sz[son[u]] < sz[v]){
            son[u] = v;
        }
    }
}

int dfs(int u, int fa, int offset){
    int sum = 0;
    if (son[u]){
        sum = int(e[u].size()) + int(fa == 0);
        sum += dfs(son[u], u, offset + sum);
    }
    else{
        ret[offset] = u;
        return 1;
    }
    for (auto v : e[u]){
        if (v == fa || v == son[u]){
            continue;
        }
        sum += dfs(v, u, sum + offset);
    }
    for (int i = int(e[u].size()) - 1; i >= 0; -- i){
        int v = e[u][i];
        if (v == fa || v == son[u]){
            continue;
        }
        ret[offset ++] = v;
    }
    ret[offset ++] = son[u];
    ret[offset ++] = u;
    return sum;
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0, u, v; i < n - 1; ++ i){
        scanf("%d%d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    getsz(1, 0);
    dfs(1, 0, 1);
    ret[0] = 1;
    for (int i = 0; i < 2 * n; ++ i){
        if (!l[ret[i]]){
            l[ret[i]] = i + 1;
        }
        else{
            r[ret[i]] = i + 1;
        }
    }
    for (int i = 1; i <= n; ++ i){
        printf("%d %d\n", l[i], r[i]);
    }
    return 0;
}