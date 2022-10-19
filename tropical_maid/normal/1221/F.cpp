#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

/*
Author : Tropical_maid
Created : 2019/09/20, 00:12:39
*/

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

int n;
vector<int> cp;
struct point {
    int x, y, c;
    void scan() {
        cin >> x >> y >> c;
        if (x > y) swap(x, y);
        cp.push_back(y);
    }
    bool operator<(const point &p) const {
        return x > p.x;
    }
} ps[500000];

pll seg[1 << 20];
llong add[1 << 20];

void init(int i, int s, int e) {
    if (s == e) {
        seg[i] = pll(-cp[s], cp[s]);
        return;
    }
    int m = (s + e) / 2;
    init(i << 1, s, m);
    init(i << 1 | 1, m + 1, e);
    seg[i] = max(seg[i << 1], seg[i << 1 | 1]);
}

void lazy(int i) {
    llong v = add[i];
    add[i] = 0;
    seg[i << 1 | 0].fs += v;
    seg[i << 1 | 1].fs += v;
    add[i << 1 | 0] += v;
    add[i << 1 | 1] += v;
}

void update(int i, int s, int e, int x, int v) {
    if (cp[e] < x) return;
    if (x <= cp[s]) {
        seg[i].fs += v;
        add[i] += v;
        return;
    }
    int m = (s + e) / 2;
    lazy(i);
    update(i << 1, s, m, x, v);
    update(i << 1 | 1, m + 1, e, x, v);
    seg[i] = max(seg[i << 1], seg[i << 1 | 1]);
}

const llong inf = 1e18;
pll query(int i, int s, int e, int x) {
    if (cp[e] < x) return pll(-inf, -1);
    if (x <= cp[s]) return seg[i];
    int m = (s + e) / 2;
    lazy(i);
    return max(query(i << 1, s, m, x), query(i << 1 | 1, m + 1, e, x));
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) ps[i].scan();
    sort(ps, ps + n);
    sort(cp.begin(), cp.end());
    cp.erase(unique(cp.begin(), cp.end()), cp.end());
    init(1, 0, (int)cp.size() - 1);
    llong ans = 0;
    int x = 2e9 - 5, y = 2e9 - 5;
    for (int i = 0; i < n; ++i) {
        update(1, 0, (int)cp.size() - 1, ps[i].y, ps[i].c);
        if (i + 1 < n && ps[i].x == ps[i + 1].x) continue;
        pll ret = query(1, 0, (int)cp.size() - 1, ps[i].x);
        ret.fs += ps[i].x;
        if (ret.fs > ans) {
            ans = ret.fs;
            x = ps[i].x;
            y = ret.se;
        }
    }
    printf("%lld\n%d %d %d %d\n", ans, x, x, y, y);
    return 0;
}