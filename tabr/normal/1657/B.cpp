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
        int n, b, x, y;
        cin >> n >> b >> x >> y;
        int a = 0;
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            if (a + x <= b) {
                a += x;
            } else {
                a -= y;
            }
            ans += a;
        }
        cout << ans << '\n';
    }
    return 0;
}