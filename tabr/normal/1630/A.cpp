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
        int n, k;
        cin >> n >> k;
        if (n == 4 && k == 3) {
            cout << -1 << '\n';
            continue;
        } else if (n == 8 && k == 7) {
            cout << "0 6\n1 3\n2 7\n5 4\n";
            continue;
        }
        vector<int> a(n);
        iota(a.begin(), a.end(), 0);
        int t = __builtin_ctz(n);
        for (int i = t - 1; i >= 2; i--) {
            if (k & (1 << i)) {
                int x = 1 << i;
                swap(a[2 * x - 1], a[x - 1]);
            }
        }
        t = k & 3;
        if (t == 1) {
            swap(a[n - 2], a[n - 1]);
        } else if (t == 2) {
            swap(a[n - 3], a[n - 1]);
        } else if (t == 3) {
            swap(a[n - 2], a[n - 1]);
            swap(a[n - 3 - 4], a[n - 1 - 4]);
        }
        int b = 0;
        for (int i = 0; i < n / 2; i++) {
            cout << a[i] << " " << a[n - 1 - i] << '\n';
            b += a[i] & a[n - 1 - i];
        }
        debug(b);
    }
    return 0;
}