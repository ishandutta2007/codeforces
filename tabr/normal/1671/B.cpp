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
        vector<int> x(n);
        for (int i = 0; i < n; i++) {
            cin >> x[i];
        }
        if (n == 1) {
            cout << "YES" << '\n';
            continue;
        }
        vector<int> y(n - 1);
        for (int i = 0; i < n - 1; i++) {
            y[i] = x[i + 1] - x[i] - 1;
        }
        if (accumulate(y.begin(), y.end(), 0) > 2) {
            cout << "NO" << '\n';
        } else {
            cout << "YES" << '\n';
        }
    }
    return 0;
}