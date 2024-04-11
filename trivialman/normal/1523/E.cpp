#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 1e9 + 7;
const LL INF = 1e9;
const int N = 1e5 + 5;
mt19937 rng(time(0));

int T, n, k;
LL fac[N], ifac[N];
LL p[N]; //survive possibility

LL pw(LL x, LL n) {
    LL res = 1;
    for (; n; n >>= 1, x = x * x % P)
        if (n & 1)
            res = res * x % P;
    return res;
}

inline LL C(int a, int b) { return fac[a] * ifac[b] % P * ifac[a - b] % P; }

int main() {
    fac[0] = 1;
    rep(i, 1, N - 1) fac[i] = fac[i - 1] * i % P;
    ifac[N - 1] = pw(fac[N - 1], P - 2);
    rrep(i, N - 2, 0) ifac[i] = ifac[i + 1] * (i + 1) % P;

    cin >> T;
    while (T--) {
        cin >> n >> k;
        int up = (n - 1) / k + 1;
        rep(i, 1, up) p[i] = C(n - (k - 1) * (i - 1), i) * pw(C(n, i), P - 2) % P;
        p[up + 1] = 0;
        rep(i, 1, up) cerr << i << " " << p[i] << endl;
        LL ans = 1;
        rep(i, 1, up) ans = (ans + (p[i] - p[i + 1] + P) % P * i % P) % P;
        cout << ans << endl;
    }
    return 0;
}