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
        int a, b;
        cin >> a >> b;
        vector<int> ans;
        if (a < b) {
            swap(a, b);
        }
        int n = a + b;
        int x = (n + 1) / 2;
        int y = n / 2;
        for (int i = 0; i <= a + b; i++) {
            int ok = 0;
            for (int _ = 0; _ < 2; _++) {
                if (x - a == b - y) {
                    int p = (i + x - a) / 2;
                    int q = (i - x + a) / 2;
                    if (p + q == i && p - q == x - a && p <= x && q <= y && 0 <= p && 0 <= q) {
                        ok = 1;
                    }
                }
                swap(x, y);
            }
            if (ok) {
                ans.emplace_back(i);
            }
        }
        cout << ans.size() << '\n';
        for (int i : ans) {
            cout << i << " ";
        }
        cout << '\n';
    }
    return 0;
}