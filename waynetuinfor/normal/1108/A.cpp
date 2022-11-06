#include <bits/stdc++.h>
using namespace std;

int main() {
    int q; cin >> q;
    while (q--) {
        int l, r, x, y; cin >> l >> r >> x >> y;
        if (l > x) {
            cout << r << ' ' << x << endl;
        } else {
            cout << l << ' ' << y << endl;
        }
    }
}