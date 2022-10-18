#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

vector<long long> divisor(long long n) {
    vector<long long> res;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            res.push_back(i);
            if (i * i != n) {
                res.push_back(n / i);
            }
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        ll m, d, w;
        cin >> m >> d >> w;
        ll n = min(m, d);
        ll b = d - 1;
        vector<ll> a = divisor(w);
        ll t = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] * b % w == 0) {
                t = a[i];
                break;
            }
        }
        ll k = n / t;
        ll ans = n * k - t * k * (k + 1) / 2;
        cout << ans << '\n';
    }
    return 0;
}