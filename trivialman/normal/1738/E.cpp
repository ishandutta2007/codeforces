#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 998244353;
const int INF = 1e9 + 1;
const int N = 1e5 + 5;
mt19937 rng(time(0));

int T, n;
int a[N], x[N], y[N];
LL fac[N], ifac[N];

LL pw(int x, LL n) {
    int res = 1;
    for (; n; n >>= 1, x = 1ll * x * x % P)
        if (n & 1)
            res = 1ll * res * x % P;
    return res;
}

inline LL C(int a, int b) { return fac[a] * ifac[b] % P * ifac[a - b] % P; }

LL calc(int l, int r) {
    int x = l >= 1, y = r <= n;

    for (l++; l <= n && a[l] == 0; l++)
        x++;
    for (r--; r >= 1 && a[r] == 0; r--)
        y++;

    LL res = 1;
    rep(i, 1, min(x, y)) res = (res + C(x, i) * C(y, i)) % P;
    // cerr << l << " " << r << " " << x << " " << y << " " << res << endl;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    fac[0] = 1;
    rep(i, 1, N - 1) fac[i] = fac[i - 1] * i % P;
    ifac[N - 1] = pw(fac[N - 1], P - 2);
    rrep(i, N - 2, 0) ifac[i] = ifac[i + 1] * (i + 1) % P;

    cin >> T;
    while (T--) {
        cin >> n;
        rep(i, 1, n) cin >> a[i];
        int l = 1, r = n, m = 1;
        x[1] = 0, y[1] = n + 1;
        LL sl = 0, sr = 0;
        while (l - 1 < r + 1) {
            while (l <= r && a[l] == 0)
                l++;
            while (l <= r && a[r] == 0)
                r--;
            sl < sr ? sl += a[l++] : sr += a[r--];
            if (l - 1 < r + 1 && sl == sr) {
                ++m, x[m] = l - 1, y[m] = r + 1;
                while (a[x[m]] == 0)
                    x[m]--;
                while (a[y[m]] == 0)
                    y[m]++;
            }
        }
        // rep(i, 1, m) cerr << x[i] << " " << y[i] << endl;

        LL ans = 1;
        rep(i, 1, m - 1) ans = ans * calc(x[i], y[i]) % P;
        bool flag = false;
        rep(i, x[m] + 1, y[m] - 1) if (a[i] > 0) flag = true;
        ans = ans *
              (flag ? calc(x[m], y[m]) : pw(2, y[m] - x[m] - (m == 1) * 2)) % P;
        cout << ans << "\n";

        // cerr << endl;
    }
    return 0;
}