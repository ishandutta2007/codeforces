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
        vector<vector<int>> at(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i]--;
            at[a[i]].emplace_back(i % 2);
        }
        for (int i = 0; i < n; i++) {
            int odd = 0;
            int even = 0;
            for (int x : at[i]) {
                if (x == 0) {
                    odd = even + 1;
                } else {
                    even = odd + 1;
                }
            }
            int ans = max(odd, even);
            cout << ans << " \n"[i == n - 1];
        }
    }
    return 0;
}