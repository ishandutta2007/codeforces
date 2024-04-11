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
        vector<int> d(n);
        for (int i = 0; i < n; i++) {
            cin >> d[i];
        }
        bool ok = true;
        for (int i = 1; i < n; i++) {
            if (d[i] != 0 && d[i - 1] >= d[i]) {
                ok = false;
                break;
            }
            d[i] += d[i - 1];
        }
        if (ok) {
            for (int i = 0; i < n; i++) {
                cout << d[i] << " \n"[i == n - 1];
            }
        } else {
            cout << -1 << '\n';
        }
    }
    return 0;
}