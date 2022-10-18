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
        if (a[n - 1] == 0) {
            for (int i = 1; i <= n + 1; i++) {
                cout << i << " ";
            }
            cout << '\n';
            continue;
        } else if (a[0] == 1) {
            cout << n + 1 << " ";
            for (int i = 1; i <= n; i++) {
                cout << i << " ";
            }
            cout << '\n';
            continue;
        }
        for (int i = 0; i < n - 1; i++) {
            if (a[i] == 0 && a[i + 1] == 1) {
                for (int j = 1; j <= n; j++) {
                    cout << j << " ";
                    if (j == i + 1) {
                        cout << n + 1 << " ";
                    }
                }
                cout << '\n';
                break;
            }
            if (i == n - 2) {
                cout << -1 << '\n';
            }
        }
    }
    return 0;
}