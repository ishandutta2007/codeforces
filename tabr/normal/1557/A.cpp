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
        double ans = a[n - 1];
        double sum = accumulate(a.begin(), a.end(), 0.0);
        sum -= a[n - 1];
        ans += sum / (n - 1);
        cout << fixed << setprecision(12) << ans << '\n';
    }
    return 0;
}