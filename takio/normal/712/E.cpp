#include <bits/stdc++.h>
#define LL long long
#define pii pair <int, int>
#define xx first
#define yy second
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r
using namespace std;

const int N = 110000, mod = 1e9 + 7;

//long double a[N << 2], b[N << 2], c[N << 2], d[N << 2];

int x[N], y[N];

struct data {
    long double a, b, c, d;
    data () {}
    data (long double a, long double b, long double c, long double d) : a (a), b (b), c (c), d (d) {}
} t[N << 2];

data add (data x, data y) {
    data z;
    long double t = 1.0 - y.a * x.d;
    z.a = x.a + x.b * x.c * y.a / t;
    z.b = x.b * y.b / t;
//    long double t2 = 1.0 - a[ls] * d[rs];
    z.c = x.c * y.c / t;
    z.d = y.d + x.d * y.b * y.c / t;
    return z;
}

void build (int rt, int l, int r) {
    if (l == r) {
        t[rt].b = t[rt].d = 1.0 * x[l] / y[l];
        t[rt].a = t[rt].c = 1 - t[rt].b;
        return;
    }
    int m = l + r >> 1;
    build (lson);
    build (rson);
    t[rt] = add (t[ls], t[rs]);
}

void updata (int rt, int l, int r, int z) {
    if (l == r) {
        t[rt].b = t[rt].d = 1.0 * x[l] / y[l];
        t[rt].a = t[rt].c = 1 - t[rt].b;
        return;
    }
    int m = l + r >> 1;
    if (z <= m) updata (lson, z);
    else updata (rson, z);
    t[rt] = add (t[ls], t[rs]);
}

data query (int rt, int l, int r, int tl, int tr) {
    if (tl <= l && r <= tr) return t[rt];
    int m = l + r >> 1;
    if (tr <= m) return query (lson, tl, tr);
    else if (m < tl) return query (rson, tl, tr);
    else return add (query (lson, tl, m), query (rson, m + 1, tr));
}



int main () {
//    freopen ("in.txt", "r", stdin);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) scanf ("%d%d", &x[i], &y[i]);
    build (1, 1, n);
    while (q--) {
        int t, u, v, w;
        scanf ("%d%d%d", &t, &u, &v);
        if (t == 2) {
            data tmp = query (1, 1, n, u, v);
//            cout << u << ' ' << v << ' ' << tmp.a << ' ' << tmp.b << endl;
            printf ("%.10f\n", (double)tmp.b);
        } else {
            scanf ("%d", &w);
            x[u] = v;
            y[u] = w;
            updata (1, 1, n, u);
        }
    }
}