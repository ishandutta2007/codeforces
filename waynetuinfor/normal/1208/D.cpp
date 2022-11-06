#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
long long s[maxn], st[maxn * 4], tg[maxn * 4];
int a[maxn];

void build(int l, int r, int o = 0) {
    if (r - l == 1) 
        return st[o] = s[l], void();
    build(l, (l + r) >> 1, o * 2 + 1);
    build((l + r) >> 1, r, o * 2 + 2);
    st[o] = min(st[o * 2 + 1], st[o * 2 + 2]);
}

void push(int o) {
    st[o * 2 + 1] += tg[o];
    st[o * 2 + 2] += tg[o];
    tg[o * 2 + 1] += tg[o];
    tg[o * 2 + 2] += tg[o];
    tg[o] = 0;
}

void modify(int l, int r, int ql, int qr, long long v, int o = 0) {
    if (l >= ql && r <= qr) {
        st[o] += v;
        tg[o] += v;
        return;
    }
    if (l >= qr || ql >= r) return;
    push(o);
    modify(l, (l + r) >> 1, ql, qr, v, o * 2 + 1);
    modify((l + r) >> 1, r, ql, qr, v, o * 2 + 2);
    st[o] = min(st[o * 2 + 1], st[o * 2 + 2]);
}

int query(int l, int r, int o = 0) {
    if (r - l == 1) return l;
    push(o);
    if (st[o * 2 + 2] <= st[o * 2 + 1]) 
        return query((l + r) >> 1, r, o * 2 + 2);
    else
        return query(l, (l + r) >> 1, o * 2 + 1);
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%lld", &s[i]);
    build(0, n);
    for (int i = 1; i <= n; ++i) {
        int j = query(0, n);
        a[j] = i;
        modify(0, n, j + 1, n, -i);
        modify(0, n, j, j + 1, 1e12);
    }
    for (int i = 0; i < n; ++i) printf("%d ", a[i]);
    puts("");
    return 0;
}