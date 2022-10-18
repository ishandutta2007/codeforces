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
        long long ans = (long long) 1e18;
        for (int i = 0; i < n - 2; i++) {
            ans = min(ans, abs(a[i] - a[i + 1]) + abs(a[i + 1] - a[i + 2]));
        }
        cout << ans << '\n';
    }
    return 0;
}