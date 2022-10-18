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
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            mp[a - i]++;
        }
        long long ans = 0;
        for (auto [k, v] : mp) {
            ans += 1LL * v * (v - 1) / 2;
        }
        cout << ans << '\n';
    }
    return 0;
}