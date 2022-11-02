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

const LL N = 610000, SZ = 610000;

int ll[SZ], rr[SZ], pos[N], sz, all;
LL sum[SZ], a[N];
multiset <LL> st[SZ];

inline void f (LL p, LL i, LL x) {
    st[p].erase(st[p].find (a[i]));
    a[i] += x;
    st[p].insert(a[i]);
}

inline void updata (int l, int r, int x) {
    if (x == 0) return;
    int pl = pos[l], pr = pos[r];
    if (pl == pr) {
        for (int i = l; i <= r; i++) f (pl, i, x);
        return;
    }
    for (int i = l; i <= rr[pl]; i++) f (pl, i, x);
    for (int i = ll[pr]; i <= r; i++) f (pr, i, x);
    for (int i = pl + 1; i <= pr - 1; i++) sum[i] += x;
}

inline int query (LL x) {
    int mn = 1e9, mx = 0;
    for (int i = 1; i <= all; i++) if (st[i].find (x - sum[i]) != st[i].end ()) {
        for (int j = ll[i]; j <= rr[i]; j++)
            if (sum[i] + a[j] == x) { mn = j; break; }
        break;
    }
    if (mn == 1e9) return -1;
    for (int i = all; i >= 1; i--) if (st[i].find (x - sum[i]) != st[i].end ()) {
        for (int j = rr[i]; j >= ll[i]; j--)
            if (sum[i] + a[j] == x) { mx = j; break; }
        break;
    }
    return mx - mn;
}

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, q;
    cin >> n >> q;
    sz = max ((int)sqrt (n * 2), 1);
    for (LL i = 1; i <= n; i++) {
        scanf ("%I64d", &a[i]);
    }
    all = 0;
    for (LL i = 1; i <= n; i++) {
        if ((i - 1) % sz == 0) {
            all++;
            ll[all] = i;
        }
        st[all].insert (a[i]);
        rr[all] = i;
        pos[i] = all;
    }
    int l, r, x, t;
    while (q--) {
        scanf ("%d", &t);
        if (t == 1) {
            scanf ("%d%d%d", &l, &r, &x);
            updata (l, r, x);
        } else {
            scanf ("%d", &x);
            printf ("%d\n", query (x));
        }
    }
}