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
        rotate(a.begin(), min_element(a.begin(), a.end()), a.end());
        string ans = "YES";
        if (a[0] != 1) {
            ans = "NO";
        }
        for (int i = 1; i < n; i++) {
            if (a[i] == 1) {
                ans = "NO";
                break;
            }
            if (a[i - 1] + 1 < a[i]) {
                ans = "NO";
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}