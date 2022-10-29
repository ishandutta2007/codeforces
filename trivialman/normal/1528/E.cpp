#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define MP make_pair
#define PB push_back
typedef long long LL;
const LL P = 998244353;
const int N = 1e6 + 5;

int n;
LL fac[N], ifac[N], dp[N], sdp[N];

LL pw(LL x, LL n) {
    LL res = 1;
    for (; n; n >>= 1, x = x * x % P)
        if (n & 1)
            res = res * x % P;
    return res;
}

inline LL inv(int x) { return 1 <= x && x < N ? fac[x - 1] * ifac[x] % P : pw(x, P - 2); }
inline LL C(int a, int b) { return fac[a] * ifac[b] % P * ifac[a - b] % P; }
inline LL C3(LL x) { return x * (x - 1) % P * (x - 2) % P * ifac[3] % P; }

int main() {
    fac[0] = 1;
    rep(i, 1, N - 1) fac[i] = fac[i - 1] * i % P;
    ifac[N - 1] = inv(fac[N - 1]);
    rrep(i, N - 2, 0) ifac[i] = ifac[i + 1] * (i + 1) % P;

    cin >> n;
    dp[0] = sdp[0] = 1;
    dp[1] = 2, sdp[1] = 3;
    rep(i, 2, n) {
        dp[i] = (dp[i - 1] + dp[i - 1] * sdp[i - 2] % P + dp[i - 1] * (dp[i - 1] + 1) / 2) % P;
        sdp[i] = (sdp[i - 1] + dp[i]) % P;
    }

    LL ans = C3(sdp[n - 1] + 3) - C3(sdp[n - 2] + 3);
    ans = (ans * 2 - 1) % P;
    rep(i, 1, n - 2) ans = (ans + (dp[i] - dp[i - 1]) * (dp[n - 1 - i] - 1)) % P;
    cout << (ans + P) % P << endl;
}