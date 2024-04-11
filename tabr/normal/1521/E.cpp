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
        int m, k;
        cin >> m >> k;
        vector<pair<int, int>> a(k);
        for (int i = 1; i <= k; i++) {
            int c;
            cin >> c;
            a[i - 1] = {c, i};
        }
        sort(a.rbegin(), a.rend());
        vector<int> b;
        for (auto [i, j] : a) {
            for (int l = 0; l < i; l++) {
                b.emplace_back(j);
            }
        }
        int n = 1;
        while (true) {
            if ((n / 2 + n) * ((n + 1) / 2) < m) {
                n++;
                continue;
            }
            if (a[0].first > n * ((n + 1) / 2)) {
                n++;
                continue;
            }
            break;
        }
        cout << n << '\n';
        vector<vector<int>> ans(n, vector<int>(n));
        int l = 0;
        for (int i = 0; i < n && l < m; i += 2) {
            for (int j = 1; j < n && l < m; j += 2) {
                ans[i][j] = b[l++];
            }
        }
        for (int i = 0; i < n && l < m; i += 2) {
            for (int j = 0; j < n && l < m; j += 2) {
                ans[i][j] = b[l++];
            }
        }
        for (int i = 1; i < n && l < m; i += 2) {
            for (int j = 0; j < n && l < m; j += 2) {
                ans[i][j] = b[l++];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << ans[i][j] << " ";
            }
            cout << '\n';
        }
    }
    return 0;
}