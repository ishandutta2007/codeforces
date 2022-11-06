#include <bits/stdc++.h>
using namespace std;

const int maxn = 1048576;
int a[maxn], b[maxn];
int st[maxn * 4], tg[maxn * 4];

void push(int o) {
    st[o * 2 + 1] += tg[o];
    tg[o * 2 + 1] += tg[o];
    st[o * 2 + 2] += tg[o];
    tg[o * 2 + 2] += tg[o];
    tg[o] = 0;
}

void modify(int l, int r, int ql, int qr, int v, int o = 0) {
    if (l >= qr || ql >= r) return;
    if (l >= ql && r <= qr) {
        st[o] += v;
        tg[o] += v;
        return;
    }

    push(o);
    modify(l, (l + r) >> 1, ql, qr, v, o * 2 + 1);
    modify((l + r) >> 1, r, ql, qr, v, o * 2 + 2);

    st[o] = max(st[o * 2 + 1], st[o * 2 + 2]);
}

int query(int l, int r, int o = 0) {
    if (r - l == 1) return l;
    push(o);
    if (st[o * 2 + 2] > 0) return query((l + r) >> 1, r, o * 2 + 2);
    else return query(l, (l + r) >> 1, o * 2 + 1);
}

int main() {
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        modify(0, maxn, 0, a[i] + 1, 1);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d", &b[i]);
        modify(0, maxn, 0, b[i] + 1, -1);
    }

    int q; scanf("%d", &q);
    while (q--) {
        int t, p, v; scanf("%d%d%d", &t, &p, &v); --p;
        if (t == 1) {
            modify(0, maxn, 0, a[p] + 1, -1);
            modify(0, maxn, 0, v + 1, 1);
            a[p] = v;
        } else {
            modify(0, maxn, 0, b[p] + 1, 1);
            modify(0, maxn, 0, v + 1, -1);
            b[p] = v;
        }

        int res = query(0, maxn);
        if (res == 0) res = -1;

        printf("%d\n", res);
    }
    return 0;
}