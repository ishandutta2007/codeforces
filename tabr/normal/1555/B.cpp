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
        int H, W;
        cin >> H >> W;
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int h, w;
        cin >> h >> w;
        if (h + x2 - x1 > H && w + y2 - y1 > W) {
            cout << -1 << '\n';
            continue;
        }
        int ans = (int) 1e9;
        if (h + x2 - x1 <= H) {
            ans = min(ans, min(max(0, h - x1), max(0, h - (H - x2))));
        }
        if (w + y2 - y1 <= W) {
            ans = min(ans, min(max(0, w - y1), max(0, w - (W - y2))));
        }
        cout << ans << '\n';
    }
    return 0;
}