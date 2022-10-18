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
    int k;
    cin >> k;
    string s;
    cin >> s;
    int n = 1 << k;
    int tt;
    cin >> tt;
    vector<int> b, c;
    vector<vector<int>> a(k + 1);
    a[0] = vector<int>(n, 1);
    for (int i = 1; i <= k; i++) {
        a[i] = vector<int>(1 << (k - i));
        for (int j = 0; j < (1 << (k - i)); j++) {
            int l = (int) b.size();
            b.emplace_back(i);
            c.emplace_back(j);
            if (s[l] != '1') {
                a[i][j] += a[i - 1][2 * j];
            }
            if (s[l] != '0') {
                a[i][j] += a[i - 1][2 * j + 1];
            }
        }
    }
    while (tt--) {
        int id;
        cin >> id;
        id--;
        cin >> s[id];
        while (id < n - 1) {
            debug(id);
            int i = b[id], j = c[id];
            a[i][j] = 0;
            if (s[id] != '1') {
                a[i][j] += a[i - 1][2 * j];
            }
            if (s[id] != '0') {
                a[i][j] += a[i - 1][2 * j + 1];
            }
            id += j / 2 - j + (1 << (k - i));
        }
        cout << a[k][0] << '\n';
    }
    return 0;
}