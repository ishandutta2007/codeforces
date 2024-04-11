#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;

int pw(int x, int p) {
    int r = 1;
    while (p) {
        if (p % 2) r = 1ll * r * x % mod;
        x = 1ll * x * x % mod;
        p /= 2;
    }
    return r;
}

int F[300005];
int R[300005];
int D[300005];
int E[300005];

int nCr(int n, int r) {
    return 1ll * F[n] * R[r] % mod * R[n - r] % mod;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    F[0] = 1;
    R[0] = 1;
    for (int i = 1; i <= 300000; ++i) {
        F[i] = 1ll * F[i - 1] * i % mod;
        R[i] = pw(F[i], mod - 2);
    }
    D[0] = 1;
    D[1] = 1;
    E[0] = 1;
    for (int i = 2; i <= 300000; ++i) {
        D[i] = (D[i - 1] + (i - 1ll) * D[i - 2]) % mod;
        E[i] = 2ll * (i - 1) * E[i - 2] % mod;
    }
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int ans = 0;
        for (int i = 0; 4 * i <= n; ++i) {
            ans = (ans + 1ll * nCr(n - i - i, i + i) * D[n - 4 * i] % mod * E[i + i]) % mod;
        }
        printf("%d\n", ans);
    }
    return 0;
}