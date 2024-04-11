#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 998244353;
const int INF = 1e9 + 1;
const int N = 3e5 + 5;
mt19937 rng(time(0));

int T, n;
LL fac[N], ifac[N], fac2[N], f[N];

int pw(int x, int n) {
    int res = 1;
    for (; n; n >>= 1, x = 1ll * x * x % P)
        if (n & 1)
            res = 1ll * res * x % P;
    return res;
}

int C(int a, int b) { return 1ll * fac[a] * ifac[b] % P * ifac[a - b] % P; }

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    fac[0] = 1;
    rep(i, 1, N - 1) fac[i] = 1ll * fac[i - 1] * i % P;
    ifac[N - 1] = pw(fac[N - 1], P - 2);
    rrep(i, N - 2, 0) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % P;
    fac2[0] = 1;
    for (int i = 2; i < N; i += 2)
        fac2[i] = 2ll * fac2[i - 2] * (i - 1) % P;

    f[0] = f[1] = 1;
    rep(i, 2, N - 1) f[i] = (1ll * f[i - 2] * (i - 1) % P + f[i - 1]) % P;

    cin >> T;
    while (T--) {
        cin >> n;
        LL ans = 0;
        rep(m, 0, n / 4) {
            (ans += 1ll * C(n - 2 * m, 2 * m) * f[n - 4 * m] % P * fac2[2 * m] %
                    P) %= P;
        }
        cout << ans << "\n";
    }
    return 0;
}