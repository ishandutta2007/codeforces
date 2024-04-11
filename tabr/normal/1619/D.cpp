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
        int m, n;
        cin >> m >> n;
        vector<vector<int>> a(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }
        int lo = 1;
        int hi = (int) 1e9 + 10;
        while (hi - lo > 1) {
            int mid = (hi + lo) / 2;
            vector<vector<int>> b(m, vector<int>(n));
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    b[i][j] = (a[i][j] >= mid);
                }
            }
            vector<int> c(n);
            int d = 0;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (b[i][j]) {
                        c[j] = 1;
                    }
                }
                if (accumulate(b[i].begin(), b[i].end(), 0) > 1) {
                    d = 1;
                }
            }
            if (d && all_of(c.begin(), c.end(), [&](int x) { return x; })) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
        cout << lo << '\n';
    }
    return 0;
}