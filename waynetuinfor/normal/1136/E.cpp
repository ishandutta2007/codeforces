#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
const long long inf = 1e18;
long long k[maxn], p[maxn], st[maxn * 4], tg[maxn * 4];
int a[maxn]; 

void build(int l, int r, int o = 0) {
    tg[o] = -inf;
    if (r - l == 1) {
        st[o] = a[l] - k[l];
        return;
    }
    build(l, (l + r) >> 1, o * 2 + 1);
    build((l + r) >> 1, r, o * 2 + 2);
    st[o] = st[o * 2 + 1] + st[o * 2 + 2];
}

void push(int o, int l, int r) {
    if (tg[o] == -inf) return;

    int m = (l + r) >> 1;
    st[o * 2 + 1] = tg[o] * (m - l);
    tg[o * 2 + 1] = tg[o];
    st[o * 2 + 2] = tg[o] * (r - m);
    tg[o * 2 + 2] = tg[o];

    tg[o] = -inf;
}

long long query(int l, int r, int ql, int qr, int o = 0) {
    if (l >= qr || ql >= r) return 0;
    if (l >= ql && r <= qr) return st[o];
    push(o, l, r);
    return query(l, (l + r) >> 1, ql, qr, o * 2 + 1) +
           query((l + r) >> 1, r, ql, qr, o * 2 + 2);
}

void modify(int l, int r, int ql, int qr, long long v, int o = 0) {
    if (l >= qr || ql >= r) return;
    if (l >= ql && r <= qr) {
        st[o] = v * (r - l);
        tg[o] = v;
        return;
    }
    push(o, l, r);
    modify(l, (l + r) >> 1, ql, qr, v, o * 2 + 1);
    modify((l + r) >> 1, r, ql, qr, v, o * 2 + 2);
    st[o] = st[o * 2 + 1] + st[o * 2 + 2];
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 1; i < n; ++i) {
        scanf("%lld", &k[i]);
        k[i] += k[i - 1];
        p[i] = p[i - 1] + k[i];
    }

    build(0, n);

    int q; scanf("%d", &q);
    while (q--) {
        char s[2]; scanf("%s", s);
        if (s[0] == 's') {
            int l, r; scanf("%d%d", &l, &r);
            printf("%lld\n", query(0, n, l - 1, r) + p[r - 1] - (l - 1 == 0 ? 0 : p[l - 2]));
            continue;
        } 

        int i, x; scanf("%d%d", &i, &x);
        long long v = query(0, n, i - 1, i) + x;

        int l = i - 1, r = i;
        for (int d = 20; d >= 0; --d) {
            if (r + (1 << d) <= n) {
                if (query(0, n, r - 1 + (1 << d), r + (1 << d)) < v)
                    r += (1 << d); 
            }
        }
        modify(0, n, l, r, v);
    }
}