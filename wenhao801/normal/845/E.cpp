#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

#define pii pair <int, int>
#define fr first
#define se second

const int MAXN = 3030;
int n, m, K;
pii a[MAXN];

struct mat { int p, k, l, r; bool operator < (const mat &tmp) const { return p < tmp.p; } } t[MAXN];
int b[MAXN], top, cur[MAXN];

inline int Hash (int x) { return lower_bound(b + 1, b + top + 1, x) - b; }
bool check (int mid) {
    int i, j;
    for (i = 1, j = 0; i <= K; i++) {
        ++j, t[j].p = max(1, a[i].fr - mid), t[j].k = 1, t[j].l = max(1, a[i].se - mid), t[j].r = min(m, a[i].se + mid);
        ++j, t[j].p = min(n + 1, a[i].fr + mid + 1), t[j].k = -1, t[j].l = max(1, a[i].se - mid), t[j].r = min(m, a[i].se + mid);
        b[++top] = t[j].l; b[++top] = t[j].r;
        b[++top] = max(1, t[j].l - 1), b[++top] = min(m, t[j].l + 1);
        b[++top] = max(1, t[j].r - 1), b[++top] = min(m, t[j].r + 1);
    }
    sort(b + 1, b + top + 1); top = unique(b + 1, b + top + 1) - b - 1;
    sort(t + 1, t + (K << 1) + 1);
    for (i = 1; i <= (K << 1); i++) t[i].l = Hash(t[i].l), t[i].r = Hash(t[i].r);
    int l = n, r = 1, d = top, u = 1;
    if (t[1].p != 1) l = 1, r = t[1].p - 1, d = 1, u = top;
    for (i = 1; i <= (K << 1); i++) {
        if (t[i].p == n + 1) break;
        for (j = i; j <= (K << 1) && t[j].p == t[i].p; j++) {
            for (int k = t[j].l; k <= t[j].r; k++) cur[k] += t[j].k;
        }
        i = j - 1;
        bool hav = 0;
        for (j = 1; j <= top; j++) if (!cur[j])
            hav = 1, u = max(u, j), d = min(d, j);
        // printf("x = %d | ? %d\n", t[i].p, hav);
        // for (j = 1; j <= top; j++) printf("%d ", cur[j]); putchar('\n');
        if (hav) l = min(l, t[i].p), r = max(r, ((i == (K << 1) || t[i + 1].p == n + 1) ? (n + 1) : t[i + 1].p) - 1);
    }
    if (t[K << 1].p <= n) l = min(l, t[K << 1].p), r = n, d = 1, u = top;
    // printf("%d %d %d %d\n", l, r, d, u);
    u = b[u], d = b[d];
    for (i = 1; i <= top; i++) b[i] = cur[i] = 0;
    top = 0;
    return max(u - d, r - l) <= (mid << 1);
}

int main () {
    n = read(), m = read(), K = read(); int i, j;
    for (i = 1; i <= K; i++) a[i].fr = read(), a[i].se = read();
    // printf("%d\n", check(3)); return 0;
    int L = 0, R = 1e9, ans = -1;
    while (L <= R) {
        int mid = (L + R) >> 1;
        if (check(mid)) R = mid - 1, ans = mid;
        else L = mid + 1;
    }
    printf("%d\n", ans);
    return 0;
}