#include <bits/stdc++.h>
using namespace std;


int main() {
    int t; cin >> t;
    while(t--) {
        int W, H; cin >> W >> H;
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        int w, h; cin >> w >> h;
        if((h + (y2 - y1)) > H && (w + (x2 - x1)) > W) {
            cout << -1 << "\n";
        }
        else {
            int ans = 1e9;
            if((h + (y2 - y1)) <= H) {
                ans = min(ans, h - y1);
                ans = min(ans, y2 - (H - h));
            }
            if((w + (x2 - x1)) <= W) {
                ans = min(ans, w - x1);
                ans = min(ans, x2 - (W - w));
            }
            ans = max(ans, 0);
            cout << ans << "\n";
        }
    }
}