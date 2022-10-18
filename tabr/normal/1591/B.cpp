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
        reverse(a.begin(), a.end());
        int k = a[0];
        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (k < a[i]) {
                k = a[i];
                ans++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}