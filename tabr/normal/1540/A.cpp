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
        vector<long long> d(n);
        for (int i = 0; i < n; i++) {
            cin >> d[i];
        }
        sort(d.begin(), d.end());
        long long ans = 0;
        long long s = 0;
        for (int i = 0; i < n; i++) {
            ans -= d[i] * i - s;
            s += d[i];
        }
        ans += d[n - 1];
        cout << ans << '\n';
    }
    return 0;
}