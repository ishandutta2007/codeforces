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
        long long k;
        cin >> k;
        vector<long long> x(n);
        for (int i = 0; i < n; i++) {
            cin >> x[i];
        }
        long long g = 0;
        sort(x.begin(), x.end());
        for (int i = 0; i < n - 1; i++) {
            g = __gcd(g, x[i + 1] - x[i]);
        }
        string ans = "NO";
        if ((k % g + g) % g == (x[0] % g + g) % g) {
            ans = "YES";
        }
        for (int i = 0; i < n; i++) {
            if (x[i] == k) {
                ans = "YES";
            }
        }
        cout << ans << '\n';
    }
    return 0;
}