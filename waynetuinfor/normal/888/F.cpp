#include <bits/stdc++.h>
using namespace std;

const int maxn = 500 + 10, mod = 1e9 + 7;
int a[maxn][maxn], f[maxn][maxn], g[maxn][maxn];
bool vf[maxn][maxn], vg[maxn][maxn];

inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
inline int mul(int a, int b) { return a * 1ll * b % mod; }

int gof(int, int);

int gog(int l, int r) {
    if (r - l <= 1) {
        if (l == r) return 0;
        return 1;
    }
    if (vg[l][r]) return g[l][r];
    g[l][r] = gof(l + 1, r);
    for (int k = l + 1; k < r; ++k) if (a[l][k]) {
        g[l][r] = add(g[l][r], mul(gog(l, k), gog(k, r)));
    }
    vg[l][r] = true;
    return g[l][r];
}

int gof(int l, int r) {
    if (l == r) return 1;
    if (vf[l][r]) return f[l][r];
    for (int k = l + 1; k <= r; ++k) if (a[l][k]) {
        f[l][r] = add(f[l][r], mul(gog(l, k), gof(k, r)));
    }
    vf[l][r] = true;
    return f[l][r];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) cin >> a[i][j];
    }
    cout << gof(1, n) << endl;
    return 0;
}