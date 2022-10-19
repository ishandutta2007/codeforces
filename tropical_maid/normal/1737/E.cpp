#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int S[1000005], P[1000005], R[1000005];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    P[0] = 1;
    for (int i = 1; i <= 1000000; ++i) P[i] = P[i - 1] * 2 % mod;
    R[0] = 1;
    R[1] = (mod + 1) / 2;
    for (int i = 2; i <= 1000000; ++i) R[i] = 1ll * R[i - 1] * R[1] % mod;
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        S[n + 1] = 0;
        S[n] = 1;
        for (int i = n - 1; i >= 1; --i) {
            S[i] = (S[i + 1] - S[min(n + 1, i * 2)] + mod) % mod;
            S[i] = (S[i] + S[i + 1]) % mod;
        }
        for (int i = 1; i <= n; ++i) {
            printf("%lld\n", 2ll * P[i / 2] * (S[i] - S[i + 1] + mod) % mod * R[n] % mod);
        }
    }
    return 0;
}