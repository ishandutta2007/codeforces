#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int w, h;
        cin >> w >> h;
        if(w + (x2 - x1) > n && h + (y2 - y1) > m) {
            cout << -1 << endl;
        } else {
            int lx = x1, rx = n - x2;
            int ly = y1, ry = m - y2;
            if(max(lx, rx) >= w || max(ly, ry) >= h) {
                cout << 0 << endl;
            } else {
                int ans = 1e9;
                if(w + x2 - x1 <= n) ans = min(ans, w - max(lx, rx));
                if(h + y2 - y1 <= m) ans = min(ans, h - max(ly, ry));
                cout << ans << endl;
            }
        }
    }
}