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
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        a[i][i] = b[i];
    }
    if (n == 2) {
        if (b[0] == b[1]) {
            a[0][1] = 1;
        }
    } else {
        vector<vector<int>> c(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                c[i][j] = i * j % n;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[i][(i + j) % n] = (b[i] + c[i][j]) % n;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " \n"[j == n - 1];
        }
    }
    return 0;
}