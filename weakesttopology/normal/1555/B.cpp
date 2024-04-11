#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int W, H, x[2], y[2], w, h;
        cin >> W >> H;
        for (int t : {0, 1}) {
            cin >> x[t] >> y[t];
        }
        cin >> w >> h;
        if (x[1] - x[0] + w > W && y[1] - y[0] + h > H) {
            cout << -1 << '\n';
        }
        else {
            int ans = 0x3f3f3f3f;
            // side by side
            if (x[1] - x[0] + w <= W) {
                int dx = min(max(0, w - x[0]), max(0, x[1] - (W - w)));
                ans = min(ans, dx);
            }
            // one on top
            if (y[1] - y[0] + h <= H) {
                int dy = min(max(0, h - y[0]), max(0, y[1] - (H - h)));
                ans = min(ans, dy);
            }
            cout << ans << '\n';
        }
    }
    exit(0);
}