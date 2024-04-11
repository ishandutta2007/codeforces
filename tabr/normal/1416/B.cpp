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
        long long s = accumulate(a.begin(), a.end(), 0LL);
        if (s % n != 0) {
            cout << -1 << '\n';
            continue;
        }
        cout << 3 * (n - 1) << '\n';
        for (int i = 1; i < n; i++) {
            long long x = (i + 1 - (a[i] % (i + 1) + i + 1) % (i + 1)) % (i + 1);
            cout << 1 << " " << i + 1 << " " << x << '\n';
            a[i] += x;
            cout << i + 1 << " " << 1 << " " << a[i] / (i + 1) << '\n';
        }
        for (int i = 1; i < n; i++) {
            cout << 1 << " " << i + 1 << " " << s / n << '\n';
        }
    }
    return 0;
}