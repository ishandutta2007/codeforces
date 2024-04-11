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
        int h, w, x1, y1, x2, y2;
        cin >> h >> w >> x1 >> y1 >> x2 >> y2;
        x1--, y1--, x2--, y2--;
        int ans = (int) 1e9;
        for (int z = 0; z < 2; z++) {
            if (x1 <= x2) {
                ans = min(ans, x2 - x1);
            } else {
                ans = min(ans, h - x1 + h - x2 - 2);
            }
            swap(h, w);
            swap(x1, y1);
            swap(x2, y2);
        }
        cout << ans << '\n';
    }
    return 0;
}