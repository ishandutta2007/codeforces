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
    int m = 100000;
    vector<int> a(m);
    a[0] = 1;
    for (int i = 0; i < m; i++) {
        if (a[i]) {
            if (i + 11 < m) {
                a[i + 11] = 1;
            }
            if (i + 111 < m) {
                a[i + 111] = 1;
            }
        }
    }
    for (int i = 0; i < 200; i++) {
        assert(a[m - 1 - i]);
    }
    while (tt--) {
        int n;
        cin >> n;
        if (n >= m) {
            cout << "YES" << '\n';
        } else if (a[n]) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}