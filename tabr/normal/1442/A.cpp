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
        int mn = a[0];
        int need = 0;
        string ans = "YES";
        for (int i = 1; i < n; i++) {
            if (mn >= a[i] - need) {
                mn = a[i] - need;
            } else {
                need = max(need, a[i] - mn);
            }
        }
        if (mn < 0) {
            ans = "NO";
        }
        cout << ans << '\n';
    }
    return 0;
}