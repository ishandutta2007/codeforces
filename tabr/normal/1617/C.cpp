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
        sort(a.begin(), a.end());
        vector<int> b(n + 1);
        vector<int> c, d;
        for (int i = 0; i < n; i++) {
            if (a[i] <= n && !b[a[i]]) {
                b[a[i]] = 1;
            } else {
                c.emplace_back(a[i]);
            }
        }
        for (int i = 1; i <= n; i++) {
            if (!b[i]) {
                d.emplace_back(i);
            }
        }
        int ans = (int) c.size();
        for (int i = 0; i < ans; i++) {
            if ((c[i] - d[i]) < d[i] + 1) {
                ans = -1;
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}