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
        int n, m;
        cin >> n >> m;
        vector<vector<long long>> c(n, vector<long long>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> c[i][j];
            }
        }
        vector<long long> d(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                d[i] += c[i][j] * (j + 1);
            }
        }
        debug(d);
        auto e = d;
        sort(e.begin(), e.end());
        for (int i = 0; i < n; i++) {
            if (d[i] != e[1]) {
                cout << i + 1 << " " << (d[i] - e[1]) << '\n';
            }
        }
    }
    return 0;
}