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
        vector<int> a(3);
        for (int i = 0; i < 3; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        string ans = "NO";
        if (a[0] == a[1]) {
            if (a[2] % 2 == 0) {
                ans = "YES";
            }
        }
        if (a[1] == a[2]) {
            if (a[0] % 2 == 0) {
                ans = "YES";
            }
        }
        if (a[0] + a[1] == a[2]) {
            ans = "YES";
        }
        cout << ans << '\n';
    }
    return 0;
}