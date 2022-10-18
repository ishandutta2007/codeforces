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
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        long long ans = LLONG_MAX;
        for (long long z = a[n - 1]; z <= a[n - 1] + 1; z++) {
            long long t = LLONG_MAX;
            vector<long long> b(n);
            for (int i = 0; i < n; i++) {
                b[i] = z - a[i];
            }
            long long one = 0;
            long long two = 0;
            for (int i = 0; i < n; i++) {
                if (b[i] % 2 == 1) {
                    b[i]--;
                    one++;
                }
                two += b[i] / 2;
            }
            for (long long c = max(0LL, (two - one) / 3 - 10); c <= max(0LL, (two - one) / 3 + 10); c++) {
                t = min(t, max((one + 2 * c) * 2 - 1, (two - c) * 2));
            }
            ans = min(ans, t);
        }
        cout << ans << '\n';
    }
    return 0;
}