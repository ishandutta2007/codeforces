#include <bits/stdc++.h>

const int N = 1000010;
using ll = long long;
using pii = std::pair <ll, ll>;

template <typename T>
void read(T &n){
    char ch;
    while (!isdigit(ch = getchar()))
        ;
    n = ch - '0';
    while (isdigit(ch = getchar())){
        n = n * 10 + ch - '0';
    }
}

struct Treap{
#define ls(u) (ch[(u)][0])
#define rs(u) (ch[(u)][1])

    int root;
    ll val[N], key[N], sum[N], sum1[N], key1[N];
    int sz[N], lazy[N], cnt[N];
    int ch[N][2];

    void pull(int u){
        sz[u] = sz[ls(u)] + sz[rs(u)] + cnt[u];
        sum[u] = sum[ls(u)] + sum[rs(u)] + key[u];
        sum1[u] = sum1[ls(u)] + sum1[rs(u)] + key1[u];
    }

    void push(int u){
        if (!lazy[u]){
            return;
        }
        update(ls(u), lazy[u]);
        update(rs(u), lazy[u]);
        lazy[u] = 0;
    }

    void update(int u, int value){
        sum1[u] += value * sum[u];
        key1[u] += value * key[u];
        lazy[u] += value;
    }

    int build(int sit, ll *c, int l, int r){
        if (l > r){
            return 0;
        }
        int mid = (l + r + 1) / 2;
        val[sit] = c[mid];
        ls(sit) = build(sit << 1, c, l, mid - 1);
        rs(sit) = build(sit << 1 | 1, c, mid + 1, r);
        return sit;
    }

    void build(ll *c, int cnt){
        root = build(1, c, 0, cnt - 1);
    }

    pii split(int p, ll u){
        if (!p) return {0, 0};
        push(p);
        if (val[p] <= u){
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
        if (u < v){
            push(u);
            rs(u) = merge(rs(u), v);
            pull(u);
            return u;
        }
        push(v);
        ls(v) = merge(u, ls(v));
        pull(v);
        return v;
    }

    void insert(ll x){
        pii pair = split(root, x);
        pii pair1 = split(pair.first, x - 1);
        int node = pair1.second;
        key[node] = x;
        key1[node] = (sz[pair1.first] + 1) * x;
        cnt[node] = 1;
        pull(node);
        update(pair.second, 1);
        root = merge(pair1.first, node);
        root = merge(root, pair.second);
    }

    void erase(ll x){
        pii pair = split(root, x);
        update(pair.second, -1);
        pii pair1 = split(pair.first, x - 1);
        int node = pair1.second;
        key[node] = 0;
        key1[node] = 0;
        cnt[node] = 0;
        pull(node);
        root = merge(pair1.first, node);
        root = merge(root, pair.second);
    }

    pii pre(int u, int count){
        if (!u || count <= 0){
            return {0, 0};
        }
        if (count >= sz[u]){
            return {sum[u], sum1[u]};
        }
        push(u);
        if (count <= sz[ls(u)]){
            return pre(ls(u), count);
        }
        pii ret = pre(rs(u), count - sz[ls(u)] - cnt[u]);
        ll x = ret.first + sum[ls(u)] + key[u];
        ll y = ret.second + sum1[ls(u)] + key1[u];
        return {x, y};
    }

    pii suf(int u, int count){
        if (!u || count <= 0){
            return {0, 0};
        }
        if (count >= sz[u]){
            return {sum[u], sum1[u]};
        }
        push(u);
        if (count <= sz[rs(u)]){
            return suf(rs(u), count);
        }
        pii ret = suf(ls(u), count - sz[rs(u)] - cnt[u]);
        ll x = ret.first + sum[rs(u)] + key[u];
        ll y = ret.second + sum1[rs(u)] + key1[u];
        return {x, y};
    }
};

Treap treap;

ll a[N], b[N], c[N];
int type[N];

ll calc(){
    int sz = treap.sz[treap.root];
    if (sz <= 1){
        return 0;
    }
    pii tot = treap.pre(treap.root, sz);
    pii left = treap.pre(treap.root, (sz + 1) / 2);
    pii right = treap.suf(treap.root, (sz - 1) / 2);
    if (right.first <= left.first){
        right = treap.suf(treap.root, sz - 1);
        ll add = tot.first * (sz + 1) - tot.second;
        ll sub = right.second - right.first;
        ll valid = add - sub;
        return tot.first - valid;
    }
    int l = 1, r = (sz + 1) / 2;
    while (l < r){
        int mid = (l + r + 1) / 2;
        if (treap.pre(treap.root, mid).first <= treap.suf(treap.root, mid - 1).first){
            r = mid - 1;
        }
        else{
            l = mid;
        }
    }
    left = treap.pre(treap.root, l);
    right = treap.suf(treap.root, l - 1);
    ll add = left.first * (l + 1) - left.second;
    ll sub = right.second - right.first * (sz - l + 1);
    ll valid = (add - sub) * 2;
    return tot.first - valid;
}

int main(){
    int n, q;
    read(n), read(q);
    int cnt = 0;
    for (int i = 0; i < n; ++ i){
        read(a[i]);
        c[cnt ++] = a[i];
    }
    for (int i = 0; i < q; ++ i){
        scanf("%d%lld", &type[i], &b[i]);
        c[cnt ++] = b[i];
    }
    std::sort(c, c + cnt);
    cnt = std::unique(c, c + cnt) - c;
    treap.build(c, cnt);
    for (int i = 0; i < n; ++ i){
        treap.insert(a[i]);
    }
    printf("%lld\n", calc());
    for (int i = 0; i < q; ++ i){
        int op = type[i];
        ll x = b[i];
        if (op == 1){
            treap.insert(x);
        }
        else{
            treap.erase(x);
        }
        printf("%lld\n", calc());
    }
    return 0;
}