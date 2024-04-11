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
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int sum = 0;
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i];
            if (sum > x) {
                break;
            }
            int t = (x - sum) / (i + 1);
            ans += t + 1;
        }
        cout << ans << '\n';
    }
    return 0;
}