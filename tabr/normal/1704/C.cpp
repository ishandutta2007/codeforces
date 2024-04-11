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
        vector<int> a(m);
        for (int i = 0; i < m; i++) {
            cin >> a[i];
            a[i]--;
        }
        sort(a.begin(), a.end());
        a.emplace_back(a[0] + n);
        vector<int> b(m);
        for (int i = 0; i < m; i++) {
            b[i] = a[i + 1] - a[i] - 1;
        }
        sort(b.rbegin(), b.rend());
        debug(b);
        int ans = 0;
        int t = 0;
        for (int i = 0; i < m; i++) {
            b[i] -= 2 * t;
            if (b[i] > 2) {
                ans += b[i] - 1;
                t += 2;
            } else if (b[i] > 0) {
                ans += 1;
                t += 1;
            }
        }
        cout << n - ans << '\n';
    }
    return 0;
}