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
        long long u, v;
        cin >> u >> v;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int b = 0;
        for (int i = 0; i < n - 1; i++) {
            b = max(b, abs(a[i] - a[i + 1]));
        }
        if (b >= 2) {
            cout << 0 << '\n';
            continue;
        } else if (b == 1) {
            cout << min(u, v) << '\n';
        } else {
            cout << v + min(u, v) << '\n';
        }
    }
    return 0;
}