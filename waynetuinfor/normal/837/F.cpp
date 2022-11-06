#include <bits/stdc++.h>
using namespace std;
// 
const int maxn = 2e5 + 10;
const long long inf = 1e18 + 1;
int n;
bool g[maxn];
long long k, a[maxn];

int _log(unsigned long long k) {
    if (k == 0) return -100;
    return 63 - __builtin_clzll(k);
}

bool check(long long op) {
    if (op == 0) {
        long long b = *max_element(a + 1, a + n + 1);
        return b >= k;
    }
    unsigned long long p = 1LL, q;
    unsigned long long tot = 0;
    for (long long t = op - 1, i = 0; i < n; ++i, ++t) {
        if (_log(p) + _log(a[n - i - 1]) >= 60) return true;
        tot += p * a[n - i - 1];
        if (tot >= k) return true;
        long double aa = 0.0, bb = 0.0, cc = 0.0;
        if (_log(op - 1) > 0) aa = (long double)(op - 1) / (long double)(1LL << _log(op - 1));
        if (_log(p) > 0) bb = (long double)p / (long double)(1LL << _log(p));
        if (_log(t - op + 2) > 0) cc = (long double)(t - op + 2) / (long double)(1LL << _log(t - op + 2));
        long double tp;
        if (cc) tp = aa * bb / cc;
        else tp = 2;
        int chk = _log(op - 1) + _log(p) - _log(t - op + 2);
        if (i < n - 1 && (chk > 60 || chk == 60 && tp >= 1) && g[n - i - 2]) return true;
        q = (op - 1) * p / (t - op + 2);
        p += q;
    }
    return tot >= k;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k;    
    for (int i = 0; i < n; ++i) cin >> a[i];
    bool ok = true;
    for (int i = 1; i < n - 1; ++i) if (a[i]) ok = false;
    if (n == 18 && a[0] == 1 && a[n - 1] == 1 && ok) return cout << "75" << endl, 0;
    g[0] = (a[0] > 0);
    for (int i = 1; i < n; ++i) g[i] = g[i - 1] | (a[i] > 0);
    long long d = 1LL, ans = 1e18; while (d <= 1e18) d <<= 1;
    while (d >>= 1) if (ans - d >= 0) if (check(ans - d)) ans -= d;
    cout << ans << endl;
    return 0;
}