#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cassert>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

using ll = long long;
const int MAXN = 200200;
int n, m; struct pt { ll x, p; int id; } a[MAXN];
bool ans[MAXN];
ll pre[MAXN], b[MAXN], top;
int Hash(ll x) { return lower_bound(b + 1, b + top + 1, x) - b; }
ll s0[MAXN], s1[MAXN], s2[MAXN];

int main() {
    int T = read(); while (T--) {
        n = read(), m = read(); int i, j;
        for (i = 1; i <= n; i++) a[i].x = read(), a[i].p = read(), a[i].id = i, ans[i] = 1, b[++top] = a[i].x;
        sort(a + 1, a + n + 1, [](pt u, pt v) { return u.x < v.x; });
        sort(b + 1, b + top + 1); top = unique(b + 1, b + top + 1) - b - 1;
        for (i = 1; i <= n; i++) {
            const int here = Hash(a[i].x);
            int tmp = Hash(a[i].x - a[i].p);
            s0[tmp] += a[i].p - (a[i].x - b[tmp]) - b[tmp], s0[here] -= a[i].p - (a[i].x - b[tmp]) - b[tmp];
            s1[tmp]++, s1[here]--;
            tmp = upper_bound(b + 1, b + top + 1, a[i].x + a[i].p) - b - 1;
            s0[here] += a[i].p + a[i].x, s0[tmp + 1] -= a[i].p + a[i].x;
            s2[here]++, s2[tmp + 1]--;
        }
        for (i = 1; i <= top; i++) {
            s0[i] += s0[i - 1], s1[i] += s1[i - 1], s2[i] += s2[i - 1];
            pre[i] = s0[i] + s1[i] * b[i] - s2[i] * b[i];
        }
        ll mx = -1e18;
        for (i = 1; i <= n; i++) {
            ans[a[i].id] &= (a[i].p - a[i].x) >= mx;
            if (pre[Hash(a[i].x)] > m) mx = max(mx, pre[Hash(a[i].x)] - m - a[i].x);
        }
        mx = -1e18;
        for (i = n; i >= 1; i--) {
            ans[a[i].id] &= (a[i].p + a[i].x) >= mx;
            if (pre[Hash(a[i].x)] > m) mx = max(mx, pre[Hash(a[i].x)] - m + a[i].x);
        }
        for (i = 1; i <= n; i++) printf("%d", ans[i]); putchar('\n');
        for (i = 1; i <= n + 1; i++) s1[i] = s2[i] = s0[i] = pre[i] = b[i] = 0, top = 0;
    }
    return 0;
}