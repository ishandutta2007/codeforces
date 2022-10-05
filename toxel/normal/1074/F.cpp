#include<bits/stdc++.h>

const int N = 200010;
const int MAX = 1 << 18;
const int BIT = 18;
typedef std::pair <int, int> pii;

pii seg[MAX << 1];
int lazy[MAX << 1];
int dfn[N], end[N], dfncnt;
int dep[N], fa[N][BIT];
std::vector <int> e[N];

void dfs(int u, int fa){
    ::fa[u][0] = fa;
    for (int i = 1; i < BIT; ++ i){
        ::fa[u][i] = ::fa[::fa[u][i - 1]][i - 1];
    }
    dfn[u] = dfncnt ++;
    for (auto v : e[u]){
        if (v == fa) continue;
        dep[v] = dep[u] + 1;
        dfs(v, u);
    }
    end[u] = dfncnt - 1;
}

void push(int sit){
    if (!lazy[sit]) return;
    int ls = sit << 1, rs = sit << 1 | 1;
    seg[ls].first += lazy[sit];
    seg[rs].first += lazy[sit];
    lazy[ls] += lazy[sit];
    lazy[rs] += lazy[sit];
    lazy[sit] = 0;
}

pii merge(pii p1, pii p2){
    if (p1.first != p2.first){
        return std::max(p1, p2);
    }
    return {p1.first, p1.second + p2.second};
}

void pull(int sit){
    int ls = sit << 1, rs = sit << 1 | 1;
    seg[sit] = merge(seg[ls], seg[rs]);
}

void add(int sit, int l, int r, int ql, int qr, int value){
    if (ql <= l && qr >= r){
        seg[sit].first += value;
        lazy[sit] += value;
        return;
    }
    push(sit);
    int mid = (l + r) >> 1;
    if (ql <= mid){
        add(sit << 1, l, mid, ql, qr, value);
    }
    if (qr > mid){
        add(sit << 1 | 1, mid + 1, r, ql, qr, value);
    }
    pull(sit);
}

void add(int ql, int qr, int value){
    if (ql > qr) return;
    add(1, 0, MAX - 1, ql, qr, value);
}

pii query(int sit, int l, int r, int ql, int qr){
    if (ql <= l && qr >= r){
        return seg[sit];
    }
    push(sit);
    int mid = (l + r) >> 1;
    pii ret = {-1, 0};
    if (ql <= mid){
        ret = merge(ret, query(sit << 1, l, mid, ql, qr));
    }
    if (qr > mid){
        ret = merge(ret, query(sit << 1 | 1, mid + 1, r, ql, qr));
    }
    return ret;
}

pii query(int ql, int qr){
    return query(1, 0, MAX - 1, ql, qr);
}

int main(){
    std::set <pii> set;
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 0, u, v; i < n - 1; ++ i){
        scanf("%d%d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; ++ i){
        seg[MAX + i] = {0, 1};
    }
    for (int i = MAX - 1; i; -- i){
        pull(i);
    }
    while (q --){
        int u, v;
        scanf("%d%d", &u, &v);
        if (u > v){
            std::swap(u, v);
        }
        int value;
        if (set.count({u, v})){
            set.erase({u, v});
            value = -1;
        }
        else{
            set.insert({u, v});
            value = 1;
        }
        if (dfn[u] <= dfn[v] && dfn[v] <= end[u]){
            std::swap(u, v);
        }
        if (dfn[v] <= dfn[u] && dfn[u] <= end[v]){
            int x = dep[u] - dep[v] - 1;
            int w = u;
            for (int i = 0; i < BIT; ++ i){
                if (x >> i & 1){
                    w = fa[w][i];
                }
            }
            add(1, n, value);
            add(dfn[w], end[w], -value);
            add(dfn[u], end[u], value);
        }
        else{
            add(dfn[u], end[u], value);
            add(dfn[v], end[v], value);
        }
        pii p = query(1, n);
        printf("%d\n", p.first == (int) set.size() ? p.second : 0);
    }
    return 0;
}