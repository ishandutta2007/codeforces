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
            a[i]--;
        }
        vector<int> b(n);
        iota(b.begin(), b.end(), 0);
        if (a == b) {
            cout << 0 << '\n';
        } else if (a[0] == 0 || a[n - 1] == n - 1) {
            cout << 1 << '\n';
        } else if (a[0] == n - 1 && a[n - 1] == 0) {
            cout << 3 << '\n';
        } else {
            cout << 2 << '\n';
        }
    }
    return 0;
}