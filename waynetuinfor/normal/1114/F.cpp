#include <bits/stdc++.h>
using namespace std;

const int maxn = 4e5 + 5;
const int mod = 1e9 + 7;
long long mask[maxn * 4], mtag[maxn * 4];
int prod[maxn * 4], dv[301], a[maxn], tag[maxn * 4], inv[301], rev[301];
vector<int> pr;

void sieve() {
    for (int i = 2; i <= 300; ++i) {
        if (!dv[i]) pr.push_back(i), dv[i] = i;
        for (int j = 0; i * pr[j] <= 300; ++j) {
            dv[i * pr[j]] = pr[j];
            if (i % pr[j] == 0)
                break;
        }
    }
    for (int i = 0; i < (int)pr.size(); ++i)
        rev[pr[i]] = i;
}

void build(int l, int r, int o = 0) {
    tag[o] = 1;
    if (r - l == 1) {
        prod[o] = a[l];
        while (a[l] > 1) {
            int d = dv[a[l]];
            mask[o] |= (1ll << rev[d]);
            while (a[l] % d == 0) a[l] /= d;
        }
        return;
    }
    build(l, (l + r) >> 1, o * 2 + 1);
    build((l + r) >> 1, r, o * 2 + 2);
    prod[o] = prod[o * 2 + 1] * 1ll * prod[o * 2 + 2] % mod;
    mask[o] = (mask[o * 2 + 1] | mask[o * 2 + 2]);
}

pair<int, long long> operator+(const pair<int, long long> &a, const pair<int, long long> &b) {
    return make_pair(a.first * 1ll * b.first % mod,
                     a.second | b.second);
}

int fpow(int a, int n) {
    int res = 1;
    while (n > 0) {
        if (n & 1) res = res * 1ll * a % mod;
        a = a * 1ll * a % mod;
        n >>= 1;
    }
    return res;
}

void push(int o, int l, int r) {
    if (r - l == 1) return;
    int m = (l + r) >> 1;
    prod[o * 2 + 1] = prod[o * 2 + 1] * 1ll * fpow(tag[o], m - l) % mod;
    prod[o * 2 + 2] = prod[o * 2 + 2] * 1ll * fpow(tag[o], r - m) % mod;
    tag[o * 2 + 1] = tag[o * 2 + 1] * 1ll * tag[o] % mod;
    tag[o * 2 + 2] = tag[o * 2 + 2] * 1ll * tag[o] % mod;
    mask[o * 2 + 1] |= mtag[o];
    mask[o * 2 + 2] |= mtag[o];
    mtag[o * 2 + 1] |= mtag[o];
    mtag[o * 2 + 2] |= mtag[o];
    tag[o] = 1;
    mtag[o] = 0;
}

pair<int, long long> query(int l, int r, int ql, int qr, int o = 0) {
    if (l >= qr || ql >= r) return make_pair(1, 0);
    if (l >= ql && r <= qr) return make_pair(prod[o], mask[o]);
    push(o, l, r);
    return query(l, (l + r) >> 1, ql, qr, o * 2 + 1) +
           query((l + r) >> 1, r, ql, qr, o * 2 + 2);
}

void modify(int l, int r, int ql, int qr, int x, long long v, int o = 0) {
    if (l >= qr || ql >= r) return;
    if (l >= ql && r <= qr) {
        prod[o] = prod[o] * 1ll * fpow(x, r - l) % mod;
        tag[o] = tag[o] * 1ll * x % mod;
        mask[o] |= v;
        mtag[o] |= v;
        return;
    }
    push(o, l, r);
    modify(l, (l + r) >> 1, ql, qr, x, v, o * 2 + 1);
    modify((l + r) >> 1, r, ql, qr, x, v, o * 2 + 2);
    prod[o] = prod[o * 2 + 1] * 1ll * prod[o * 2 + 2] % mod;
    mask[o] = (mask[o * 2 + 1] | mask[o * 2 + 2]);
}

int main() {
    int n, q; scanf("%d%d", &n, &q);
    sieve();
    for (int i = 1; i <= 300; ++i) inv[i] = fpow(i, mod - 2);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    build(0, n);
    while (q--) {
        static char s[20];
        scanf("%s", s);
        if (s[0] == 'M') {
            int l, r, x; scanf("%d%d%d", &l, &r, &x);
            int y = x;
            long long z = 0;
            while (y > 1) {
                int d = dv[y];
                z |= (1ll << rev[d]);
                while (y % d == 0) y /= d;
            }
            modify(0, n, l - 1, r, x, z);
        } else {
            int l, r; scanf("%d%d", &l, &r);
            pair<int, long long> p = query(0, n, l - 1, r);
            int ans = p.first;
            for (int i = 0; i < (int)pr.size(); ++i) {
                if (p.second & (1ll << i)) {
                    ans = ans * 1ll * (mod + 1 - inv[pr[i]]) % mod;
                }
            }
            printf("%d\n", ans);
        }
    }
}