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
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i]--;
            a[i] = min(a[i], m - 1 - a[i]);
        }
        sort(a.begin(), a.end());
        string ans(m, 'B');
        for (int i = 0; i < n; i++) {
            if (i == 0 || a[i] != a[i - 1]) {
                ans[a[i]] = 'A';
            } else {
                ans[m - 1 - a[i]] = 'A';
            }
        }
        cout << ans << '\n';
    }
    return 0;
}