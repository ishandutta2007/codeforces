#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
// typedef __int128 LLL;
const LL P = 1e9 + 7;
const LL INF = 2e18;
const int N = 2e5 + 5;
mt19937 rng(time(0));

int T, n, k;
LL fac[N], ifac[N];

LL pw(LL x, LL n)
{
    LL res = 1;
    for (; n; x = x * x % P, n >>= 1)
        if (n & 1)
            res = res * x % P;
    return res;
}

LL C(int a, int b) { return fac[a] * ifac[b] % P * ifac[a - b] % P; }

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    fac[0] = 1;
    rep(i, 1, n) fac[i] = fac[i - 1] * i % P;
    ifac[n] = pw(fac[n], P - 2);
    rrep(i, n - 1, 0) ifac[i] = ifac[i + 1] * (i + 1) % P;
    LL ans = 0;
    rep(i, 0, min(n,k)) ans = (ans + C(n, i)) % P;
    cout << ans;
    return 0;
}