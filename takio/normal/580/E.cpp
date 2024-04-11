#include <bits/stdc++.h>
#define LL long long
#define pii pair <int, int>
#define piii pair <pii, int>
#define xx first
#define yy second
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r
using namespace std;

const int N = 100100, p1 = 17, p2 = 19, mod1 = 1e9 + 7, mod2 = 1e9 + 9;
int n, m, k;
int lazy[N << 2], a[N];
LL f1[N], f2[N], sf1[N], sf2[N];

struct data {
    int a, b, c;
    data (int a = 0, int b = 0, int c = 0) : a (a), b (b), c (c) {}
    bool operator == (const data x) const {
        return x.a == a && x.b == b && x.c == c;
    }
    void w () { cout << a << ' ' << b << ' ' << c << endl; }
} sum[N << 2];

data add (data a, data b) {
    return data (
        (f1[b.c] * a.a + b.a) % mod1,
        (f2[b.c] * a.b + b.b) % mod2,
        a.c + b.c
    );
}

void updata (int rt, int l, int r) {
    if (lazy[rt] != -1) {
        int c = lazy[rt], m = l + r >> 1;
        int ll = m - l, lr = r - m - 1;
        lazy[ls] = lazy[rs] = c;
        sum[ls] = data (sf1[ll] * c % mod1, sf2[ll] * c % mod2, ll + 1);
        sum[rs] = data (sf1[lr] * c % mod1, sf2[lr] * c % mod2, lr + 1);
        lazy[rt] = -1;
    }
}

void build (int rt, int l, int r) {
    if (l == r) { sum[rt] = data (a[l], a[l], 1); return; }
    int m = l + r >> 1;
    build (lson), build (rson);
    sum[rt] = add (sum[ls], sum[rs]);
}

void updata (int rt, int l, int r, int tl, int tr, int c) {
    if (tl <= l && r <= tr) { int len = tr - tl; sum[rt] = data (sf1[len] * c % mod1, sf2[len] * c % mod2, len + 1); lazy[rt] = c; return; }
    updata (rt, l, r);
    int m = l + r >> 1;
    if (tr <= m) updata (lson, tl, tr, c);
    else if (m < tl) updata (rson, tl, tr, c);
    else updata (lson, tl, m, c), updata (rson, m + 1, tr, c);
    sum[rt] = add (sum[ls], sum[rs]);
}

data query (int rt, int l, int r, int tl, int tr) {
    if (tl <= l && r <= tr) { return sum[rt]; }
    updata (rt, l, r);
    int m = l + r >> 1;
    if (tr <= m) return query (lson, tl, tr);
    else if (m < tl) return query (rson, tl, tr);
    else return add (query (lson, tl, m), query (rson, m + 1, tr));
}

int main () {
//    freopen ("in.txt", "r", stdin);
    sf1[0] = sf2[0] = f1[0] = f2[0] = 1;
    for (int i = 1; i < N; i++) f1[i] = f1[i - 1] * p1 % mod1, f2[i] = f2[i - 1] * p2 % mod2;
    for (int i = 1; i < N; i++) sf1[i] = (sf1[i - 1] + f1[i]) % mod1, sf2[i] = (sf2[i - 1] + f2[i]) % mod2;
    cin >> n >> m >> k;
    m += k;
    for (int i = 1; i <= n; i++) {
        scanf ("%1d", &a[i]);
    }
    memset (lazy, -1, sizeof lazy);
    build (1, 1, n);
    int t, x, y, c;
    while (m--) {
        scanf ("%d%d%d%d", &t, &x, &y, &c);
        if (t == 1) {
            updata (1, 1, n, x, y, c);
        } else {
            int len = y - x - c;
//            cout << len << endl;
            if (len == -1 || query (1, 1, n, x, x + len) == query (1, 1, n, y - len, y)) printf ("YES\n");
            else printf ("NO\n");
//            cout << len << ' ' << c << ' ' << x << ' ' << x + len << ' ' << y - len << ' ' << y << endl;
//            if (len != -1) {
//                query (1, 1, n, x, x + len).w ();
//                query (1, 1, n, y - len, y).w ();
//            }
        }
    }
}