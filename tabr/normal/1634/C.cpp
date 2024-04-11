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
        int n, k;
        cin >> n >> k;
        if (k == 1) {
            cout << "YES" << '\n';
            for (int i = 0; i < n; i++) {
                cout << i + 1 << '\n';
            }
            continue;
        }
        if (n % 2 == 1) {
            cout << "NO" << '\n';
            continue;
        }
        cout << "YES" << '\n';
        vector<vector<int>> a(n, vector<int>(k));
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < n; j++) {
                a[j][i] = 1 + i * n + j;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) {
                cout << a[i][j] << " \n"[j == k - 1];
            }
        }
    }
    return 0;
}