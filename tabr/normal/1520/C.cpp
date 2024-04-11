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
        if (n == 1) {
            cout << 1 << '\n';
            continue;
        } else if (n == 2) {
            cout << -1 << '\n';
            continue;
        }
        vector<vector<int>> a(n, vector<int>(n));
        int k = 1;
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n; i++) {
                a[i][j] = k++;
            }
        }
        for (int i = 0; i < n; i += 2) {
            rotate(a[i].begin(), a[i].begin() + 1, a[i].end());
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << a[i][j] << " ";
            }
            cout << '\n';
        }
    }
    return 0;
}