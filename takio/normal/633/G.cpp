#include <bits/stdc++.h>
#define LL long long
#define pii pair <LL, LL>
#define xx first
#define yy second
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r
using namespace std;

const int M = 1010, N = 100100;

bitset <M> sum[N << 2], pri, tmp;
int a[N], lazy[N << 2], m;
vector <int> g[N];
int an, L[N], R[N], is[N], p[N];

void build (int rt, int l, int r) {
    lazy[rt] = 0;
    sum[rt].reset();
    if (l == r) {
//        sum[rt].reset();
        sum[rt][a[p[l]]] = 1;
        return;
//        lazy[rt] = 0;
    }
    int m = l + r >> 1;
    build (lson);
    build (rson);
    sum[rt] = sum[ls] | sum[rs];
}

inline void add (int &a, int b) {
    a += b;
    if (a >= m) a -= m;
}

void change (bitset <M> &x, int y) {
    x = (x << y) | (x >> m - y);
}

void down (int rt) {
    if(lazy[rt]) {
        add (lazy[ls], lazy[rt]);
        add (lazy[rs], lazy[rt]);
        change (sum[ls], lazy[rt]);
        change (sum[rs], lazy[rt]);
        lazy[rt] = 0;
    }
}

void updata (int rt, int l, int r, int tl, int tr, int x) {
    if (tl <= l && r <= tr) {
        lazy[rt] += x;
        lazy[rt] %= m;
        change (sum[rt], x);
        return;
    }
    down (rt);
    int m = l + r >> 1;
    if (tr <= m) updata (lson, tl, tr, x);
    else if (m < tl) updata (rson, tl, tr, x);
    else updata (lson, tl, m, x), updata (rson, m + 1, tr, x);
    sum[rt] = sum[ls] | sum[rs];
}

bitset <M> query (int rt, int l, int r, int tl, int tr) {
    if (tl <= l && r <= tr) {
        return sum[rt];
    }
    down (rt);
    int m = l + r >> 1;
    if (tr <= m) return query (lson, tl, tr);
    else if (m < tl) return query (rson, tl, tr);
    else return (query (lson, tl, m) | query (rson, m + 1, tr));
//    sum[rt] = sum[ls] | sum[rs];
}

void dfs (int u, int fa) {
//    cout << u << ' ' << fa << endl;
    p[++an] = u;
    L[u] = an;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v == fa) continue;
        dfs (v, u);
    }
    R[u] = an;
}

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, u, v;
    cin >> n >> m;
    for (int i = 2; i < m; i++) if (!is[i]) {
        pri[i] = 1;
        for (int j = i + i; j < m; j += i) is[j] = 1;
    }
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &a[i]);
        a[i] %= m;
    }
    for (int i = 1; i < n; i++) {
        scanf ("%d%d", &u, &v);
        g[u].push_back (v);
        g[v].push_back (u);
    }
    dfs (1, 0);
//    for (int i = 1; i <= n; i++) cout << L[i] << ' ' << R[i] << endl;
//    return 0;
    build (1, 1, n);
    int q, t, x;
    cin >> q;
    while (q--) {
        scanf ("%d", &t);
        if (t == 1) {
            scanf ("%d%d", &u, &x);
            x %= m;
            updata (1, 1, n, L[u], R[u], x);
        } else {
            scanf ("%d", &u);
            tmp = query (1, 1, n, L[u], R[u]) & pri;
            printf ("%d\n", tmp.count());
        }
    }
}