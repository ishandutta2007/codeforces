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
        int cnt0 = (int) count(a.begin(), a.end(), 0);
        int cnt1 = 0;
        int ans = cnt0;
        for (int i = 0; i < n; i++) {
            if (a[i] == 1) {
                cnt1++;
            } else {
                cnt0--;
            }
            ans = min(ans, max(cnt0, cnt1));
        }
        ans = min(ans, cnt1);
        cout << ans << '\n';
    }
    return 0;
}