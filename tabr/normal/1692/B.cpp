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
        map<int, int> c;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            c[a]++;
        }
        int ans = (int) c.size();
        int evens = 0;
        for (auto [x, y] : c) {
            if (y % 2 == 0) {
                evens++;
            }
        }
        if (evens % 2 == 1) {
            ans--;
        }
        cout << ans << '\n';
    }
    return 0;
}