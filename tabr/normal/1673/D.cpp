#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

template <typename T>
vector<T> divisor(T n) {
    n = abs(n);
    if (n == 0) {
        return vector<T>();
    }
    vector<T> res;
    for (T i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            res.emplace_back(i);
            if (i * i != n) {
                res.emplace_back(n / i);
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
        long long b, q, y;
        cin >> b >> q >> y;
        long long c, r, z;
        cin >> c >> r >> z;
        if (r % q != 0) {
            cout << 0 << '\n';
            continue;
        }
        auto IsInB = [&](long long v) {
            if ((v - b) % q != 0) {
                return false;
            }
            long long t = (v - b) / q;
            if (0 <= t && t < y) {
                return true;
            } else {
                return false;
            }
        };
        if (!IsInB(c) || !IsInB(c + r * (z - 1))) {
            cout << 0 << '\n';
            continue;
        }
        if (!IsInB(c - r) || !IsInB(c + r * z)) {
            cout << -1 << '\n';
            continue;
        }
        long long ans = 0;
        for (auto t : divisor(r)) {
            if (lcm(t, q) != r) {
                continue;
            }
            ans += (r / t) * (r / t);
        }
        ans %= (int) 1e9 + 7;
        cout << ans << '\n';
    }
    return 0;
}