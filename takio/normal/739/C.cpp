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

const int N = 300010;

int a[N];

struct data {
    int t, lu, ld, ru, rd, mx;
    LL vl, vr;
    inline data () {}
    inline data (LL x) {
        vl = vr = x;
        lu = ld = ru = rd = mx = 1;
        t = -1;
    }
    void w () {
        cout << t << ' ' << lu << ' ' << ld << ' ' << ru << ' ' << rd << ' ' << mx << ' ' << vl << ' ' << vr << endl;
    }
//    data (int t, LL lu, LL ld, LL ru, LL rd) : t (t), lu (lu), ld (ld), ru (ru), rd (rd) {}
} c[N << 2];

LL lazy[N << 2];

inline data up (data a, data b) {
//    a.w ();
//    b.w ();
    data c;
    c.vl = a.vl;
    c.vr = b.vr;
    c.ld = a.ld;
    c.lu = a.lu;
    c.rd = b.rd;
    c.ru = b.ru;
    c.mx = max (a.mx, b.mx);
    c.t = 0;
    if (a.vr > b.vl) {
        c.mx = max (c.mx, a.ru + b.ld);
        c.mx = max (c.mx, a.rd + b.ld);
    }
    if (a.vr < b.vl) {
        c.mx = max (c.mx, a.rd + b.lu);
        c.mx = max (c.mx, a.rd + b.ld);
    }
    if (a.t == -1 || a.t == 1 || a.t == 2) {
        if (a.vr < b.vl && a.t != 1) c.lu = max (c.lu, b.lu + a.mx);
        if (a.vr > b.vl && a.t != 2) c.ld = max (c.ld, b.ld + a.mx);
        if (a.t != 1 && a.vr != b.vl) c.lu = max (c.lu, b.ld + a.mx);
    }
    if (b.t == -1 || b.t == 1 || b.t == 2) {
        if (a.vr < b.vl && b.t != 1) c.rd = max (c.rd, a.rd + b.mx);
        if (a.vr > b.vl && b.t != 2) c.ru = max (c.ru, a.ru + b.mx);
        if (b.t != 2 && a.vr != b.vl) c.ru = max (c.ru, a.rd + b.mx);
    }
//    if (a.t == 3 && )
    if (a.t == -1 && b.t == -1) {
        if (a.vr > b.vl) c.t = 1, c.ld = c.ru = 2;
        if (a.vr < b.vl) c.t = 2, c.lu = c.rd = 2;
    } else if ((a.t == 1 || a.t == -1) && (b.t == 1 || b.t == -1) && (a.vr > b.vl)) {
        c.t = 1;
        c.mx = c.ld = c.ru = a.mx + b.mx;
    } else if ((a.t == 2 || a.t == -1) && (b.t == 2 || b.t == -1) && (a.vr < b.vl)) {
        c.t = 2;
        c.mx = c.lu = c.rd = a.mx + b.mx;
    } else if ( (a.t == 3 || a.t == -1) && (a.vr > b.vl)) {
//        cout << "in" << endl;
        c.lu = max (c.lu, a.mx + b.ld);
        c.mx = max (c.mx, c.lu);
        if (b.t == 1 || b.t == -1) {
            c.t = 3;
            c.ru = max (a.ru, c.lu);
        } else c.t = 0;
    } else if ((b.t == 3 || b.t == -1) && (a.vr < b.vl)) {
        c.ru = max (c.ru, b.mx + a.rd);
        c.mx = max (c.mx, c.ru);
        if (a.t == 2 || a.t == -1) {
            c.t = 3;
            c.lu = max (c.lu, c.ru);
        } else c.t = 0;
    } else if ((a.t == 2 || a.t == -1) && (b.t == 1 || b.t == -1) && a.vr != b.vl) {
        c.t = 3;
    }
//    a.w ();
//    b.w ();
//    c.w ();
    return c;
}

inline void build (int rt, int l, int r) {
    lazy[rt] = 0;
    if (l == r) {
        c[rt] = data (a[l]);
        return;
    }
    int m = l + r >> 1;
    build (lson);
    build (rson);
//    cout << l << ' ' << m << ' ' << m + 1 << ' ' << r << endl;
    c[rt] = up (c[ls], c[rs]);
}

inline void down (int rt) {
    if (lazy[rt]) {
        lazy[ls] += lazy[rt];
        lazy[rs] += lazy[rt];
        c[ls].vl += lazy[rt];
        c[rs].vl += lazy[rt];
        c[ls].vr += lazy[rt];
        c[rs].vr += lazy[rt];
        lazy[rt] = 0;
    }
}

void updata (int rt, int l, int r, int tl, int tr, int val) {
//    cout << l << ' ' << r << ' ' << tl << ' ' << tr << endl;
    if (tl <= l && r <= tr ) {
        c[rt].vl += val;
        c[rt].vr += val;
        lazy[rt] += val;
        return;
    }
    int m = l + r >> 1;
    down (rt);
    if (tr <= m) updata (lson, tl, tr, val);
    else if (m < tl) updata (rson, tl, tr, val);
    else updata (lson, tl, m, val), updata (rson, m + 1, tr, val);
//    cout << l << ' ' << m << ' ' << m + 1 << ' ' << r << endl;
    c[rt] = up (c[ls], c[rs]);
}

int n;

int solve () {
    int r = 0;
//    for (int i = 1; i <= n; i++) cout << a[i] << ' '; cout << endl;
    for (int i = 1; i <= n; i++) {
        int c = 1, f = 1;
        for (int j = i + 1; j <= n; j++) {
            if (a[j] == a[j - 1]) break;
            if (a[j - 1] > a[j]) {
                if (f == 1) f = 2;
            }
            if (a[j - 1] < a[j]) {
                if (f == 2) break;
            }
            c++;
            r = max (r, c);
        }
    }
    return r;
}

void w () {
    srand (1999);
    freopen ("in.txt", "w", stdout);
    int T = 100;
    while (T--) {
        int n = 120, q = 100, c = 100;
        cout << n << endl;
        for (int i = 1; i <= n; i++) cout << rand () % c + 1 << ' '; cout << endl;
        cout << q << endl;
        for (int i = 1; i <= q; i++) {
            int l, r;
//            do {
            l = rand () % n + 1;
            r = rand () % n + 1;
            if (l > r) swap (l, r);
            cout << l << ' ' << r << ' ' << rand () % c + 1 << endl;
//            }
        }
    }
    exit (0);
}

int main () {
//    freopen ("in.txt", "r", stdin);
//    w ();
    while (cin >> n) {
        for (int i = 1; i <= n; i++) {
            scanf ("%d", &a[i]);
        }
        build (1, 1, n);
    //    cout << c[1].mx << endl;
        int q, l, r, v;
        cin >> q;
        while (q--) {
            scanf ("%d%d%d", &l, &r, &v);
            updata (1, 1, n, l, r, v);
            printf ("%d\n", c[1].mx);
//            for (int i = l; i <= r; i++) a[i] += v;
//            cout << solve () << ' ' << c[1].mx << endl;
//            assert (solve () == c[1].mx);
        }
    }
}