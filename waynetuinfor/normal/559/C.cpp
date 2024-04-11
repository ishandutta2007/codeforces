#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000 + 5;
const int maxk = 2e5 + 5;
const int mod = 1e9 + 7;
int fc[maxk], iv[maxk];
int r[maxn], c[maxn], dp[maxn];

int fpow(int a, int n) {
    int res = 1;
    while (n > 0) {
        if (n & 1) res = res * 1ll * a % mod;
        a = a * 1ll * a % mod;
        n >>= 1;
    }
    return res;
}

int cnk(int n, int k) {
    if (k < 0 || n < k) return 0;
    return fc[n] * 1ll * iv[k] % mod * iv[n - k] % mod;
}

int main() {
    fc[0] = iv[0] = 1;
    for (int i = 1; i < maxk; ++i) {
        fc[i] = fc[i - 1] * 1ll * i % mod;
        iv[i] = fpow(fc[i], mod - 2);
    }
    int h, w, n; scanf("%d%d%d", &h, &w, &n);
    for (int i = 0; i < n; ++i) scanf("%d%d", &r[i], &c[i]), --r[i], --c[i];
    r[n] = h - 1, c[n] = w - 1, n++;
    vector<int> v(n);
    iota(v.begin(), v.end(), 0);
    sort(v.begin(), v.end(), [&](int i, int j) {
        return r[i] + c[i] < r[j] + c[j];
    });
    for (int i = 0; i < n; ++i) {
        int j = v[i];
        dp[i] = cnk(r[j] + c[j], r[j]);
        for (int k = 0; k < i; ++k) {
            int z = v[k];
            if (r[z] > r[j] || c[z] > c[j]) continue;
            int d = dp[k] * 1ll * cnk(r[j] - r[z] + c[j] - c[z], r[j] - r[z]) % mod;
            dp[i] += mod - d;
            if (dp[i] >= mod) dp[i] -= mod;
        }
    }
    printf("%d\n", dp[n - 1]);
}