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
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        if (a[0] == a[n - 1]) {
            cout << "YES" << '\n';
        } else if (!binary_search(a.begin(), a.end(), 1)) {
            cout << "YES" << '\n';
        } else if (a[0] == 0) {
            cout << "NO" << '\n';
        } else {
            string ans = "YES";
            for (int i = 0; i < n - 1; i++) {
                if (a[i + 1] - a[i] == 1) {
                    ans = "NO";
                }
            }
            cout << ans << '\n';
        }
    }
    return 0;
}