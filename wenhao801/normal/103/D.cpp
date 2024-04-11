#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

#define lint long long

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 300300;

int n;
lint a[MAXN << 1];
struct Q { int t, k, id; lint ans; } q[MAXN];
bool cmp (Q x, Q y) { if (x.k == y.k) return x.t > y.t; return x.k < y.k; }
bool cmp2 (Q x, Q y) { return x.id < y.id; }
lint s[MAXN << 1];

int main () {
    n = read();
    int SIZ = sqrt(n);
    int i, j;
    for (i = 1; i <= n; i++) a[i] = read();
    int m = read();
    for (i = 1; i <= m; i++) q[i].t = read(), q[i].k = read(), q[i].id = i;
    sort(q + 1, q + m + 1, cmp);
    for (i = 1, j = 1; i <= SIZ; i++) {
        int t = n + 1;
        while (q[j].k == i) {
            while (t != q[j].t) t--, s[t] = a[t] + s[t + q[j].k];
            q[j++].ans = s[t];
        }
    }
    for (j; j <= m; j++) {
        lint s = 0;
        for (i = q[j].t; i <= n; i += q[j].k) s += a[i];
        q[j].ans = s;
    }
    sort(q + 1, q + m + 1, cmp2);
    for (i = 1; i <= m; i++) printf("%lld\n", q[i].ans);
    return 0;
}