#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>
#include <cassert>
#include <ctime>
#include <cstring>

using namespace std;

const int N = 1005000;
const int INF = (int)1e9;
const int K = 20;

struct Point {
    int l, r, q, cost;
    Point() {}
    Point(int l, int r, int q, int cost) : l(l), r(r), q(q), cost(cost) {}
};

struct Point2 {
    int w, l, r, q, cost;
    Point2() {}
    Point2(int w, int l, int r, int q, int cost) : w(w), l(l), r(r), q(q), cost(cost) {}
};

struct Tree {
    int l, r, mx;
    Tree() {}
};

int fa[N][K], lt[N], a[N], n, m, ans[N];
Tree tr[5 * N];

vector<Point> v;
vector<Point2> vv;


bool cmp0(Point u, Point v) {
    if (u.l != v.l) return u.l < v.l;
    return u.q < v.q;
}

bool cmp1(Point2 u, Point2 v) {
    if (u.w != v.w) return u.w > v.w;
    return u.q < v.q;
}

int fmin(int l, int r) {
    int k = lt[r - l + 1];
    return min(fa[l][k], fa[r - (1 << k) + 1][k]);
}

int find_l(int x) {
    int l = -1, r = x;
    while (l < r - 1) {
        int mid = (l + r) / 2;
        if (fmin(mid, x) >= a[x]) {
            r = mid;
        } else {
            l = mid;
        }
    }
    return r;
}

int find_r(int x) {
    int l = x, r = n;
    while (l < r - 1) {
        int mid = (l + r) / 2;
        if (fmin(x, mid) >= a[x]) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return l;
}

void build(int x, int l, int r) {
    tr[x].l = l;
    tr[x].r = r;
    tr[x].mx = -INF;
    if (l + 1 == r) return;
    build(x + x, l, (l + r) / 2);
    build(x + x + 1, (l + r) / 2, r);
}

void upd(int x, int u, int val) {
    if (tr[x].l + 1 == tr[x].r) {
        tr[x].mx = val;
        return;
    }
    if (u < tr[x + x].r) {
        upd(x + x, u, val);
    } else {
        upd(x + x + 1, u, val);
    }
    tr[x].mx = max(tr[x + x].mx, tr[x + x + 1].mx);
}

int fmax(int x, int l, int r) {
    if (r <= tr[x].l) return -INF;
    if (l >= tr[x].r) return -INF;
    if ((tr[x].l >= l) && (tr[x].r <= r)) {
        return tr[x].mx;
    }
    return max(fmax(x + x, l, r), fmax(x + x + 1, l, r));
}                                      

int main() {
//    freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        fa[i][0] = a[i];
    }
    lt[1] = 0;
    for (int i = 2; i <= n; i++) {
        lt[i] = lt[i / 2] + 1;
    }
    for (int j = 1; j < K; j++) {
        for (int i = 0; i < n; i++) {
            fa[i][j] = fa[i][j - 1];
            if (i + (1 << (j - 1)) < n) {
                fa[i][j] = min(fa[i][j], fa[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        int ri = find_r(i);
        int le = find_l(i);
//        fprintf(stderr, "%d: %d, %d\n", i, le, ri);
        v.push_back(Point(le, ri, 0, a[i]));
        vv.push_back(Point2(ri - le + 1, ri, ri, 0, a[i]));
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int lu, ru, wu;
        scanf("%d%d%d", &lu, &ru, &wu);
        --lu;
        --ru;
        v.push_back(Point(lu, lu + wu - 1, 1, i));
        v.push_back(Point(ru - wu + 1, ru, 1, i));

        vv.push_back(Point2(wu, lu + wu - 1, ru, 1, i));
    }
    sort(v.begin(), v.end(), cmp0);
    build(1, 0, n);
    for (int i = 0; i < (int)v.size(); i++) {
        if (v[i].q == 0) {
            upd(1, v[i].r, v[i].cost);
        } else {
            ans[v[i].cost] = max(ans[v[i].cost], fmax(1, v[i].r, n));
        }
    }

    sort(vv.begin(), vv.end(), cmp1);
    build(1, 0, n);
    for (int i = 0; i < (int)vv.size(); i++) {
//        cerr << vv[i].q << " " << vv[i].cost << endl;
        if (vv[i].q == 0) {
            upd(1, vv[i].r, vv[i].cost);
        } else {
            ans[vv[i].cost] = max(ans[vv[i].cost], fmax(1, vv[i].l, vv[i].r + 1));
        }
    }
    for (int i = 0; i < m; i++) printf("%d\n", ans[i]);
}