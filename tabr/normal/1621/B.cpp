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
        int n;
        cin >> n;
        long long inf = (long long) 1e10;
        long long mn = inf;
        long long mx = -inf;
        long long cmn = inf;
        long long cmx = inf;
        long long c2 = inf;
        for (int i = 0; i < n; i++) {
            long long l, r, c;
            cin >> l >> r >> c;
            if (mn > l) {
                mn = l;
                cmn = c2 = inf;
            }
            if (mx < r) {
                mx = r;
                cmx = c2 = inf;
            }
            if (mn == l) {
                cmn = min(cmn, c);
            }
            if (mx == r) {
                cmx = min(cmx, c);
            }
            if (mn == l && mx == r) {
                c2 = min(c2, c);
            }
            cout << min(cmn + cmx, c2) << '\n';
        }
    }
    return 0;
}