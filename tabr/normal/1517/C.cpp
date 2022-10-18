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
    int n;
    cin >> n;
    vector<int> p(n);
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        a[i][i] = p[i];
    }
    for (int i = 0; i < n; i++) {
        int x = i, y = i;
        for (int k = 1; k < p[i]; k++) {
            if (y && a[x][y - 1] == 0) {
                y--;
                a[x][y] = p[i];
            } else {
                x++;
                if (x == n || a[x][y]) {
                    cout << -1 << '\n';
                    return 0;
                }
                a[x][y] = p[i];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << a[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}