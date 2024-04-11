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
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        string ans = "YES";
        for (int i = 1; i < n - 1; i++) {
            int x = lcm(a[i - 1], a[i]);
            int y = lcm(a[i], a[i + 1]);
            if (gcd(x, y) != a[i]) {
                ans = "NO";
            }
        }
        cout << ans << '\n';
    }
    return 0;
}