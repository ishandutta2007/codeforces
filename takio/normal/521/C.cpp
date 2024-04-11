#include <bits/stdc++.h>
#define LL long long
using namespace std;

const LL N = 100100, mod = 1e9 + 7;

char s[N];
LL f[N], inv[N], sum[N];

LL mypow (LL x, LL k) {
    LL res = 1;
    while (k) {
        if (k & 1) (res *= x) %= mod;
        (x *= x) %= mod;
        k >>= 1;
    }
    return res;
}

LL cal (LL n, LL m) {
    LL c = 1;
    for (LL i = n - m + 1; i <= n; i++) {
        (c *= i) %= mod;
    }
    for (LL i = m; i >= 1; i--) {
        (c *= inv[i]) %= mod;
    }
    return c;
}

int main () {
//    freopen ("in.txt", "r", stdin);
    LL n, k;
    LL c = 1, res = 0;
    cin >> n >> k;
    scanf ("%s", s);
    if (k == 0) {
        for (LL i = 0; i < n; i++) res *= 10, res += s[i] - '0', res %= mod;
        cout << res << endl;
        return 0;
    }
    if (n == k + 1) {
        for (LL i = 0; i < n; i++) (res += s[i] - '0') %= mod;
        cout << res << endl;
        return 0;
    }
    f[0] = 1;
    for (LL i = 1; i < N; i++) f[i] = f[i - 1] * 10 % mod;
//    for (LL i = 1; i < 10; i++) cout << f[i] << ' ';
    for (LL i = 0; i < N; i++) inv[i] = mypow (i, mod - 2);
    c = cal (n - 2, k - 1);
    LL all = -1;
    LL ff = n - 2, ee = n - k - 1;
    for (LL i = n - 2, t = 0; i >= k - 1; i--, t++) {
        sum[t] = ((t == 0 ? 0 : sum[t - 1]) + c * f[t]) % mod;
        all++;
//        cout << ff << ' ' << ee << ' ' << k - 1 << ' ' << c << endl;
        (c *= inv[ff]) %= mod;
        (c *= ee) %= mod;
        ff--, ee--;
    }
//    for (LL i = 0; i < 10; i++) cout << sum[i] << endl;
    c = 1;
    ff = 1, ee = k + 1;
    for (LL i = 0; i < n; i++) {
        if (i <= k) {
            (res += sum[all] * (s[i] - '0')) %= mod;
//            cout << sum[all] * (s[i] - '0') << endl;
        } else {
            (res += sum[--all] * (s[i] - '0')) %= mod;
            (res += f[n - 1 - i] * c % mod * (s[i] - '0') % mod) %= mod;
            (c *= inv[ff]) %= mod;
            (c *= ee) %= mod;
            ff++, ee++;
        }
    }
    cout << res << endl;
}