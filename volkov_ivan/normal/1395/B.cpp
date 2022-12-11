#include <bits/stdc++.h>

using namespace std;

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    int n, m, sx, sy;
    cin >> n >> m >> sx >> sy;
    cout << sx << ' ' << sy << endl;
    for (int y = 1; y <= m; y++) {
        if (y == sy) continue; 
        cout << sx << ' ' << y << endl; 
    }
    int c = 0;
    for (int x = 1; x <= n; x++) {
        if (x == sx) continue;
        c++;
        if (c % 2 == 1) {
            for (int y = m; y >= 1; y--) {
                cout << x << ' ' << y << endl;
            }
        } else {
            for (int y = 1; y <= m; y++) {
                cout << x << ' ' << y << endl;
            }
        }
    }
    return 0;
}