#include <iostream>

using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    int x = 1, y = 1, z = 1;
    for (int i = a - 1; i--;) x *= 10;
    for (int i = b - 1; i--;) y *= 10;
    for (int i = c - 1; i--;) z *= 10;

    if (a > b) {
        x += z;
    } else {
        y += z;
    }

    cout << x << " " << y << "\n";
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int q;
    cin >> q;
    while (q--) solve();

    return 0;
}