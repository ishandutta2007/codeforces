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
            mp[a]++;
        }
        int c = 0;
        for (auto [x, y] : mp) {
            c = max(c, y);
        }
        int ans = n - c;
        long long k = c;
        while (k < n) {
            k <<= 1;
            ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}