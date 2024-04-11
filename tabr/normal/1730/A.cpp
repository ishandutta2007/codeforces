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
        int n, c;
        cin >> n >> c;
        map<int, int> a;
        for (int i = 0; i < n; i++) {
            int b;
            cin >> b;
            a[b]++;
        }
        int ans = 0;
        for (auto [x, y] : a) {
            ans += min(c, y);
        }
        cout << ans << '\n';
    }
    return 0;
}