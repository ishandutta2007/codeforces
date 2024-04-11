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
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> b(m);
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
        int c = b[0];
        for (int i = 0; i < m; i++) {
            c = __gcd(c, b[i]);
        }
        vector<vector<long long>> d(c);
        vector<int> e(c);
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            d[i % c].emplace_back(abs(a[i]));
            sum += abs(a[i]);
            if (a[i] < 0) {
                e[i % c] ^= 1;
            }
        }
        long long best = (long long) 1e18;
        for (int z = 0; z < 2; z++) {
            long long now = 0;
            for (int i = 0; i < c; i++) {
                if (!e[i]) {
                    continue;
                }
                long long t = (long long) 1e18;
                for (auto x : d[i]) {
                    t = min(t, abs(x));
                }
                now += t;
            }
            best = min(best, now);
            for (int i = 0; i < c; i++) {
                e[i] ^= 1;
            }
        }
        if (c == 1) {
            best = 0;
        }
        long long ans = sum - best * 2;
        cout << ans << '\n';
    }
    return 0;
}