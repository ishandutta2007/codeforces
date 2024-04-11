#include <bits/stdc++.h>
using namespace std;

// long long solve(long long k, long long n, long long m, long long s) {
    // long long rem = k - (abs(s) + abs(n - s) + abs(m - s));
    // if (rem < 0) return -1;
    // long long res = abs(s) + abs(n - s) / 2 * 2 + abs(m - s) / 2 * 2;
    // if (rem % 2 == 0) return res + rem;
    // return -1;
// }
//
//
const long long inf = 3e18;

inline long long solve(long long k, long long s, long long n, long long m) {
    long long dx = abs(n - s), dy = abs(m - s);
    long long res = (dx / 2) * 2 + (dy / 2) * 2;
    long long use = dx + dy;
    if (k < use) return -inf;
    if ((k - use) % 2 == 0) return (k - use) + res;
    return -inf;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int q; cin >> q;
    while (q--) {
        long long n, m, k; cin >> n >> m >> k;
        n = abs(n), m = abs(m);
        long long s = min(n, m);
        int d = 61;
        while (d--) {
            if (s - (1ll << d) >= 0) {
                long long t = s - (1ll << d);
                if (t + abs(n - t) + abs(m - t) <= k) s = t;
            }
        }
        long long ans = -1;
        for (int i = -min(10ll, k); i <= min(10ll, k); ++i) ans = max(ans, solve(k - abs(s + i), s + i, n, m) + abs(s + i));
        cout << ans << endl;
    }
}