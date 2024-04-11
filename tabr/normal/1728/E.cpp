#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

template <typename T>
T extgcd(T a, T b, T &x, T &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    T p = b / a;
    T g = extgcd(b - p * a, a, y, x);
    x -= p * y;
    return g;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    long long s = 0;
    vector<long long> r;
    for (int i = 0; i < n; i++) {
        long long a, b;
        cin >> a >> b;
        s += b;
        r.emplace_back(a - b);
    }
    sort(r.rbegin(), r.rend());
    vector<long long> pref(n + 1);
    pref[0] = s;
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + r[i];
    }
    int best = (int) (max_element(pref.begin(), pref.end()) - pref.begin());
    int m;
    cin >> m;
    debug(pref);
    for (int i = 0; i < m; i++) {
        long long x, y;
        cin >> x >> y;
        long long p, q;
        auto g = extgcd(x, y, p, q);
        p *= n / g;
        q *= n / g;
        if (p < 0) {
            long long t = (abs(p) + y / g - 1) / (y / g);
            p += y / g * t;
            q -= x / g * t;
        }
        if (q < 0) {
            long long t = (abs(q) + x / g - 1) / (x / g);
            q += x / g * t;
            p -= y / g * t;
        }
        debug(x, y, p, q, g);
        if (p < 0) {
            cout << -1 << '\n';
            continue;
        }
        if (n % g) {
            cout << -1 << '\n';
            continue;
        }
        long long ans = 0;
        if (p * x < best) {
            long long t = min(q / (x / g), (best / x - p) / (y / g));
            p += y / g * t;
            q -= x / g * t;
            debug(p * x);
            ans = max(ans, pref[p * x]);
            p += y / g;
            q -= x / g;
            debug(p * x);
            if (0 <= p * x && p * x <= n) {
                ans = max(ans, pref[p * x]);
            }
        } else {
            long long t = min((p - (best + x - 1) / x) / (y / g), (n / y - q) / (x / g));
            p -= y / g * t;
            q += x / g * t;
            debug(p * x);
            ans = max(ans, pref[p * x]);
            p -= y / g;
            q += x / g;
            debug(p * x);
            if (0 <= p * x && p * x <= n) {
                ans = max(ans, pref[p * x]);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}