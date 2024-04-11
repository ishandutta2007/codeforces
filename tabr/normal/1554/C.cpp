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
        int n, m;
        cin >> n >> m;
        if (n > m) {
            cout << 0 << '\n';
            continue;
        }
        int ans = 0;
        int t = 1;
        for (int i = 29; i >= 0; i--) {
            if (t && !(n & (1 << i)) && (m & (1 << i))) {
                ans ^= 1 << i;
            } else if ((n & (1 << i)) && !(m & (1 << i))) {
                t = 0;
            }
        }
        if (t == 1) {
            for (int i = 0; i < 30; i++) {
                if (!(n & (1 << i)) && !(m & (1 << i))) {
                    ans ^= 1 << i;
                    break;
                } else {
                    ans &= ~(1 << i);
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}