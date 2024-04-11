#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
const int maxc = 1e5;
int a[maxn], st[maxn * 4], tg[maxn * 4], xr[maxn * 4];

void push(int o) {
    if (tg[o] != -1) {
        st[o * 2 + 1] = tg[o * 2 + 1] = tg[o];
        st[o * 2 + 2] = tg[o * 2 + 2] = tg[o];
        xr[o * 2 + 1] = xr[o * 2 + 2] = 0;
        tg[o] = -1;
    }
    if (xr[o]) {
        st[o * 2 + 1] ^= 1;
        xr[o * 2 + 1] ^= 1;
        st[o * 2 + 2] ^= 1;
        xr[o * 2 + 2] ^= 1;
        xr[o] = 0;
    }
}

void modify(int l, int r, int ql, int qr, int v, int o = 0) {
    if (l >= qr || ql >= r) return;
    if (l >= ql && r <= qr) {
        if (v <= 1) {
            xr[o] = 0;
            tg[o] = v;
            st[o] = v;
        } else {
            xr[o] ^= 1;
            st[o] ^= 1;
        }
        return;
    }
    push(o);
    modify(l, (l + r) >> 1, ql, qr, v, o * 2 + 1);
    modify((l + r) >> 1, r, ql, qr, v, o * 2 + 2);
}

int query(int l, int r, int p, int o = 0) {
    if (r - l == 1) return st[o];
    push(o);
    if (p < (l + r) >> 1) 
        return query(l, (l + r) >> 1, p, o * 2 + 1);
    else 
        return query((l + r) >> 1, r, p, o * 2 + 2);
}

int main() {
    int n, q; scanf("%d%d", &n, &q);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    memset(tg, -1, sizeof(tg));

    for (int i = 0; i < q; ++i) {
        char s[2]; int x;
        scanf("%s%d", s, &x);

        if (s[0] == '>') {
            modify(0, maxn, abs(x) + 1 + maxc, maxn, 1);
            modify(0, maxn, 0, maxc - abs(x), 0);

            if (x < 0)
                modify(0, maxn, x + 1 + maxc, -x + maxc, 2);
            if (x < 0 && query(0, maxn, -x + maxc) == 0)
                modify(0, maxn, -x + maxc, -x + maxc + 1, 1);
            if (x < 0 && query(0, maxn, x + maxc) == 1)
                modify(0, maxn, x + maxc, x + maxc + 1, 0);
        } else {
            modify(0, maxn, abs(x) + 1 + maxc, maxn, 0);
            modify(0, maxn, 0, maxc - abs(x), 1);

            if (x > 0)
                modify(0, maxn, -x + maxc + 1, x + maxc, 2);
            if (x > 0 && query(0, maxn, -x + maxc) == 0)
                modify(0, maxn, -x + maxc, -x + maxc + 1, 1);
            if (x > 0 && query(0, maxn, x + maxc) == 1)
                modify(0, maxn, x + maxc, x + maxc + 1, 0);
        }
    }

    for (int i = 0; i < n; ++i) {
        if (query(0, maxn, a[i] + maxc) == 0) printf("%d ", a[i]);
        else printf("%d ", -a[i]);
    }
    puts("");
    return 0;
}