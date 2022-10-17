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

const int MAXN = 300300, base1 = 998244853, mod1 = 1e9 + 9, base2 = 10007, mod2 = 1004535809;
int qpow (int x, int y, int mod) {
    int ret = 1;
    while (y) {
        if (y & 1) ret = 1ll * ret * x % mod;
        x = 1ll * x * x % mod; y >>= 1;
    }
    return ret;
}
int inv (int x, int mod) { return qpow(x, mod - 2, mod); }

int n, a[MAXN], p1[MAXN], p2[MAXN];

#define pii pair<int, int>
#define fr first
#define se second
struct node {
    pii pre, suf;
    node operator + (const node &tmp) const {
        return node{
            pii((pre.fr + tmp.pre.fr) % mod1, (pre.se + tmp.pre.se) % mod2),
            pii((suf.fr + tmp.suf.fr) % mod1, (suf.se + tmp.suf.se) % mod2)};
    }
} t[MAXN << 2];
bool operator == (const pii &x, const pii &y) {
    return (x.fr + mod1) % mod1 == (y.fr + mod1) % mod1 && (x.se + mod2) % mod2 == (y.se + mod2) % mod2;
}

void build (int l, int r, int x) {
    if (l == r) {
        t[x] = node{pii(-p1[l], -p2[l]), pii(-p1[n - l + 1], -p2[n - l + 1])};
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, x << 1); build(mid + 1, r, x << 1 | 1);
    t[x] = t[x << 1] + t[x << 1 | 1];
}
void modify (int pos, int l, int r, int x) {
    if (l == r) {
        t[x] = node{pii(p1[l], p2[l]), pii(p1[n - l + 1], p2[n - l + 1])};
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) modify(pos, l, mid, x << 1);
    else modify(pos, mid + 1, r, x << 1 | 1);
    t[x] = t[x << 1] + t[x << 1 | 1];
}
node query (int l, int r, int L, int R, int x) {
    if (l <= L && R <= r) return t[x];
    int mid = (L + R) >> 1;
    if (l <= mid && mid < r) return query(l, r, L, mid, x << 1) + query(l, r, mid + 1, R, x << 1 | 1);
    if (l <= mid) return query(l, r, L, mid, x << 1);
    else return query(l, r, mid + 1, R, x << 1 | 1);
}

int main () {
    n = read(); int i, j;
    for (i = 1; i <= n; i++) a[i] = read();
    p1[0] = p2[0] = 1; for (i = 1; i <= n; i++) p1[i] = 1ll * p1[i - 1] * base1 % mod1, p2[i] = 1ll * p2[i - 1] * base2 % mod2;
    build(1, n, 1);
    for (i = 1; i <= n; i++) {
        int len = min(n - a[i] + 1, a[i]);
        pii pre = query(a[i] - len + 1, a[i], 1, n, 1).pre, suf = query(a[i], a[i] + len - 1, 1, n, 1).suf;
        pre = pii(1ll * pre.fr * inv(p1[a[i] - len + 1], mod1) % mod1, 1ll * pre.se * inv(p2[a[i] - len + 1], mod2) % mod2);
        int tmp = n - (a[i] + len - 1) + 1;
        suf = pii(1ll * suf.fr * inv(p1[tmp], mod1) % mod1, 1ll * suf.se * inv(p2[tmp], mod2) % mod2);
        if (!(pre == suf)) { puts("YES"); return 0; }
        modify(a[i], 1, n, 1);
    }
    puts("NO");
    return 0;
}