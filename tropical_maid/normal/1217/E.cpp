#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

/*
Author : Tropical_maid
Created : 2019/09/06, 00:05:55
*/

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

const int inf = 1e9 + 5;

pii operator+(pii a, pii b) {
    if (a.fs > b.fs) a.se = a.fs, a.fs = b.fs;
    else if (a.se > b.fs) a.se = b.fs;
    if (a.fs > b.se) a.se = a.fs, a.fs = b.se;
    else if (a.se > b.se) a.se = b.se;
    return a;
}

const int sz = 1 << 18;
struct segtree {
    pii seg[sz << 1];
    segtree() {
        for (int i = 0; i < (sz << 1); ++i) seg[i] = pii(inf, inf);
    }
    void init() {
        for (int i = sz; --i; ) seg[i] = seg[i << 1] + seg[i << 1 | 1];
    }
    void update(int x, int v) {
        x += sz;
        seg[x] = pii(v, inf);
        while (x >>= 1)
            seg[x] = seg[x << 1] + seg[x << 1 | 1];
    }
    pii query(int x, int y) {
        x += sz;
        y += sz;
        pii ret = pii(inf, inf);
        while (x <= y) {
            if ((x & 1) == 1) ret = ret + seg[x++];
            if ((y & 1) == 0) ret = ret + seg[y--];
            x >>= 1;
            y >>= 1;
        }
        return ret;
    }
} seg[10];

void update(int i, int x) {
    for (int j = 0, k = x; j < 10; ++j, k /= 10) {
        if (k % 10 > 0) seg[j].update(i, x);
        else seg[j].update(i, inf);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        for (int j = 0, k = x; j < 10; ++j, k /= 10) {
            if (k % 10 > 0) seg[j].seg[i + sz] = pii(x, inf);
            else seg[j].seg[i + sz] = pii(inf, inf);
        }
    }
    for (int i = 0; i < 10; ++i) seg[i].init();
    while (q--) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1) update(x, y);
        else {
            int ans = inf + inf;
            for (int i = 0; i < 10; ++i) {
                pii ret = seg[i].query(x, y);
                if (ret.se == inf) continue;
                ans = min(ans, ret.fs + ret.se);
            }
            printf("%d\n", ans < inf + inf ? ans : -1);
        }
    }
    return 0;
}