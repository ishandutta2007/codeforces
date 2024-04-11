#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<long long, long long>> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
    }
    sort(p.begin(), p.end(), [&](pair<long long, long long> i, pair<long long, long long> j) {
        if (i.first == j.first) {
            return i.second > j.second;
        }
        return i.first < j.first;
    });
    vector<long long> a(n), c(n);
    for (int i = 0; i < n; i++) {
        tie(a[i], c[i]) = p[i];
    }
    long long ans = accumulate(c.begin(), c.end(), 0LL);
    long long t = a[n - 1] - a[0] - c[0];
    long long b = a[0];
    long long d = 0;
    long long mn = -a[0] - c[0];
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > b) {
            d = mn + a[i];
            b = a[i];
        }
        mn = min(mn, d - a[i] - c[i]);
        b = max(b, a[i] + c[i]);
        t = min(t, max(0LL, a[n - 1] - a[i] - c[i]) + d);
        debug(d, t);
    }
    ans += max(t, 0LL);
    debug(a);
    debug(c);
    cout << ans << '\n';
    return 0;
}