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
        int l, r, a;
        cin >> l >> r >> a;
        int ans = r / a + r % a;
        r -= r % a;
        r--;
        if (r >= l) {
            ans = max(ans, r / a + r % a);
        }
        cout << ans << '\n';
    }
    return 0;
}