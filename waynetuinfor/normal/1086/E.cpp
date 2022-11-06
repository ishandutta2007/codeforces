#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000 + 5;
const int mod = 998244353;
int a[maxn][maxn], fw[2][maxn], v[maxn];
int cnk[maxn][maxn], f[maxn][maxn], fc[maxn], pw[maxn];

void add(int *fw, int p, int v) {
    for (int i = p + 1; i < maxn; i += i & -i)
        fw[i] += v;
}

int query(int *fw, int p) {
    int res = 0;
    for (int i = p + 1; i; i -= i & -i)
        res += fw[i];
    return res;
}

int func(int n, int m) {
    if (~f[n][m]) return f[n][m];
    f[n][m] = 0;
    int c = 1;
    for (int i = 0; i <= m; ++i) {
        f[n][m] += c * 1ll * cnk[m][i] % mod * fc[n - i] % mod;
        f[n][m] %= mod;
        c = mod - c;
    }
    return f[n][m];
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &a[i][j]);
            --a[i][j];
        }
    }
    cnk[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        cnk[i][0] = cnk[i - 1][0];
        for (int j = 1; j <= n; ++j) {
            cnk[i][j] = cnk[i - 1][j] + cnk[i - 1][j - 1];
            if (cnk[i][j] >= mod) cnk[i][j] -= mod;
        }
    }
    fc[0] = 1;
    for (int i = 1; i <= n; ++i) fc[i] = fc[i - 1] * 1ll * i % mod;
    memset(f, -1, sizeof(f));
    pw[0] = 1;
    for (int i = 1; i < maxn; ++i) pw[i] = pw[i - 1] * 1ll * func(n, n) % mod;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        memset(v, 0, sizeof(v));
        memset(fw, 0, sizeof(fw));
        if (i) for (int j = 0; j < n; ++j) add(fw[0], j, 1);
        else for (int j = 0; j < n; ++j) v[j] = 1;
        for (int j = 0; j < n; ++j) add(fw[1], j, 1);
        int way = 0;
        for (int j = 0; j < n; ++j) {
            if (i && !v[a[i - 1][j]]) {
                add(fw[0], a[i - 1][j], -1);
                v[a[i - 1][j]] = 1;
            }
            int x = query(fw[1], a[i][j] - 1);
            int y = query(fw[0], a[i][j] - 1);
            if (i && a[i - 1][j] < a[i][j] && query(fw[1], a[i - 1][j]) > query(fw[1], a[i - 1][j] - 1)) --x;
            if (i && a[i - 1][j] < a[i][j] && query(fw[0], a[i - 1][j]) > query(fw[0], a[i - 1][j] - 1)) --y;
            way += y * 1ll * func(n - 1 - j, query(fw[0], n) - 1) % mod;
            way %= mod;
            way += (x - y) * 1ll * func(n - 1 - j, query(fw[0], n)) % mod;
            way %= mod;
            // for (int k = 0; k < a[i][j]; ++k) {
                // if (query(fw[1], k) == query(fw[1], k - 1)) continue;
                // if (i && a[i - 1][j] == k) continue;
                // printf("try k = %d\n", k);
                // if (!v[k]) {
                    // add(fw[0], k, -1);
                    // (way += func(n - 1 - j, query(fw[0], n))) %= mod;
                    // add(fw[0], k, 1);
                // } else {
                    // (way += func(n - 1 - j, query(fw[0], n))) %= mod;
                // }
            // } 
            if (!v[a[i][j]]) {
                add(fw[0], a[i][j], -1);
                v[a[i][j]] = 1;
            }
            add(fw[1], a[i][j], -1);
        }
        // printf("way = %d\n", way);
        ans += way * 1ll * pw[n - i - 1] % mod;
        ans %= mod;
    }
    printf("%d\n", ans);
    return 0;
}