#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

long long extgcd(long long a, long long b, long long &x, long long &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    long long p = b / a;
    long long g = extgcd(b - p * a, a, y, x);
    x -= p * y;
    return g;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    long long k;
    cin >> k;
    vector<int> a(n), b(m);
    int MAX = 2 * max(n, m) + 1;
    vector<int> c(MAX, -1), d(MAX, -1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        c[a[i]] = i;
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        d[b[i]] = i;
    }
    vector<int> e(MAX);
    vector<pair<long long, long long>> p;
    long long xx, yy;
    long long g = extgcd(n, m, xx, yy);
    long long t = 1LL * m * n / g;
    for (int i = 0; i < MAX; i++) {
        if (c[i] != -1 && d[i] != -1) {
            if (abs(c[i] - d[i]) % g != 0) {
                continue;
            }
            long long x = xx;
            x *= (d[i] - c[i]) / g;
            long long q = n * x + c[i];
            q %= t;
            q += t;
            q %= t;
            p.emplace_back(q, t);
        }
    }
    long long hi = (long long)4e18;
    long long lo = k - 1;
    while (hi - lo > 1) {
        long long mid = (hi + lo) >> 1;
        long long cnt = mid;
        for (auto z : p) {
            if (mid - 1 < z.first) {
                continue;
            }
            cnt -= max(0LL, (mid - 1 - z.first) / z.second + 1);
        }
        if (cnt >= k) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    cout << hi << '\n';
    return 0;
}