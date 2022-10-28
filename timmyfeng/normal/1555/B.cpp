#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int w, h, x1, y1, x2, y2, a, b;
        cin >> w >> h >> x1 >> y1 >> x2 >> y2 >> a >> b;

        int x = a + (x2 - x1) <= w ? min(a - x1, a - (w - x2)) : INT_MAX;
        int y = b + (y2 - y1) <= h ? min(b - y1, b - (h - y2)) : INT_MAX;

        if (min(x, y) == INT_MAX) {
            cout << -1 << "\n";
        } else {
            cout << max(0, min(x, y)) << "\n";
        }
    }
}