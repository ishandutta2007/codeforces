#include<bits/stdc++.h>

const int N = 300010;
const int MAX = 1 << 19;
typedef std::pair <int, int> pii;

std::vector <int> e[N];
int sz[N], dfn[N], dfnend[N];
pii seg[MAX << 1];
int dfncnt = 0;
std::vector <int> vec[N];
int ans[N];

void dfs(int u, int fa){
    sz[u] = 1;
    dfn[u] = ++ dfncnt;
    for (auto v : e[u]){
        if (v == fa) continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
    dfnend[u] = dfncnt;
}

void add(int sit, pii value){
    seg[sit + MAX] = value;
    for (sit += MAX, sit >>= 1; sit; sit >>= 1){
        seg[sit] = std::min(seg[sit << 1], seg[sit << 1 | 1]);
    }
}

pii query(int l, int r){
    pii ret = {INT_MAX, 0};
    for (l += MAX, r += MAX + 1; l < r; l >>= 1, r >>= 1){
        if (l & 1) ret = std::min(ret, seg[l ++]);
        if (r & 1) ret = std::min(ret, seg[-- r]);
    }
    return ret;
}

int main(){
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 2, x; i <= n; ++ i){
        scanf("%d", &x);
        e[i].push_back(x);
        e[x].push_back(i);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; ++ i){
        add(i, {INT_MAX, 0});
        vec[sz[i]].push_back(i);
    }
    for (int i = 1; i <= n; ++ i){
        for (auto u : vec[i - 1 >> 1]){
            add(dfn[u], {INT_MAX, 0});
        }
        for (auto u : vec[i]){
            add(dfn[u], {sz[u], u});
            ans[u] = query(dfn[u], dfnend[u]).second;
        }
    }
    while (q --){
        int x;
        scanf("%d", &x);
        printf("%d\n", ans[x]);
    }
    return 0;
}