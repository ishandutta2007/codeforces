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
        vector<int> a(n + 2);
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            ans += abs(a[i] - a[i - 1]);
        }
        ans += a[n];
        for (int i = 1; i <= n; i++) {
            if (a[i - 1] < a[i] && a[i] > a[i + 1]) {
                int c = a[i] - max(a[i - 1], a[i + 1]);
                ans -= c;
                a[i] -= c;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}