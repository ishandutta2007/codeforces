#include <bits/stdc++.h>
using namespace std;

const int maxn = 131072, mod = 1e9 + 7, tinv = 500000004;
int s[maxn], f[maxn];
int ar[maxn], xr[maxn], pr[maxn];
int vans[maxn];

void xorfwt(int v[], int l, int r) {
    if (r - l == 1) return;
    int m = l + r >> 1;
    xorfwt(v, l, m), xorfwt(v, m, r);
    for (int i = l, j = m; i < m; ++i, ++j) {
        int x = (v[i] + v[j]) % mod;
        v[j] = (v[i] - v[j] + mod) % mod, v[i] = x;
    }
}

void xorifwt(int v[], int l, int r) {
    if (r - l == 1) return;
    int m = l + r >> 1;
    for (int i = l, j = m; i < m; ++i, ++j) {
        int x = (v[i] + v[j]) % mod * 1ll * tinv % mod;
        v[j] = (v[i] - v[j] + mod) % mod * 1ll * tinv % mod, v[i] = x;
    }
    xorifwt(v, l, m), xorifwt(v, m, r);
}

void andfwt(int v[], int l, int r) {
    if (r - l == 1) return;
    int m = l + r >> 1;
    andfwt(v, l, m), andfwt(v, m, r);
    for (int i = l, j = m; i < m; ++i, ++j) (v[i] += v[j]) %= mod;
}

void andifwt(int v[], int l, int r) {
    if (r - l == 1) return;
    int m = l + r >> 1;
    andifwt(v, l, m), andifwt(v, m, r);
    for (int i = l, j = m; i < m; ++i, ++j) v[i] = (v[i] - v[j] + mod) % mod;
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int a; scanf("%d", &a);
        ++s[a];
    }
    f[0] = 0, f[1] = 1;
    for (int i = 2; i < maxn; ++i) f[i] = (f[i - 1] + f[i - 2]) % mod;
    for (int i = 0; i < maxn; ++i) xr[i] = pr[i] = s[i];
    for (int i = 0; i < maxn; ++i) {
        for (int p = i, q = 1; q; q = p, p = (p - 1) & i) ar[i] = (ar[i] + s[i ^ p] * 1ll * s[p] % mod) % mod;
    }
    xorfwt(xr, 0, maxn);
    for (int i = 0; i < maxn; ++i) xr[i] = xr[i] * 1ll * xr[i] % mod;
    xorifwt(xr, 0, maxn);
    for (int i = 0; i < maxn; ++i) {
        xr[i] = xr[i] * 1ll * f[i] % mod;
        pr[i] = pr[i] * 1ll * f[i] % mod;
        ar[i] = ar[i] * 1ll * f[i] % mod;
    }
    andfwt(ar, 0, maxn), andfwt(xr, 0, maxn), andfwt(pr, 0, maxn);
    for (int i = 0; i < maxn; ++i) vans[i] = (ar[i] * 1ll * xr[i] % mod) * 1ll * pr[i] % mod;
    andifwt(vans, 0, maxn);
    int ans = 0;
    for (int i = 1; i < maxn; i <<= 1) ans = (ans + vans[i]) % mod;
    printf("%d\n", ans);
    return 0;
}