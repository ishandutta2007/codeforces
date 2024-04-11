#include <bits/stdc++.h>

const int N = 1000010;

int col[N], c[N], rt[N];
std::vector<int> e[N];
bool flag[N];

void dfs(int u, int root){
    rt[u] = root;
    for (auto v : e[u]){
        if (c[v] != c[u]){
            continue;
        }
        if (col[v] != -1){
            if (col[u] == col[v]){
                flag[c[u]] = false;
            }
        }
        else{
            col[v] = col[u] ^ 1;
            dfs(v, root);
        }
    }
}

using ppii = std::pair <int *, int>;

int fa[N];
std::vector <ppii> rollback;

void set(int *p, int value){
    rollback.emplace_back(p, *p);
    *p = value;
}

void do_rollback(){
    while (!rollback.empty()){
        ppii p = rollback.back();
        *(p.first) = p.second;
        rollback.pop_back();
    }
}

int find(int u){
    if (fa[u] == u){
        return u;
    }
    set(fa + u, find(fa[u]));
    return fa[u];
}

void unite(int u, int v){
    u = find(u), v = find(v);
    if (u == v){
        return;
    }
    set(fa + u, v);
}

int main(){
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= k; ++ i){
        flag[i] = true;
    }
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &c[i]);
    }
    using pii = std::pair <int, int>;
    std::map <pii, std::vector<pii>> map;
    for (int i = 0; i < m; ++ i){
        int u, v;
        scanf("%d%d", &u, &v);
        e[u].emplace_back(v);
        e[v].emplace_back(u);
        pii type = {c[u], c[v]};
        if (type.first > type.second){
            std::swap(type.first, type.second);
            std::swap(u, v);
        }
        map[type].emplace_back(u, v);
    }
    memset(col, -1, sizeof(col));
    for (int i = 1; i <= n; ++ i){
        if (col[i] == -1){
            col[i] = 0;
            dfs(i, i);
        }
    }
    using ll = long long;
    ll ans = 0;
    for (int i = 1; i <= k; ++ i){
        ans += flag[i];
    }
    for (int i = 0; i < N; ++ i){
        fa[i] = i;
    }
    ans = 1ll * ans * (ans - 1) / 2;
    for (const auto &pair : map){
        pii p = pair.first;
        if (p.first == p.second){
            continue;
        }
        if (!flag[p.first] || !flag[p.second]){
            continue;
        }
        for (const auto &p1 : pair.second){
            int u1 = rt[p1.first] + n * (col[p1.first]);
            int v1 = rt[p1.second] + n * (col[p1.second]);
            int u2 = rt[p1.first] + n * (col[p1.first] ^ 1);
            int v2 = rt[p1.second] + n * (col[p1.second] ^ 1);
            if (find(u1) == find(v2)){
                -- ans;
                break;
            }
            unite(u1, v1);
            unite(u2, v2);
        }
        do_rollback();
    }
    printf("%lld\n", ans);
    return 0;
}