#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

constexpr int mod = 31607;

inline int inverse(int a) {
    a %= mod;
    if (a < 0) {
        a += mod;
    }
    int b = mod, u = 0, v = 1;
    while (a) {
        int t = b / a;
        b -= t * a;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    assert(b == 1);
    if (u < 0) {
        u += mod;
    }
    return u;
}

int a[21][21];
int b[21];
int c[2];
int d[21];
int new_c[2];
int inv[31607];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            a[i][j] *= 3973;
            a[i][j] %= mod;
        }
    }
    for (int i = 0; i < n; i++) {
        d[i] = 1;
        for (int j = 0; j < n; j++) {
            d[i] *= a[i][j];
            d[i] %= mod;
        }
    }
    int ans = 0;
    for (int i = 1; i < mod; i++) {
        inv[i] = inverse(i);
    }
    for (int mask = 0; mask < (1 << (n + 2)); mask++) {
        c[0] = 1;
        c[1] = 0;
        for (int i = 0; i < n; i++) {
            b[i] = 1;
        }
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                c[0] *= d[i];
                c[0] %= mod;
            } else {
                for (int j = 0; j < n; j++) {
                    if (i == j && (mask & (1 << (n + 1)))) {
                        c[0] *= a[i][j];
                        c[0] %= mod;
                    } else if (i == n - 1 - j && (mask & (1 << n))) {
                        c[0] *= a[i][j];
                        c[0] %= mod;
                    } else {
                        b[j] *= a[i][j];
                        b[j] %= mod;
                    }
                }
            }
        }
        if (__builtin_parity(mask)) {
            swap(c[0], c[1]);
        }
        for (int j = 0; j < n; j++) {
            new_c[0] = c[1] * b[j] % mod;
            new_c[1] = c[0] * b[j] % mod;
            c[0] += new_c[0];
            c[1] += new_c[1];
            if (c[0] >= mod) {
                c[0] -= mod;
            }
            if (c[1] >= mod) {
                c[1] -= mod;
            }
        }
        ans += c[1] - c[0] + mod;
        while (ans >= mod) {
            ans -= mod;
        }
    }
    ans = (ans + 1) % mod;
    cout << ans << '\n';
    return 0;
}