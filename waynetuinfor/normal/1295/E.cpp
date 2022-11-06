#include <bits/stdc++.h>
using namespace std;

const int kN = 200'000 + 5;
const long long kInf = 1'000'000'000'000'000'000;
long long st[kN * 4], tg[kN * 4];
int p[kN], a[kN];

void Push(int o) {
    for (int i = 1; i <= 2; ++i) {
        tg[o * 2 + i] += tg[o];
        st[o * 2 + i] += tg[o];
    }
    tg[o] = 0;
}

void Modify(int l, int r, int ql, int qr, int v, int o = 0) {
    if (l >= qr || ql >= r) return;
    if (l >= ql && r <= qr) {
        tg[o] += v;
        st[o] += v;
        return;
    }
    Push(o);
    int m = (l + r) >> 1;
    Modify(l, m, ql, qr, v, o * 2 + 1);
    Modify(m, r, ql, qr, v, o * 2 + 2);
    st[o] = min(st[o * 2 + 1], st[o * 2 + 2]);
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &p[i]), p[i]--;
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i) Modify(0, n, p[i] + 1, n, a[i]);
    long long ans = kInf;
    for (int i = 0; i < n - 1; ++i) {
        Modify(0, n, 0, p[i], a[i]);
        Modify(0, n, p[i] + 1, n, -a[i]);
        ans = min(ans, st[0]);
    }
    printf("%lld\n", ans);
    return 0;
}