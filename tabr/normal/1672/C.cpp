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
        vector<int> c;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] == a[i + 1]) {
                c.emplace_back(i);
            }
        }
        if (c.size() <= 1) {
            cout << 0 << '\n';
            continue;
        }
        int x = c.back() - c[0];
        cout << max(1, x - 1) << '\n';
    }
    return 0;
}