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
    int n, q;
    cin >> n >> q;
    vector<vector<int>> a(q, vector<int>(3));
    for (int i = 0; i < q; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> a[i][j];
            a[i][j]--;
        }
        a[i][2]++;
        if (a[i][0] < a[i][1]) {
            swap(a[i][0], a[i][1]);
        }
    }
    vector<int> d(n);
    for (int z = 0; z < 30; z++) {
        vector<int> c(n, -1);
        vector<vector<int>> b(n);
        for (int i = 0; i < q; i++) {
            if (~a[i][2] & (1 << z)) {
                c[a[i][0]] = 0;
                c[a[i][1]] = 0;
            } else {
                b[a[i][0]].emplace_back(a[i][1]);
                b[a[i][1]].emplace_back(a[i][0]);
            }
        }
        for (int i = 0; i < n; i++) {
            if (c[i] != -1) {
                continue;
            }
            c[i] = 0;
            for (int j : b[i]) {
                if (c[j] == 0) {
                    c[i] = 1;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (c[i] == 1) {
                d[i] |= 1 << z;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << d[i] << " \n"[i == n - 1];
    }
    return 0;
}