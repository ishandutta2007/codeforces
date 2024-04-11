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
        int n, p, k;
        cin >> n >> p >> k;
        vector<int> a(n);
        string s;
        cin >> s;
        for (int i = 0; i < n; i++) {
            a[i] = s[i] - '0';
        }
        int x, y;
        cin >> x >> y;
        vector<int> b(k);
        int ans = 2e9;
        for (int i = n - 1; i >= p - 1; i--) {
            if (!a[i]) {
                b[i % k]++;
            }
            int t = b[i % k] * x;
            int c = max(0, i - p + 1);
            t += c * y;
            ans = min(ans, t);
        }
        cout << ans << '\n';
    }
    return 0;
}