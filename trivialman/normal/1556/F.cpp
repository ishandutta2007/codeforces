#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 1e9 + 7;
const int N = 15;
const int INF = 1e9;
const double pi = acos(-1);
mt19937 rng(time(0));

int n;
int a[N], p[N][N], f[1 << N], _2to3[1 << N], g[4782970];

int pw(int x, int n) {
    int res = 1;
    for (; n; n >>= 1, x = 1ll * x * x % P)
        if (n & 1)
            res = 1ll * res * x % P;
    return res;
}

int main() {
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) rep(j, i + 1, n) p[i][j] = 1ll * a[i] * pw(a[i] + a[j], P - 2) % P, p[j][i] = (P + 1 - p[i][j]) % P;

    rep(mask, 0, (1 << n) - 1) _2to3[mask] = _2to3[mask >> 1] * 3 + (mask & 1);

    rep(mask, 0, (1 << n) - 1) {
        vector<int> win, lose; //lose:2, chosen:1, unchosen:0
        rep(i, 1, n)((mask >> i - 1 & 1) ? win : lose).PB(i);

        int num = win.size(), base = _2to3[(1 << n) - 1 - mask] * 2;
        vector<int> mul(n + 1), tmp(1 << num, 0);
        for (auto x : win) {
            mul[x] = 1;
            for (auto y : lose)
                mul[x] = 1ll * mul[x] * p[x][y] % P;
        }

        g[base] = 1;
        rep(mask1, 1, (1 << num) - 1) {
            int x = mask1 & -mask1, y = __builtin_ctz(mask1), i = tmp[mask1 - x] + (1 << win[y] - 1);
            tmp[mask1] = i;
            g[base + _2to3[i]] = 1ll * g[base + _2to3[tmp[mask1 - x]]] * mul[win[y]] % P;
        }
    }

    rep(mask, 1, (1 << n) - 1) {
        vector<int> win, lose;
        rep(i, 1, n)((mask >> i - 1 & 1) ? win : lose).PB(i);
        int res = 1, num = win.size(), base = _2to3[mask] * 2;
        vector<int> tmp(1 << num, 0);

        rep(mask1, 1, (1 << num) - 2) {
            int x = mask1 & -mask1, y = __builtin_ctz(mask1), i = tmp[mask1 - x] + (1 << win[y] - 1);
            tmp[mask1] = i;
            res = (res - 1ll * f[i] * g[base - _2to3[i]] % P) % P;
        }

        f[mask] = (res + P) % P;
    }

    int ans = 0, base = _2to3[(1 << n) - 1] * 2;
    rep(mask, 1, (1 << n) - 1) ans = (ans + 1ll * __builtin_popcount(mask) * f[mask] % P * g[base - _2to3[mask]] % P) % P;
    cout << ans << endl;
    return 0;
}