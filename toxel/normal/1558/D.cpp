#include <bits/stdc++.h>

const int N = 1000010;
const int moder = 998244353;

int fac[N], inv[N], invf[N];

int comb(int n, int m){
    if (n < m || m < 0) return 0;
    return 1ll * fac[n] * invf[m] % moder * invf[n - m] % moder;
}

using pii = std::pair <int, int>;
std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());

struct Treap{
#define ls(u) (ch[(u)][0])
#define rs(u) (ch[(u)][1])

    int root, node_sz;
    int ch[N][2];
    int key[N], sz[N], cnt[N];
    int lazy[N];
    unsigned prior[N];

    void clear(int x){
        ls(x) = rs(x) = 0;
        key[x] = sz[x] = cnt[x] = lazy[x] = prior[x] = 0;
    }

    void init(){
        node_sz = root = 0;
    }

    int newnode(int x){
        clear(++ node_sz);
        key[node_sz] = x;
        prior[node_sz] = rnd();
        return node_sz;
    }

    void pull(int u){
        sz[u] = sz[ls(u)] + sz[rs(u)] + cnt[u];
    }

    void push(int u){
        if (!lazy[u]){
            return;
        }
        for (int i = 0; i < 2; ++ i){
            if (ch[u][i]){
                key[ch[u][i]] += lazy[u];
                lazy[ch[u][i]] += lazy[u];
            }
        }
        lazy[u] = 0;
    }

    pii split(int p, int u){
        if (!p) return {0, 0};
        push(p);
        if (key[p] <= u){
            pii ret = split(rs(p), u);
            rs(p) = ret.first;
            pull(p);
            return {p, ret.second};
        }
        pii ret = split(ls(p), u);
        ls(p) = ret.second;
        pull(p);
        return {ret.first, p};
    }

    int merge(int u, int v){
        if (!u || !v) return u ^ v;
        push(u);
        push(v);
        if (prior[u] > prior[v]){
            rs(u) = merge(rs(u), v);
            pull(u);
            return u;
        }
        ls(v) = merge(u, ls(v));
        pull(v);
        return v;
    }

    int right(int p){
        while (rs(p)){
            push(p);
            p = rs(p);
        }
        return p;
    }

    bool insert(int x){
        pii pair = split(root, x - 1);
        int p = right(pair.first);
        pii pair1;
        bool result = false;
        if (p && key[p] == x - 1){
            result = true;
            ++ lazy[pair.second];
            ++ key[pair.second];
            pair1 = split(pair.first, x - 2);
            ++ key[pair1.second];
            pair1.second = merge(pair1.second, pair.second);
            pair = pair1;
        }
        else{
            int nd = newnode(x);
            ++ cnt[nd], ++ sz[nd];
            ++ lazy[pair.second];
            ++ key[pair.second];
            pair.second = merge(nd, pair.second);
        }
        root = merge(pair.first, pair.second);
        return result;
    }

    void dfs(int u){
        if (!u){
            return;
        }
        push(u);
        dfs(ls(u));
        dfs(rs(u));
    }
};

Treap treap;
int xx[N];

void solve(){
    treap.init();
    int n, m;
    scanf("%d%d", &n, &m);
    int big = 0;
    for (int i = 0; i < m; ++ i){
        int x, y;
        scanf("%d%d", &x, &y);
        if (!treap.insert(y)){
            ++ big;
        }
    }
    big = n - big - 1;
    printf("%d\n", comb(n + big, n));
}

int main(){
    fac[0] = invf[0] = 1;
    for (int i = 1; i < N; ++ i){
        fac[i] = 1ll * fac[i - 1] * i % moder;
        inv[i] = i == 1 ? 1 : moder - 1ll * (moder / i) * inv[moder % i] % moder;
        invf[i] = 1ll * invf[i - 1] * inv[i] % moder;
    }
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}