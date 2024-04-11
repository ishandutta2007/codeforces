#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    int a = INT_MIN, b = INT_MAX;
    for (int i = 0; i < n; ++i) {
        int l, r; cin >> l >> r;
        a = max(a, l); b = min(b, r);
    }
    int c = INT_MIN, d = INT_MAX;
    int m; cin >> m;
    for (int i = 0; i < m; ++i) {
        int l, r; cin >> l >> r;
        c = max(c, l); d = min(d, r);
    }
    cout << (max(c - b, a - d) > 0 ? max(c - b, a - d) : 0) << '\n';
    return 0;
}