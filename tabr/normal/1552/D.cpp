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
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i] = abs(a[i]);
        }
        sort(a.begin(), a.end());
        a.resize(unique(a.begin(), a.end()) - a.begin());
        if ((int) a.size() < n || a[0] == 0) {
            cout << "YES" << '\n';
            continue;
        }
        int ok = 0;
        int total = 1;
        for (int i = 0; i < n; i++) {
            total *= 3;
        }
        for (int mask = 0; mask < total; mask++) {
            int s = 0;
            int c = mask;
            for (int i = 0; i < n; i++) {
                if (c % 3 == 1) {
                    s += a[i];
                } else if (c % 3 == 2) {
                    s -= a[i];
                }
                c /= 3;
            }
            s = abs(s);
            c = mask;
            for (int i = 0; i < n; i++) {
                if (c % 3 == 0) {
                    if (s == a[i]) {
                        ok = 1;
                        break;
                    }
                }
                c /= 3;
            }
        }
        if (ok) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}