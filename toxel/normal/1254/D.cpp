#include <bits/stdc++.h>

const int N = 150010;
const int moder = 998244353;

std::vector <int> e[N];
int c[N], offset[N];

int powermod(int a, int exp){
    int ret = 1;
    for ( ; exp > 0; exp >>= 1){
        if (exp & 1){
            ret = 1ll * a * ret % moder;
        }
        a = 1ll * a * a % moder;
    }
    return ret;
}

void add(int sit, int value){
    for ( ; sit < N; sit += sit & -sit){
        c[sit] += value;
        c[sit] -= c[sit] >= moder ? moder : 0;
    }
}

void add(int l, int r, int value){
    add(l, value);
    add(r + 1, value ? moder - value : 0);
}

int query(int sit){
    int ret = 0;
    for ( ; sit; sit -= sit & -sit){
        ret += c[sit];
        ret -= ret >= moder ? moder : 0;
    }
    return ret;
}

int dfn[N], right[N], dfncnt;
int top[N], fa[N], sz[N], son[N];

void dfs(int u, int fa){
    ::fa[u] = fa;
    sz[u] = 1;
    dfn[u] = ++ dfncnt;
    for (auto v : e[u]){
        if (v == fa){
            continue;
        }
        dfs(v, u);
        sz[u] += sz[v];
        if (sz[v] > sz[son[u]]){
            son[u] = v;
        }
    }
    right[u] = dfncnt;
}

void build(int u){
    for (auto v : e[u]){
        if (v == fa[u]){
            continue;
        }
        if (v == son[u]){
            top[v] = top[u];
        }
        else{
            top[v] = v;
        }
        build(v);
    }
}

int main(){
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n - 1; ++ i){
        int u, v;
        scanf("%d%d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    top[1] = 1;
    build(1);
    while (q --){
        int type;
        scanf("%d", &type);
        if (type == 1){
            int v, d;
            scanf("%d%d", &v, &d);
            offset[v] += d;
            offset[v] -= offset[v] >= moder ? moder : 0;
            if (v != 1){
                int value = 1ll * d * sz[v] % moder;
                add(1, n, value);
                add(dfn[v], right[v], value ? moder - value : 0);
            }
            if (son[v]){
                int value = 1ll * d * (n - sz[son[v]]) % moder;
                add(dfn[son[v]], right[son[v]], value);
            }
            int value = 1ll * n * d % moder;
            add(dfn[v], dfn[v], value);
        }
        else{
            int v;
            scanf("%d", &v);
            int ans = query(dfn[v]);
            while (true){
                v = top[v];
                if (v == 1){
                    break;
                }
                ans = (ans + 1ll * offset[fa[v]] * (n - sz[v])) % moder;
                v = fa[v];
            }
            ans = 1ll * ans * powermod(n, moder - 2) % moder;
            printf("%d\n", ans);
        }
    }
    return 0;
}