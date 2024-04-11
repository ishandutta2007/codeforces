#include <bits/stdc++.h>

const int N = 300010;
const int M = 20000010;
const int BIT = 20;
const int MAX = 1 << BIT;
using ll = unsigned long long;

ll value[M];
int ch[M][2];
int rt[N];
int sz = 0;
int a[N];
ll w[N];
std::vector <int> e[N];
int top[N][BIT], dep[N];

int newnode(){
    return ++ sz;
}

void copy(int &u, int v){
    u = newnode();
    memcpy(ch[u], ch[v], sizeof(ch[0]));
    value[u] = value[v];
}

void insert(int u, int sit, ll val){
    for (int i = BIT - 1; i >= 0; -- i){
        value[u] ^= val;
        int pos = sit >> i & 1;
        copy(ch[u][pos], ch[u][pos]);
        u = ch[u][pos];
    }
    value[u] ^= val;
}

int getlca(int u, int v){
    if (dep[u] < dep[v]){
        std::swap(u, v);
    }
    for (int i = 0; i < BIT; ++ i){
        if (dep[u] - dep[v] >> i & 1){
            u = top[u][i];
        }
    }
    if (u == v){
        return u;
    }
    for (int i = BIT - 1; i >= 0; -- i){
        if (top[u][i] != top[v][i]){
            u = top[u][i];
            v = top[v][i];
        }
    }
    return top[u][0];
}

void dfs(int u, int fa){
    copy(rt[u], rt[fa]);
    insert(rt[u], a[u], w[a[u]]);
    top[u][0] = fa;
    for (int i = 1; i < BIT; ++ i){
        top[u][i] = top[top[u][i - 1]][i - 1];
    }
    for (auto v : e[u]){
        if (v == fa){
            continue;
        }
        dep[v] = dep[u] + 1;
        dfs(v, u);
    }
}

ll query(int sit, int l, int r, int ql, int qr){
    if (!sit){
        return 0;
    }
    if (ql > r || qr < l){
        return 0;
    }
    if (ql <= l && r <= qr){
        return value[sit];
    }
    int mid = (l + r) / 2;
    return query(ch[sit][0], l, mid, ql, qr) ^
           query(ch[sit][1], mid + 1, r, ql, qr);
}

int query(int sit1, int sit2, int l, int r, int ql, int qr){
    if ((value[sit1] ^ value[sit2]) == 0){
        return -1;
    }
    if (ql > r || qr < l){
        return -1;
    }
    if (l == r){
        return l;
    }
    int mid = (l + r) / 2;
    int ret = query(ch[sit1][0], ch[sit2][0], l, mid, ql, qr);
    if (ret != -1){
        return ret;
    }
    return query(ch[sit1][1], ch[sit2][1], mid + 1, r, ql, qr);
}

int main(){
    int n, test;
    scanf("%d%d", &n, &test);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    std::mt19937_64 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
    for (int i = 1; i <= n; ++ i){
        w[i] = rnd();
    }
    for (int i = 0, u, v; i < n - 1; ++ i){
        scanf("%d%d", &u, &v);
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    dfs(1, 0);
    while (test --){
        int u, v, l, r;
        scanf("%d%d%d%d", &u, &v, &l, &r);
        int lca = getlca(u, v);
        auto check = [&](int l, int r){
            if (l > r){
                return -1;
            }
            return query(rt[u], rt[v], 0, MAX - 1, l, r);
        };
        if (a[lca] < l || a[lca] > r){
            printf("%d\n", check(l, r));
            continue;
        }
        int col = a[lca];
        ll val = query(rt[u], 0, MAX - 1, col, col) ^ query(rt[v], 0, MAX - 1, col, col) ^
                 query(rt[lca], 0, MAX - 1, col, col) ^ query(rt[top[lca][0]], 0, MAX - 1, col, col);
        if (val){
            printf("%d\n", col);
            continue;
        }
        int ret = check(l, col - 1);
        if (ret != -1){
            printf("%d\n", ret);
            continue;
        }
        printf("%d\n", check(col + 1, r));
    }
}

/*
6 1
3 2 1 3 1 3
1 2
1 3
2 4
2 5
4 6
1 4 1 5
 */