#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

#define ll long long
const int MAXN = 700700;
int n, m, q, a[MAXN]; set <int> s[MAXN];

struct node {
    int x, prex, t, val, id;
    node (int _x = 0, int _p = 0, int _t = 0, int _v = 0, int _i = 0) { x = _x, prex = _p, t = _t, val = _v, id = _i; }
} t[MAXN]; int top;
int pre (int x) { auto it = s[a[x]].find(x); return it == s[a[x]].begin() ? -1 : *(--it); }
int nex (int x) { auto it = ++s[a[x]].find(x); return it == s[a[x]].end() ? -1 : *it; }

namespace BIT {
    ll tree[MAXN];
    inline int lowbit (int x) { return x & -x; }
    inline ll sum (int x) { ll ret = 0; while (x) ret += tree[x], x -= lowbit(x); return ret; }
    inline void add (int x, int k) { while (x <= n) tree[x] += k, x += lowbit(x); }
}
bool cmp (node x, node y) { if (x.x == y.x) return x.id < y.id; return x.x < y.x; }

ll ans[MAXN];
void solve (int l, int r) {
    if (l == r) return;
    int mid = (l + r) >> 1, i, j;
    solve(l, mid), solve(mid + 1, r);
    sort(t + l, t + mid + 1, cmp); sort(t + mid + 1, t + r + 1, cmp);
    for (i = l, j = mid + 1; i <= mid || j <= r;) {
        if ((i <= mid && j <= r && cmp(t[i], t[j])) || j > r) {
            if (!t[i].id) BIT::add(t[i].prex, t[i].val);
            ++i;
        }
        else {
            if (t[j].id) ans[t[j].id] += BIT::sum(n) - BIT::sum(t[j].prex - 1);
            ++j;
        }
    }
    for (i = l; i <= mid; i++) if (!t[i].id) BIT::add(t[i].prex, -t[i].val);
}

int main () {
    n = read(), m = read(); int i, j;
    for (i = 1; i <= n; i++) a[i] = read(), s[a[i]].insert(i);
    for (i = 1; i <= n; i++) {
        j = pre(i);
        if (j != -1) t[++top] = node(i, j, 0, i - j, 0);
    }
    for (i = 1; i <= m; i++) {
        int op = read();
        if (op == 1) {
            int x = read(), k = read();
            int p = pre(x), q = nex(x);
            if (p != -1 && q != -1) t[++top] = node(q, p, i, q - p, 0);
            if (p != -1) t[++top] = node(x, p, i, -(x - p), 0);
            if (q != -1) t[++top] = node(q, x, i, -(q - x), 0);
            s[a[x]].erase(x);
            a[x] = k; s[k].insert(x);
            p = pre(x), q = nex(x);
            if (p != -1 && q != -1) t[++top] = node(q, p, i, -(q - p), 0);
            if (p != -1) t[++top] = node(x, p, i, x - p, 0);
            if (q != -1) t[++top] = node(q, x, i, q - x, 0);
        }
        else {
            int l = read(), r = read();
            t[++top] = node(r, l, i, 0, ++q);
        }
    }
    solve(1, top);
    for (i = 1; i <= q; i++) printf("%lld\n", ans[i]);
    return 0;
}