#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        auto ask = [&](int x, int y) {
            assert(0 <= x && x < n);
            assert(0 <= y && y < m);
            cout << "SCAN " << x + 1 << ' ' << y + 1 << endl;
            int ret;
            cin >> ret;
            return ret;
        };
        auto dig = [&](int x, int y) {
            cout << "DIG " << x + 1 << ' ' << y + 1 << endl;
            int ret;
            cin >> ret;
            return ret;
        };
        int l = ask(0, 0), r = ask(0, m - 1);
        // (x1, y1), (x2, y2)
        // x1 + x2 + y1 + y2 = l
        // x1 + x2 + (m - 1 - y1) + (m - 1 - y2) = r
        // x1 + x2 - y1 - y2 = r - 2 * (m - 1)

        // 2 * (x1 + x2) = l + r - 2 * (m - 1)
        // 2 * (y1 + y2) = 2 * (m - 1) + l - r
        int sx = (l + r - 2 * (m - 1)) / 2, sy = (2 * (m - 1) + l - r) / 2;
        int dx = ask(sx / 2, 0), dy = ask(0, sy / 2);
        // x2 - x1 + y1 + y2 = dx (x1 <= x2)
        // 2x1 = l - dx
        int x1 = (l - dx) / 2, x2 = sx - x1;
        int y1 = (l - dy) / 2, y2 = sy - y1;
        if(dig(x1, y1)) {
            assert(dig(x2, y2));
        } else {
            assert(dig(x1, y2));
            assert(dig(x2, y1));
        }
    }
}