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
        if (a[n - 1] >= 0 && a[n - 2] <= a[n - 1]) {
            cout << n - 2 << '\n';
            for (int i = n - 3; i >= 0; i--) {
                cout << i + 1 << " " << n - 1 << " " << n << '\n';
            }
        } else if (a[n - 1] >= 0) {
            cout << -1 << '\n';
        } else if (is_sorted(a.begin(), a.end())) {
            cout << 0 << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
    return 0;
}