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
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        vector<int> c(n);
        for (int i = 0; i < n; i++) {
            c[i] = a[i] - b[i];
        }
        c.emplace_back(0);
        int d = *max_element(c.begin(), c.end());
        for (int i = 0; i < n; i++) {
            a[i] = max(0, a[i] - d);
        }
        if (a == b) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}