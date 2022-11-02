#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <cassert>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

const int N = 200500;
const int INF = 1e9;
const int K = 20;

struct Tree {
    int l, r, min;
    Tree () {}
};

Tree tr[4 * N];
int f0[N][K], f1[N][K], f[N], lt[N], a[N];
int n, s, l;

int getdiff(int l, int r) {
    int k = lt[r - l + 1];
    int pt = r - (1 << k) + 1;
    return max(f1[l][k], f1[pt][k]) - min(f0[l][k], f0[pt][k]);
}

void build(int x, int l, int r) {
    tr[x].l = l;
    tr[x].r = r;
    tr[x].min = INF;
    if (l < r) {
        int mid = l + (r - l) / 2;
        build(x + x, l, mid);
        build(x + x + 1, mid + 1, r);
    }
}

void modify(int x, int k, int val) {
    if (tr[x].l == tr[x].r) {
        tr[x].min = val;
        return;
    }
    if (k <= tr[x + x].r) modify(x + x, k, val); else
    modify(x + x + 1, k, val);
    tr[x].min = min(tr[x + x].min, tr[x + x + 1].min);
}

int fmin(int x, int l, int r) {
    if (l > tr[x].r) return INF;
    if (r < tr[x].l) return INF;
    if ((l <= tr[x].l) && (tr[x].r <= r)) return tr[x].min;
    return min(fmin(x + x, l, r), fmin(x + x + 1, l, r));
}


int main() {
//  freopen("input.txt", "r", stdin);
    scanf("%d%d%d", &n, &s, &l);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    lt[1] = 0;
    for (int i = 2; i <= n; i++) lt[i] = lt[i / 2] + 1;
    for (int i = 0; i < n; i++) {
        f0[i][0] = a[i];
        f1[i][0] = a[i];
    }
    for (int j = 1; j < 17; j++) {
        for (int i = 0; i < n; i++) {
            f0[i][j] = f0[i][j - 1];
            f1[i][j] = f1[i][j - 1];
            int ni = i + (1 << (j - 1));
            if (ni < n) {
                f0[i][j] = min(f0[i][j], f0[ni][j - 1]);
                f1[i][j] = max(f1[i][j], f1[ni][j - 1]);
            }
        }
    }
    build(1, -1, n - 1);
    modify(1, -1, 0);
    for (int i = 0; i < n; i++) {
        int ll = -1, rr = i;
        while (ll < rr - 1) {
            int mid = (ll + rr) / 2;
            int diff = getdiff(mid, i);
            if (diff <= s) {
                rr = mid;
            } else {
                ll = mid;
            }
        }
        int lx = rr - 1;
        int rx = i - l;
        if (lx > rx) f[i] = INF;
        else f[i] = fmin(1, lx, rx) + 1;
        if (f[i] >= INF) f[i] = INF;
        modify(1, i, f[i]);
    }
    if (f[n - 1] == INF) f[n - 1] = -1;
    printf("%d\n", f[n - 1]);
}