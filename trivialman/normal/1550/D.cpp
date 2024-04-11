#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 1e9 + 7;
const int INF = (1 << 30) - 1;
const int N = 2e5 + 5;
mt19937 rng(time(0));

int T, n, l, r;
LL ans, fac[N], ifac[N];

LL pw(LL x, LL n) {
    LL res = 1;
    for (; n; x = x * x % P, n >>= 1)
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
        cin >> n >> l >> r;
        int diff = min(1 - l, r - n);
        if (n % 2 == 0) {
            ans = 1ll * diff * C(n, n / 2) % P;
            rep(i, 1, n / 2) {
                diff++;
                int l1 = l + diff, r1 = r - diff;
                int remain_l = n / 2 - max(l1 - 1, 0), remain_r = n / 2 - max(n - r1, 0);
                if (remain_l < 0 || remain_r < 0)
                    break;
                ans = (ans + C(remain_l + remain_r, remain_r)) % P;
            }
        } else {
            ans = 2ll * diff * C(n, n / 2) % P;
            rep(i, 1, n / 2 + 1) {
                diff++;
                int l1 = l + diff, r1 = r - diff;
                int remain_l = (n + 1) / 2 - max(l1 - 1, 0), remain_r = n / 2 - max(n - r1, 0);
                LL tmp = 0;
                if (remain_l >= 0 && remain_r >= 0)
                    tmp = (tmp + C(remain_l + remain_r, remain_r)) % P;
                remain_l--, remain_r++;
                if (remain_l >= 0 && remain_r >= 0)
                    tmp = (tmp + C(remain_l + remain_r, remain_r)) % P;
                ans = (ans + tmp) % P;
            }
        }
        cout << ans << endl;
    }
    return 0;
}