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
    int tt;
    cin >> tt;
    while (tt--) {
        int x, y;
        cin >> x >> y;
        int ax = -1, ay = -1;
        auto f = [&](int a, int b, int c, int d) {
            return abs(a - c) + abs(b - d);
        };
        for (int i = 0; i <= x; i++) {
            for (int j = 0; j <= y; j++) {
                int ac = f(0, 0, i, j);
                int bc = f(x, y, i, j);
                int ab = f(0, 0, x, y);
                if (ac * 2 == ab && bc * 2 == ab) {
                    ax = i;
                    ay = j;
                }
            }
        }
        cout << ax << " " << ay << '\n';
    }
    return 0;
}