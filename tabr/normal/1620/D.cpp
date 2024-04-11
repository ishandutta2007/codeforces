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
        sort(a.begin(), a.end());
        int ans = (int) 1e9;
        for (int x = 0; x <= 10; x++) {
            for (int y = 0; y <= 10; y++) {
                int need = 0;
                int ok = 1;
                for (int i = 0; i < n; i++) {
                    int z = (int) 1e9;
                    for (int b = 0; b <= x; b++) {
                        for (int c = 0; c <= y; c++) {
                            int d = a[i] - b - c * 2;
                            if (d >= 0 && d % 3 == 0) {
                                z = min(z, d / 3);
                            }
                        }
                    }
                    need = max(need, z);
                }
                if (ok) {
                    ans = min(ans, need + x + y);
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}