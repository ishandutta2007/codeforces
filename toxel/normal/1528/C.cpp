#include <bits/stdc++.h>

const int N = 300100;
using ll = long long;

std::vector <int> e1[N], e2[N];
int dfn[N], right[N], dfncnt;
int c[N];
int n, ans;

void add(int sit, int x){
    for ( ; sit < n + 5; sit += sit & -sit){
        c[sit] += x;
    }
}

void add(int l, int r, int x){
    add(l, x);
    add(r + 1, -x);
}

ll query(int sit){
    ll ret = 0;
    for ( ; sit; sit -= sit & -sit){
        ret += c[sit];
    }
    return ret;
}

void getdfn(int u, int fa){
    dfn[u] = ++ dfncnt;
    for (auto v : e2[u]){
        if (v == fa){
            continue;
        }
        getdfn(v, u);
    }
    right[u] = dfncnt;
}

void dfs(int u, int fa, int cur){
    int pos = query(dfn[u]);
    if (pos == 0){
        ++ cur;
        add(dfn[u], right[u], u);
    }
    else{
        add(dfn[pos], right[pos], -pos);
        add(dfn[u], right[u], u);
    }
    ans = std::max(ans, cur);
    for (auto v : e1[u]){
        if (v == fa){
            continue;
        }
        dfs(v, u, cur);
    }
    if (pos == 0){
        add(dfn[u], right[u], -u);
    }
    else{
        add(dfn[pos], right[pos], pos);
        add(dfn[u], right[u], -u);
    }
}

void solve(){
    scanf("%d", &n);

    dfncnt = ans = 0;
    for (int i = 0; i <= n + 10; ++ i){
        e1[i].clear();
        e2[i].clear();
        c[i] = 0;
    }

    for (int i = 2, fa; i <= n; ++ i){
        scanf("%d", &fa);
        e1[i].emplace_back(fa);
        e1[fa].emplace_back(i);
    }
    for (int i = 2, fa; i <= n; ++ i){
        scanf("%d", &fa);
        e2[i].emplace_back(fa);
        e2[fa].emplace_back(i);
    }
    getdfn(1, 0);
    dfs(1, 0, 0);
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