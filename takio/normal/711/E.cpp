#include <bits/stdc++.h>
#define LL long long
#define pii pair <LL, LL>
#define xx first
#define yy second
using namespace std;

const LL N = 200100, mod = 1e6 + 3;

vector <pii> g[N];

LL pm (LL x, LL y) {
    x %= mod;
    LL r = 1;
    while (y) {
        if (y & 1) (r *= x) %= mod;
        (x *= x) %= mod;
        y >>= 1;
    }
    return r;
}

int main () {
//    freopen ("in.txt", "r", stdin);
//    for (int i = 1; i <= mod; i++) if (mod % i == 0) cout << i << endl;
    LL n, k;
    cin >> n >> k;
//    LL r1 = 1, r2 = 1;
//    for (int i = 0; i < k; i++) r1 *= (pm (2, n) - i);
//    for (int i = 0; i < k; i++) r2 *= pm (2, n);
//    r1 = r2 - r1;
//    LL g = __gcd (r1, r2);
//    cout << (r1 / g) % mod << ' ' << (r2 / g) % mod << endl;
    LL r = 1;
    for (LL i = 1; i <= n; i++) {
        r *= 2;
        if (r >= k) break;
    }
    if (r < k) {
        cout << 1 << ' ' << 1 << endl;
        return 0;
    }
//    cout << r << endl;
    LL inv2 = pm (2, mod - 2);
    LL x = 1;
    for (LL i = 1; i < k; i++) {
        LL t = i, c = 0;
        while (t % 2 == 0) c++, t /= 2;
//        cout << i << ' ' << c << ' ' << t << endl;
//        (x *= pm (2, c)) %= mod;
        (x *= (pm (2, n - c) - t + mod)) %= mod;
        if (x == 0) {
//            cout << i << endl;
            break;
        }
    }
    LL c = 0;
    LL kk = k - 1;
    while (kk) {
        c += kk / 2;
        kk /= 2;
    }
//    cout << c << endl;
//    cout << kk << endl;
//    cout <<  c << ' ' << pm (inv2, c) << endl;
    LL y = pm (pm (2, n), k - 1) * pm (inv2, c) % mod;
    x = (y - x + mod) % mod;
    cout << x << ' ' << y << endl;
}