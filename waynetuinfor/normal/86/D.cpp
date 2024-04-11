#include <bits/stdc++.h>
#define getchar gtx
using namespace std;

inline int gtx() {
    const int N = 1048576;
    static char buffer[N];
    static char *p = buffer, *end = buffer;
    if (p == end) {
        if ((end = buffer + fread(buffer, 1, N, stdin)) == buffer) return EOF;
        p = buffer;
    }
    return *p++;
}

template <typename T>
inline bool rit(T& x) {
    char c = 0; bool flag = false;
    while (c = getchar(), (c < '0' && c != '-') || c > '9') if (c == -1) return false;
    c == '-' ? (flag = true, x = 0) : (x = c - '0');
    while (c = getchar(), c >= '0' && c <= '9') x = x * 10 + c - '0';
    if (flag) x = -x;
    return true;
}

template <typename T, typename ...Args>
inline bool rit(T& x, Args& ...args) { return rit(x) && rit(args...); }

const int maxn = 1e6 + 5;
int a[maxn], c[maxn];
int64_t ans[maxn], gans;

struct query { int l, r, idx, pos; } qr[maxn];

void add(int p, int v) {
    gans -= a[p] * 1ll * c[a[p]] * c[a[p]];
    c[a[p]] += v;
    gans += a[p] * 1ll * c[a[p]] * c[a[p]];
}

int main() {
    int n, t; rit(n, t);
    for (int i = 1; i <= n; ++i) rit(a[i]);
    int sz = 1 + (int)sqrt(n);
    for (int i = 0; i < t; ++i) {
        int l, r; rit(l, r);
        qr[i] = { l, r, i, l / sz };
    }
    sort(qr, qr + t, [](const query &i, const query &j) { return tie(i.pos, i.r) < tie(j.pos, j.r); });
    for (int i = 0, l = 1, r = 0; i < t; ++i) {
        while (r < qr[i].r) add(++r, 1); while (r > qr[i].r) add(r--, -1);
        while (l > qr[i].l) add(--l, 1); while (l < qr[i].l) add(l++, -1);
        ans[qr[i].idx] = gans;
    }
    for (int i = 0; i < t; ++i) printf("%" PRId64 "\n", ans[i]);
    return 0;
}