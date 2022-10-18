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
        int ans = 0;
        for (int i = 30; i >= 0; i--) {
            if (n & (1 << i)) {
                ans = (1 << i) - 1;
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}