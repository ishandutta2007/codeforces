#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <queue>
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r
#define getm int m = (l + r) >> 1
#define LL long long
#define ULL unsigned long long
#define pii pair <LL, int>

using namespace std;

const int N = 200100;

int d[N], h[N];
LL sum[N], t[N];

struct segment1 {
    pii mx[N << 2];

    void build (int rt, int l, int r) {
        if (l == r) { mx[rt] = pii (t[l], l); return; }
        getm;
        build (lson), build (rson);
        mx[rt] = max (mx[ls], mx[rs]);
    }

    pii query (int rt, int l, int r, int tl, int tr) {
//        cout << rt << ' ' << l << ' ' << r << ' ' << tl << ' ' << tr << endl;
        if (tl <= l && r <= tr) {
            return mx[rt];
        }
        getm;
        if (tr <= m) return query (lson, tl, tr);
        else if (m < tl) return query (rson, tl, tr);
        else return max (query (lson, tl, m), query (rson, m + 1, tr));
    }
} mxsg;

struct segment2 {
    pii mn[N << 2];

    void build (int rt, int l, int r) {
        if (l == r) { mn[rt] = pii (t[l], l); return; }
        getm;
        build (lson), build (rson);
        mn[rt] = min (mn[ls], mn[rs]);
    }

    pii query (int rt, int l, int r, int tl, int tr) {
//        cout << rt << ' ' << l << ' ' << r << ' ' << tl << ' ' << tr << endl;
        if (tl <= l && r <= tr) {
            return mn[rt];
        }
        getm;
        if (tr <= m) return query (lson, tl, tr);
        else if (m < tl) return query (rson, tl, tr);
        else return min (query (lson, tl, m), query (rson, m + 1, tr));
    }

} mnsg;

//struct qry {
//    int l, r, id;
//} q[N];
//
//bool cmp (qry a, qry b) {
//    if (pos[a.l] == pos[b.l]) return a.r < b.r;
//    return a.l < b.l;
//}

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
//    int sz = sqrt (2 * n), all = 0;
//    for (int i = 1, t = sz; i <= n; i++, t++) {
//        if (t == sz) {
//            t = 0;
//            cnt2[++all] = 0;
//            ll[all] = i;
//        }
//        rr[all] = i;
//        pos[i] = all;
//    }
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &d[i]);
        d[n + i] = d[i];
    }
    for (int i = 2; i <= 2 * n; i++) {
        sum[i] = sum[i - 1] + d[i - 1];
    }
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &h[i]);
        h[i] *= 2;
        h[n + i] = h[i];
    }
//    for (int i = 1; i <= 2 * n; i++) cout << sum[i] << ' '; cout << endl;
    for (int i = 1; i <= 2 * n; i++) {
        t[i] = sum[i] - h[i];
    }
    mnsg.build (1, 1, 2 * n);
//    for (int i = 1; i <= 2 * n; i++) cout << t[i] << ' '; cout << endl;
    for (int i = 1; i <= 2 * n; i++) {
        t[i] = sum[i] + h[i];
    }
    mxsg.build (1, 1, 2 * n);
//    for (int i = 1; i <= 2 * n; i++) cout << t[i] << ' '; cout << endl;
    int l, r, tl, tr;
    while (m--) {
        scanf ("%d%d", &tl, &tr);
        if (tl > tr) {
            l = tr + 1;
            r = tl - 1;
        } else {
            l = tr + 1;
            r = tl - 1 + n;
        }
//        cout << "l r" << l << ' ' << r << endl;
        pii t1 = mxsg.query(1, 1, 2 * n, l, r);
        pii t2 = mnsg.query(1, 1, 2 * n, l, r);
        pii t3, t4;
        LL t1f = t1.first, t2f = t2.first, t1s = t1.second, t2s = t2.second;
        LL res;
//        cout << t1s << ' ' << t2s << ' ' << t1f << ' ' << t2f << endl;
        if (t1s == t2s) {
            if (t1s == l) t3 = mxsg.query(1, 1, 2 * n, l + 1, r);
            else if (t1s == r) t3 = mxsg.query(1, 1, 2 * n, l, r - 1);
            else t3 = max (mxsg.query(1, 1, 2 * n, l, t1s - 1), mxsg.query(1, 1, 2 * n, t1s + 1, r));
            if (t2s == l) t4 = mnsg.query(1, 1, 2 * n, l + 1, r);
            else if (t2s == r) t4 = mnsg.query(1, 1, 2 * n, l, r - 1);
            else t4 = min (mnsg.query(1, 1, 2 * n, l, t2s - 1), mnsg.query(1, 1, 2 * n, t2s + 1, r));
//            cout << t3.first << ' ' << t4.first << endl;
            res = max (t3.first - t2f, t1f - t4.first);
        } else res = t1f - t2f;
        printf ("%I64d\n", res);
    }
}