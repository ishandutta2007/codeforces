#include <bits/stdc++.h>
using namespace std;

const int kN = 20 + 5;
string s[kN], t[kN], r[kN * kN];

int main() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> s[i];
    for (int i = 0; i < m; ++i) cin >> t[i];
    for (int i = 0, x = 0, y = 0; i < n * m; ++i) {
        r[i] = s[x] + t[y];
        if (++x == n) x = 0;
        if (++y == m) y = 0;
    }
    int q; cin >> q;
    while (q--) {
        int y; cin >> y;
        cout << r[(y - 1) % (n * m)] << '\n';
    }
}