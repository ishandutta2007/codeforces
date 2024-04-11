#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a == 0 && b == 0 && d - 1 == c) {
        cout << "YES" << '\n';
        cout << 3 << ' ';
        while (c--) {
            cout << 2 << ' ' << 3 << ' ';
        }
        cout << '\n';
        return 0;
    }
    if (c == 0 && d == 0 && a - 1 == b) {
        cout << "YES" << '\n';
        cout << 0 << ' ';
        while (b--) {
            cout << 1 << ' ' << 0 << ' ';
        }
        cout << '\n';
        return 0;
    }

    int ct01 = a;
    int ct23 = d;
    int ct12 = min(b - a, c - d);
    int xtra1 = b - (ct01 + ct12);
    int xtra2 = c - (ct12 + ct23);

    if (xtra1 > 1 || xtra2 > 1 || ct12 < 0) {
        cout << "NO" << '\n';
    } else {
        cout << "YES" << '\n';
        if (xtra1) {
            cout << 1 << ' ';
        }
        while (ct01--) {
            cout << 0 << ' ' << 1 << ' ';
        }
        while (ct12--) {
            cout << 2 << ' ' << 1 << ' ';
        }
        while (ct23--) {
            cout << 2 << ' ' << 3 << ' ';
        }
        if (xtra2) {
            cout << 2 << ' ';
        }
        cout << '\n';
    }
}