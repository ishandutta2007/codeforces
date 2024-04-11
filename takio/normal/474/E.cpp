#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <iostream>
#include <ctime>
#define LL long long
#define pii pair <LL, LL>
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r

using namespace std;

const LL N = 100100;
map <LL, LL> mp, id;

struct segmemt {
    LL mx[N << 2], id[N << 2];

    void build (LL rt, LL l, LL r) {
        mx[rt] = id[rt] = 0;
        if (l == r) return ;
        LL m = (l + r) >> 1;
        build (lson), build (rson);
    }

    void update (LL rt, LL l, LL r, LL x, LL val) {
//        cout << "update" << x << ' ' << val << ' '<< l << ' ' << r << endl;
        if (l == r) {
            mx[rt] = val;
            id[rt] = x;
            return ;
        }
        LL m = (l + r) >> 1;
        if (x <= m) update (lson, x, val);
        else update (rson, x, val);
        if (mx[ls] > mx[rs]) mx[rt] = mx[ls], id[rt] = id[ls];
        else mx[rt] = mx[rs], id[rt] = id[rs];
    }

    pii query (LL rt, LL l, LL r, LL tl, LL tr, LL n) {
        if (tl < 0 || tr < 0 || tl > n || tr > n) return pii (0, 0);
//        cout << l << ' ' << r << ' ' << tl << ' ' << tr << endl;
        if (tr <= 0) return pii (0, 0);
        if (tl <= l && r <= tr) {
            return pii (mx[rt], id[rt]);
        }
        LL m = (l + r) >> 1;
        if (tr <= m) return query (lson, tl, tr, n);
        if (tl > m) return query (rson, tl, tr, n);
        return max (query (lson, tl, m, n), query (rson, m + 1, tr, n));
    }
} sg;

LL n, a[N], b[N];

LL find1 (LL x) {
    LL f = 0, e = n + 1;
    while (f + 1 < e) {
        LL m = (f + e) / 2;
        if (b[m] >= x) e = m;
        else f = m;
    }
    return e;
}

LL find2 (LL x) {
    LL f = 0, e = n + 1;
    while (f + 1 < e) {
        LL m = (f + e) / 2;
        if (b[m] <= x) f = m;
        else e = m;
    }
    return f;
}
//
//bool cmp (data a, data b) {
//    return a.b < b.b;
//}

LL t[N], pre[N], gn[N];
vector <LL> g[N];

int main () {
//    freopen ("in.txt", "r", stdin);
    LL d;
    cin >> n >> d;
    for (LL i = 1; i <= n; i++) {
        scanf ("%I64d", &a[i]);
        b[i] = a[i];
        id[a[i]] = i;
    }
    for (LL i = 1; i <= n; i++) {
        LL idd = id[a[i]];
        g[idd].push_back (i);
    }
    sort (b + 1, b + 1 + n);
    b[n + 1] = 1LL << 60, b[0] = - b[n + 1];
    LL bn = 0;
    for (LL i = 1; i <= n; i++) {
        mp[b[i]] = ++bn;
    }
    sg.build (1, 1, n);
    LL res = 0, p = 0;
    memset (gn, -1, sizeof gn);
    for (LL i = 1; i <= n; i++) {
        LL l = find2 (a[i] - d), r = find1 (a[i] + d);
//        cout << a[i] << ' ' << mp[a[i]] << ' ' << l << ' ' << r << endl;
        pii u = max (sg.query (1, 1, n, 1, l, n), sg.query (1, 1, n, r, n, n));
        if (u.second == 0) pre[i] = 0;
        else {
            LL idd = id[b[u.second]];
            pre[i] = g[idd][gn[idd]];
        }
//        cout << pre[i] << ' ' << u.first << ' ' << u.second << endl;
        sg.update (1, 1, n, mp[a[i]], u.first + 1);
        if (u.first + 1 > res) res = u.first + 1, p = i;
//        cout << res << endl;
        gn[id[a[i]]]++;
    }
    LL tn = 0;
    while (p) {
//        cout << p << endl;
        t[++tn] = p;
        p = pre[p];
    }
    cout << res << endl;
    for (LL i = tn; i >= 1; i--) {
        if (i != tn) printf (" ");
        printf ("%I64d", t[i]);
    }
}