#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 200200;
struct node { int ls, rs, val; } t[MAXN * 60];
int top = 1, rt[MAXN];
void modify (int pos, int l, int r, int o, int x) {
    if (l == r) { t[x].val = t[o].val + 1; return; }
    int mid = (l + r) >> 1;
    if (pos <= mid) { t[x].rs = t[o].rs; modify(pos, l, mid, t[o].ls, t[x].ls = ++top); }
    else { t[x].ls = t[o].ls; modify(pos, mid + 1, r, t[o].rs, t[x].rs = ++top); } 
    t[x].val = t[t[x].ls].val + t[t[x].rs].val;
}
int query (int l, int r, int L, int R, int o, int x) {
    if (l > r) return 0;
    if (l <= L && R <= r) { return t[x].val - t[o].val; }
    int ret = 0, mid = (L + R) >> 1;
    if (l <= mid) ret += query(l, r, L, mid, t[o].ls, t[x].ls);
    if (mid < r) ret += query(l, r, mid + 1, R, t[o].rs, t[x].rs);
    return ret;
}

int n, m;

int main () {
    int i, j; n = read(), m = read();
    for (i = 1; i <= n; i++) {
        j = read();
        rt[i] = ++top; modify(j, 1, n, rt[i - 1], rt[i]);
    }
    while (m--) {
        int l = read(), d = read(), r = read(), u = read();
        long long ans = 1ll * n * (n - 1) / 2;
        ans -= 1ll * (l - 1) * (l - 2) / 2; ans -= 1ll * (n - r) * (n - r - 1) / 2;
        long long _a = query(u + 1, n, 1, n, rt[0], rt[l - 1]);
        long long _b = query(u + 1, n, 1, n, rt[l - 1], rt[r]);
        long long _c = query(u + 1, n, 1, n, rt[r], rt[n]);
        long long _d = query(1, d - 1, 1, n, rt[0], rt[l - 1]);
        long long _e = query(1, d - 1, 1, n, rt[l - 1], rt[r]);
        long long _f = query(1, d - 1, 1, n, rt[r], rt[n]);
        ans -= _a * _b + _a * _c + _b * _c + _d * _e + _d * _f + _e * _f + _b * (_b - 1) / 2 + _e * (_e - 1) / 2;
        printf("%lld\n", ans);
    }
    return 0;
}