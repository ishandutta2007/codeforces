#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;
long long S[100005];
int F[100005], R[100005];

int pw(int x, int p) {
    int r = 1;
    while (p) {
        if (p % 2) r = 1ll * r * x % mod;
        x = 1ll * x * x % mod;
        p /= 2;
    }
    return r;
}

int nCr(int n, int r) {
    return 1ll * F[n] * R[r] % mod * R[n - r] % mod;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    F[0] = R[0] = 1;
    for (int i = 1; i <= 100000; ++i) F[i] = 1ll * F[i - 1] * i % mod, R[i] = pw(F[i], mod - 2);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> S[i];
            S[i] += S[i - 1];
        }
        if (S[n] == 0) {
            printf("%d\n", pw(2, n - 1));
            continue;
        }
        map<long long, int> cnt;
        for (int i = 1; i < n; ++i) {
            ++cnt[S[i]];
        }
        int ans = 1;
        if (S[n] % 2 == 0) ans = pw(2, cnt[S[n] / 2]);
        for (int i = 1; S[i] * 2 < S[n]; i += cnt[S[i]]) {
            int a = cnt[S[i]], b = cnt[S[n] - S[i]];
            int m = 0;
            for (int j = 0; j <= a && j <= b; ++j) {
                m = (m + 1ll * nCr(a, j) * nCr(b, j)) % mod;
            }
            ans = 1ll * ans * m % mod;
        }
        printf("%d\n", ans);
    }
    return 0;
}