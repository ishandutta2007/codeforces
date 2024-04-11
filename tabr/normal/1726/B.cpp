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
        int n, m;
        cin >> n >> m;
        if (m < n) {
            cout << "No" << '\n';
            continue;
        }
        vector<int> ans(n, 1);
        if (n % 2 == 1) {
            ans[n - 1] = m - (n - 1);
        } else {
            if (m % 2 != n % 2) {
                cout << "No" << '\n';
                continue;
            }
            ans[n - 2] = (m - (n - 2)) / 2;
            ans[n - 1] = (m - (n - 2)) / 2;
        }
        cout << "Yes" << '\n';
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " \n"[i == n - 1];
        }
    }
    return 0;
}