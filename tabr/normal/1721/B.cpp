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
        int n, m, sx, sy, d;
        cin >> n >> m >> sx >> sy >> d;
        sx--, sy--;
        int ans = n + m - 2;
        if (d >= min(sx, m - 1 - sy) && d >= min(sy, n - 1 - sx)) {
            ans = -1;
        }
        cout << ans << '\n';
    }
    return 0;
}