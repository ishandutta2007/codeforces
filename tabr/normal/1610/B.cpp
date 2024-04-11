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
        }
        vector<int> b = a;
        reverse(b.begin(), b.end());
        if (a == b) {
            cout << "YES" << '\n';
            continue;
        }
        int x = -1, y = -1;
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                x = a[i];
                y = b[i];
                break;
            }
        }
        vector<int> c, d;
        for (int i = 0; i < n; i++) {
            if (a[i] != x) {
                c.emplace_back(a[i]);
            }
            if (a[i] != y) {
                d.emplace_back(a[i]);
            }
        }
        auto e = c;
        auto f = d;
        reverse(e.begin(), e.end());
        reverse(f.begin(), f.end());
        if (c == e || d == f) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}