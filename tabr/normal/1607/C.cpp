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
        long long d = 0;
        long long ans = a[0];
        for (int i = 0; i < n; i++) {
            a[i] += d;
            d -= a[i];
            ans = max(ans, a[i]);
        }
        cout << ans << '\n';
    }
    return 0;
}