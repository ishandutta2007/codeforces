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
        a[0] = 1;
        for (int i = 1; i < n; i++) {
            if (3LL * a[i - 1] > (int) 1e9) {
                a[0] = -1;
                cout << "NO" << '\n';
                break;
            }
            a[i] = a[i - 1] * 3;
        }
        if (a[0] != -1) {
            cout << "YES" << '\n';
            for (int i = 0; i < n; i++) {
                cout << a[i] << " \n"[i == n - 1];
            }
        }
    }
    return 0;
}