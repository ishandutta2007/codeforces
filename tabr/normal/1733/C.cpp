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
        if (n == 1) {
            cout << 0 << '\n';
            continue;
        }
        vector<pair<int, int>> ans;
        ans.emplace_back(0, n - 1);
        if ((a[0] + a[n - 1]) % 2 == 1) {
            a[n - 1] = a[0];
        } else {
            a[0] = a[n - 1];
        }
        for (int i = 1; i < n - 1; i++) {
            if ((a[i] + a[0]) % 2 == 1) {
                ans.emplace_back(0, i);
            } else {
                ans.emplace_back(i, n - 1);
            }
        }
        cout << ans.size() << '\n';
        for (auto [x, y] : ans) {
            cout << x + 1 << " " << y + 1 << '\n';
        }
    }
    return 0;
}