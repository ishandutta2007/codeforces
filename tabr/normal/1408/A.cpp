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
        vector<vector<int>> a(3, vector<int>(n));
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }
        vector<int> p(n);
        p[0] = a[0][0];
        for (int i = 1; i < n - 1; i++) {
            for (int j = 0; j < 3; j++) {
                if (p[i - 1] != a[j][i]) {
                    p[i] = a[j][i];
                    break;
                }
            }
        }
        for (int i = 0; i < 3; i++) {
            if (p[0] != a[i][n - 1] && p[n - 2] != a[i][n - 1]) {
                p[n - 1] = a[i][n - 1];
                break;
            }
        }
        for (int i : p) {
            cout << i << " ";
        }
        cout << '\n';
    }
    return 0;
}