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
    int h, w, q;
    cin >> h >> w >> q;
    vector<vector<int>> a(h, vector<int>(w));
    long long ans = h * w;
    auto f = [&](int z) {
        if (z == -1) {
            return 0LL;
        }
        long long res = 0;
        int t = 0;
        int x = 0, y = 0;
        if (z < w) {
            y = w - 1 - z;
        } else {
            x = z - (w - 1);
        }
        int c = 0;
        if (y != 0) {
            c = 1;
            y--;
        }
        while (x < h && y < w) {
            if (a[x][y]) {
                res += t * (t - 1) / 2;
                t = 0;
            } else {
                t++;
            }
            if (c == 0) {
                x++;
            } else {
                y++;
            }
            c ^= 1;
        }
        res += t * (t - 1) / 2;
        return res;
    };
    for (int i = 0; i < h + w - 1; i++) {
        debug(f(i));
        ans += f(i);
    }
    while (q--) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        int z = x - y + w - 1;
        ans -= f(z);
        ans -= f(z - 1);
        a[x][y] ^= 1;
        ans += f(z);
        ans += f(z - 1);
        if (a[x][y]) {
            ans--;
        } else {
            ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}