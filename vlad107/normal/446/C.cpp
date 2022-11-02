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

const int BASE = 1000000009;
const int N = 400500;

struct Tree {
    int sum, a0, a1, l, r;
    Tree() {};
    Tree(int l, int r) : l(l), r(r), sum(0), a0(0), a1(0) {};
    void print() {
        fprintf(stderr, "%d %d %d %d %d\n", sum, a0, a1, l, r);
    }
};

Tree tr[5 * N];
int n, m, a[N], from, f0[N], g0[N], g1[N], f1[N], fib[N];

void addBASE(int &x, long long y) {
    x = (x + y) % BASE;
}

void push(int x) {
    if ((tr[x].a0 != 0) || (tr[x].a1 != 0)) {
        int len = tr[x].r - tr[x].l;
        addBASE(tr[x].sum, g0[len] * 1LL * tr[x].a0);
        addBASE(tr[x].sum, g1[len] * 1LL * tr[x].a1);
        if (tr[x].l != tr[x].r) {
            addBASE(tr[x + x].a0, tr[x].a0);
            addBASE(tr[x + x].a1, tr[x].a1);
            addBASE(tr[x + x + 1].a0, tr[x].a0 * 1LL * f0[tr[x + x + 1].l - tr[x].l]);
            addBASE(tr[x + x + 1].a0, tr[x].a1 * 1LL * f1[tr[x + x + 1].l - tr[x].l]);
            addBASE(tr[x + x + 1].a1, tr[x].a0 * 1LL * f0[tr[x + x + 1].l - tr[x].l + 1]);
            addBASE(tr[x + x + 1].a1, tr[x].a1 * 1LL * f1[tr[x + x + 1].l - tr[x].l + 1]);
        }
        tr[x].a0 = 0;
        tr[x].a1 = 0;
    }
}

void upd(int x) {
    tr[x].sum = (tr[x + x].sum + tr[x + x + 1].sum) % BASE;
    addBASE(tr[x].sum, g0[tr[x + x].r - tr[x + x].l] * 1LL * tr[x + x].a0);
    addBASE(tr[x].sum, g1[tr[x + x].r - tr[x + x].l] * 1LL * tr[x + x].a1);
    addBASE(tr[x].sum, g0[tr[x + x + 1].r - tr[x + x + 1].l] * 1LL * tr[x + x + 1].a0);
    addBASE(tr[x].sum, g1[tr[x + x + 1].r - tr[x + x + 1].l] * 1LL * tr[x + x + 1].a1);
}

void build(int x, int l, int r) {
    tr[x] = Tree(l, r);
    if (l < r) {
        int mid = (l + r) / 2;
        build(x + x, l, mid);
        build(x + x + 1, mid + 1, r);
        upd(x);
    } else {
        tr[x].sum = a[l];
    }
}

void add(int x, int l, int r) {
    push(x);
    if ((r < tr[x].l) || (l > tr[x].r)) {
        return;
    }
    if ((l <= tr[x].l) && (r >= tr[x].r)) {
        tr[x].a0 += fib[tr[x].l - from];
        tr[x].a1 += fib[tr[x].l - from + 1];
        // tr[x].print();
        return;
    }
    add(x + x, l, r);
    add(x + x + 1, l, r);
    upd(x);
}

int fsum(int x, int l, int r) {
    // tr[x].print();
    push(x);
    if ((r < tr[x].l) || (l > tr[x].r)) {
        return 0;
    }
    if ((l <= tr[x].l) && (r >= tr[x].r)) {
        return tr[x].sum;
    }
    int res = fsum(x + x, l, r) + fsum(x + x + 1, l, r);
    upd(x);
    if (res >= BASE) {
        res -= BASE;
    }
    return res;
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("1.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    f0[0] = 1;f0[1] = 0;
    f1[0] = 0;f1[1] = 1;
    g0[0] = 1;g0[1] = 1;
    g1[0] = 0;g1[1] = 1;
    fib[0] = 1;fib[1] = 1;
    for (int i = 2; i <= n; i++) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % BASE;
        f0[i] = (f0[i - 1] + f0[i - 2]) % BASE;
        f1[i] = (f1[i - 1] + f1[i - 2]) % BASE;
        g0[i] = (2 * g0[i - 1]) % BASE;
        if (i > 2) {
            g0[i] = (g0[i] - g0[i - 3] + BASE) % BASE;
        }
        g1[i] = (2 * g1[i - 1]) % BASE;
        if (i > 2) {
            g1[i] = (g1[i] - g1[i - 3] + BASE) % BASE; 
        }
    }
    // fprintf(stderr, "%d %d\n", f0[2], f1[2]);
    build(1, 0, n - 1);
    for (int i = 0; i < m; i++) {
        int qt, l, r;
        scanf("%d%d%d", &qt, &l, &r);
        --l;
        --r;
        from = l;
        if (qt == 1) {
            add(1, l, r);
        } else {
            printf("%d\n", fsum(1, l, r));
        }
    }
}