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
        int u, v;
        cin >> u >> v;
        if (u > v) {
            cout << "NO" << '\n';
            continue;
        }
        vector<int> a(30), b(30);
        for (int i = 0; i < 30; i++) {
            if (u & (1 << i)) {
                a[i]++;
            }
            if (v & (1 << i)) {
                b[i]++;
            }
            if (i) {
                a[i] += a[i - 1];
                b[i] += b[i - 1];
            }
        }
        string ans = "YES";
        for (int i = 0; i < 30; i++) {
            if (a[i] < b[i]) {
                ans = "NO";
            }
        }
        cout << ans << '\n';
    }
    return 0;
}