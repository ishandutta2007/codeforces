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
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long x = 0;
    long long ans = 0;
    for (int i = 29; i >= 0; i--) {
        vector<long long> b(n);
        for (int j = 0; j < n; j++) {
            b[j] = a[j] ^ x;
        }
        stable_sort(b.begin(), b.end(), [&](long long p, long long q) {
            return (p >> (i + 1)) < (q >> (i + 1));
        });
        long long p = 0, q = 0;
        for (int k = 0; k < n; k++) {
            int l = k;
            while (l != n - 1 && (b[k] >> (i + 1)) == (b[l + 1] >> (i + 1))) {
                l++;
            }
            long long t = 0;
            for (int j = l; j >= k; j--) {
                if (b[j] & (1LL << i)) {
                    p += t;
                } else {
                    t++;
                }
            }
            t = 0;
            for (int j = l; j >= k; j--) {
                if (b[j] & (1LL << i)) {
                    t++;
                } else {
                    q += t;
                }
            }
            k = l;
        }
        if (p > q) {
            x += 1LL << i;
        }
        ans += min(p, q);
    }
    cout << ans << " " << x << '\n';
    return 0;
}