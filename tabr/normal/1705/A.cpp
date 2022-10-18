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
        int x;
        cin >> x;
        vector<int> a(2 * n);
        for (int i = 0; i < 2 * n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        string ans = "YES";
        for (int i = 0; i < n; i++) {
            if (a[i] + x > a[i + n]) {
                ans = "NO";
            }
        }
        cout << ans << '\n';
    }
    return 0;
}