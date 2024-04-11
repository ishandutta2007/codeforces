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
        int ans = 1;
        for (int i = 0; i < n - 1; i++) {
            if (i != 0 && a[i] == a[i - 1]) {
                continue;
            }
            vector<long long> b;
            b.emplace_back(a[i]);
            b.emplace_back(a[i + 1]);
            int j = i + 1;
            while (j < n - 1 && b.back() * 2 - a[i] <= a[n - 1]) {
                j = (int) (lower_bound(a.begin() + j + 1, a.end(), b.back() * 2 - a[i]) - a.begin());
                b.emplace_back(a[j]);
            }
            debug(b);
            ans = max(ans, (int) b.size());
        }
        ans = n - ans;
        cout << ans << '\n';
    }
    return 0;
}