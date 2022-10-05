#include<bits/stdc++.h>

const int N = 100010;
const int MAX = 1 << 17;
const int M = 1024;

std::bitset <M> seg[MAX << 1];
int lazy[MAX << 1];
int dfn[N], end[N], dfncnt;
std::vector <int> e[N];
int n, m;

void dfs(int u, int fa){
    dfn[u] = dfncnt ++;
    for (auto v : e[u]){
        if (v == fa) continue;
        dfs(v, u);
    }
    end[u] = dfncnt - 1;
}

int min[N], a[N];
std::vector <int> prime;
std::bitset <M> allone;

void move(std::bitset <M> &set, int offset){
    set = ((set << offset) & allone) | (set >> (m - offset));
}

void push(int sit){
    if (!lazy[sit]) return;
    move(seg[sit << 1], lazy[sit]);
    move(seg[sit << 1 | 1], lazy[sit]);
    lazy[sit << 1] = (lazy[sit << 1] + lazy[sit]) % m;
    lazy[sit << 1 | 1] = (lazy[sit << 1 | 1] + lazy[sit]) % m;
    lazy[sit] = 0;
}

void pull(int sit){
    seg[sit] = seg[sit << 1] | seg[sit << 1 | 1];
}

void add(int sit, int l, int r, int ql, int qr, int value){
    if (ql <= l && qr >= r){
        move(seg[sit], value);
        lazy[sit] = (lazy[sit] + value) % m;
        return;
    }
    push(sit);
    int mid = (l + r) >> 1;
    if (mid >= ql){
        add(sit << 1, l, mid, ql, qr, value);
    }
    if (mid < qr){
        add(sit << 1 | 1, mid + 1, r, ql, qr, value);
    }
    pull(sit);
}

void add(int l, int r, int value){
    add(1, 0, MAX - 1, l, r, value);
}

std::bitset <M> query(int sit, int l, int r, int ql, int qr){
    if (ql <= l && qr >= r){
        return seg[sit];
    }
    push(sit);
    int mid = (l + r) >> 1;
    std::bitset <M> set;
    if (mid >= ql){
        set |= query(sit << 1, l, mid, ql, qr);
    }
    if (mid < qr){
        set |= query(sit << 1 | 1, mid + 1, r, ql, qr);
    }
    return set;
}

std::bitset <M> query(int ql, int qr){
    return query(1, 0, MAX - 1, ql, qr);
}

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++ i){
        allone[i] = 1;
    }
    for (int i = 2; i < m; ++ i){
        if (!min[i]){
            min[i] = i;
            prime.push_back(i);
        }
        for (auto u : prime){
            if (u * i >= m) break;
            min[u * i] = u;
            if (i % u == 0) break;
        }
    }
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
        a[i] %= m;
    }
    for (int i = 0; i < n - 1; ++ i){
        int u, v;
        scanf("%d%d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; ++ i){
        seg[dfn[i] + MAX][a[i]] = 1;
    }
    for (int i = MAX - 1; i; -- i){
        pull(i);
    }
    int q;
    scanf("%d", &q);
    while (q --){
        int type;
        scanf("%d", &type);
        if (type == 1){
            int v, x;
            scanf("%d%d", &v, &x);
            x %= m;
            add(dfn[v], end[v], x);
        }
        else{
            int v;
            scanf("%d", &v);
            std::bitset <M> set = query(dfn[v], end[v]);
            int ans = 0;
            for (auto u : prime){
                ans += set[u];
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}