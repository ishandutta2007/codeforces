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
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        vector<vector<long long>> c(2);
        for (int i = 0; i < n; i++) {
            c[a[i]].emplace_back(b[i]);
        }
        sort(c[0].rbegin(), c[0].rend());
        sort(c[1].rbegin(), c[1].rend());
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += b[i];
        }
        if (c[0].size() == c[1].size()) {
            sort(b.begin(), b.end());
            for (int i = 1; i < n; i++) {
                ans += b[i];
            }
        } else {
            if (c[0].size() > c[1].size()) {
                swap(c[0], c[1]);
            }
            for (int i = 0; i < (int) c[0].size(); i++) {
                ans += c[0][i];
                ans += c[1][i];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}