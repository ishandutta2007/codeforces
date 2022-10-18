#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        bool zero = false;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] > k) {
                a[i] = 1;
            } else if (a[i] == k) {
                a[i] = 1;
                zero = true;
            } else {
                a[i] = 0;
            }
        }
        if (!zero) {
            cout << "no" << '\n';
            continue;
        }
        bool ok = false;
        if (n == 1) {
            ok = true;
        }
        for (int i = 0; i < n; i++) {
            if (!a[i]) {
                continue;
            }
            for (int j = max(0, i - 2); j <= min(i + 2, n - 1); j++) {
                if (i == j) {
                    continue;
                }
                if (a[j]) {
                    ok = true;
                    break;
                }
            }
            if (ok) {
                break;
            }
        }
        if (ok) {
            cout << "yes" << '\n';
        } else {
            cout << "no" << '\n';
        }
    }
    return 0;
}