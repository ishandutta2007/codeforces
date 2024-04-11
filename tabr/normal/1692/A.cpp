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
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int ans = 0;
        for (int i : {b, c, d}) {
            if (a < i) {
                ans++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}