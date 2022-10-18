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
        int h, w;
        cin >> h >> w;
        string s;
        cin >> s;
        int x = 0, y = 0;
        int n = (int) s.size();
        int mnx = 0, mxx = 0, mny = 0, mxy = 0;
        int ansx = 1, ansy = 1;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'U') {
                x--;
            } else if (s[i] == 'D') {
                x++;
            } else if (s[i] == 'L') {
                y--;
            } else {
                y++;
            }
            mnx = min(mnx, x);
            mxx = max(mxx, x);
            mny = min(mny, y);
            mxy = max(mxy, y);
            if (mxx - mnx + 1 <= h && mxy - mny + 1 <= w) {
                ansx = 1 - mnx;
                ansy = 1 - mny;
            } else {
                break;
            }
        }
        cout << ansx << " " << ansy << '\n';
    }
    return 0;
}