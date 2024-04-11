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
        int n, k, b;
        long long s;
        cin >> n >> k >> b >> s;
        long long high = s / k;
        long long low = (s - (k - 1) * 1LL * (n - 1)) / k;
        if (b < low || high < b) {
            cout << -1 << '\n';
        } else {
            vector<long long> a(n);
            a[0] = s;
            for (int i = 1; i < n; i++) {
                if (a[0] > b * 1LL * k) {
                    a[i] = min(a[0] - b * 1LL * k, k - 1LL);
                    a[0] -= a[i];
                }
            }
            for (int i = 0; i < n; i++) {
                cout << a[i] << " \n"[i == n - 1];
            }
        }
    }
    return 0;
}