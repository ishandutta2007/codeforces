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

const int mod = 1e9 + 7, MAXN = 100100, lim = 2e5, magic = 86;
inline int qpow (int x, int y) {
    int ret = 1;
    while (y) {
        if (y & 1) ret = 1ll * ret * x % mod;
        x = 1ll * x * x % mod; y >>= 1;
    }
    return ret;
}
inline int inv (int x) { return qpow(x, mod - 2); }

int pr[MAXN], pt; bool np[MAXN << 1];
void sieve () {
    int i, j;
    for (i = 2; i <= lim; i++) {
        if (!np[i]) pr[++pt] = i;
        for (j = 1; j <= pt; j++) {
            if (i * pr[j] > lim) break;
            np[i * pr[j]] = 1;
            if (i % pr[j] == 0) break;
        }
    }
}

int n, q, a[MAXN], pre[MAXN], lg2[MAXN];

namespace small {
    int tmp[MAXN][magic + 5];
    struct seg {
        int val[magic + 5];
        seg operator + (const seg &tmp) const {
            seg ret;
            for (int i = 1; i <= magic; i++) ret.val[i] = max(val[i], tmp.val[i]);
            return ret;
        }
        int calc () {
            int ret = 1;
            for (int i = 1; i <= magic; i++) ret = 1ll * ret * qpow(pr[i], val[i]) % mod;
            return ret;
        }
    } t[MAXN << 2];
    void build (int l, int r, int x) {
        if (l == r) { for (int i = 1; i <= magic; i++) t[x].val[i] = tmp[l][i]; return; }
        int mid = (l + r) >> 1;
        build(l, mid, x << 1); build(mid + 1, r, x << 1 | 1);
        t[x] = t[x << 1] + t[x << 1 | 1];
    }
    seg query (int l, int r, int L, int R, int x) {
        if (l <= L && R <= r) return t[x];
        int mid = (L + R) >> 1;
        if (l <= mid && mid < r) return query(l, r, L, mid, x << 1) + query(l, r, mid + 1, R, x << 1 | 1);
        if (l <= mid) return query(l, r, L, mid, x << 1);
        else return query(l, r, mid + 1, R, x << 1 | 1);
    }
}

namespace big {
    int tmp[MAXN];
    struct seg {
        int val, ls, rs;
    } t[MAXN * 72]; int top = 0, rt[MAXN];
    void modify (int pos, int k, int l, int r, int o, int x) {
        if (l == r) { t[x].val = 1ll * t[o].val * k % mod; return; }
        int mid = (l + r) >> 1;
        if (pos <= mid) {
            t[x].rs = t[o].rs;
            modify(pos, k, l, mid, t[o].ls, t[x].ls = ++top);
        }
        else {
            t[x].ls = t[o].ls;
            modify(pos, k, mid + 1, r, t[o].rs, t[x].rs = ++top);
        }
        t[x].val = 1ll * t[t[x].ls].val * t[t[x].rs].val % mod;
    }
    int query (int l, int r, int L, int R, int o, int x) {
        if (!x) return 1;
        if (l <= L && R <= r) return 1ll * inv(t[o].val) * t[x].val % mod;
        int mid = (L + R) >> 1, ret = 1;
        if (l <= mid) ret = 1ll * ret * query(l, r, L, mid, t[o].ls, t[x].ls) % mod;
        if (mid < r) ret = 1ll * ret * query(l, r, mid + 1, R, t[o].rs, t[x].rs) % mod;
        return ret;
    }
}
int las[MAXN << 1];

int main () {
    sieve();
    n = read(); int i, j;
    for (i = 1; i <= n; i++) {
        a[i] = read();
        for (j = 1; j <= magic; j++) {
            while (a[i] % pr[j] == 0) a[i] /= pr[j], ++small::tmp[i][j];
        }
    }
    small::build(1, n, 1); big::t[0].val = 1;
    for (i = 1; i <= n; i++) {
        pre[i] = las[a[i]], las[a[i]] = i;
        big::rt[i] = ++big::top; big::modify(pre[i] + 1, a[i], 1, n, big::rt[i - 1], big::rt[i]);
    }
    q = read(); int last = 0;
    while (q--) {
        int l = (read() + last) % n + 1, r = (read() + last) % n + 1;
        if (l > r) swap(l, r);
        int tmp = small::query(l, r, 1, n, 1).calc();
        tmp = 1ll * tmp * big::query(1, l, 1, n, big::rt[l - 1], big::rt[r]) % mod;
        printf("%d\n", last = (tmp + mod) % mod);
    }
    return 0;
}