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
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i] >> b[i];
        }
        vector<int> x(n), y(n);
        long long c = 0;
        for (int i = 0; i < n; i++) {
            x[i] = min(m, a[i]);
            y[i] = m - x[i];
            c += (b[i] - y[i]) - (a[i] - x[i]);
        }
        for (int i = 0; i < n; i++) {
            int ny = min(m, b[i]);
            int nx = m - ny;
            if (c + y[i] - x[i] - ny + nx >= 0) {
                c = c + y[i] - x[i] - ny + nx;
                x[i] = nx;
                y[i] = ny;
                continue;
            }
            if (c < 0) {
                break;
            }
            int px = (int) (m + x[i] - y[i] - c) / 2;
            for (int ix = min(px + 3, x[i]); ix >= max(px - 3, nx); ix--) {
                int iy = m - ix;
                if (c + y[i] - x[i] - iy + ix >= 0) {
                    c = c + y[i] - x[i] - iy + ix;
                    x[i] = ix;
                    y[i] = iy;
                }
            }
            break;
        }
        cout << abs(c) << '\n';
        for (int i = 0; i < n; i++) {
            cout << x[i] << " " << y[i] << '\n';
        }
    }
    return 0;
}