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
        map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[a[i]].emplace_back(i);
        }
        long long ans = 0;
        for (auto [k, v] : mp) {
            long long s = 0;
            for (int i : v) {
                ans += s * (n - i);
                s += i + 1;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}