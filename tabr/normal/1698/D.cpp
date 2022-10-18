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
        auto Ask = [&](int x) {
            cout << "? " << 1 << " " << x << endl;
            int res = 0;
            for (int i = 0; i < x; i++) {
                int t;
                cin >> t;
                if (t <= x) {
                    res++;
                }
            }
            return res % 2;
        };
        int low = 0;
        int high = n;
        while (high - low > 1) {
            int mid = (high + low) >> 1;
            if (Ask(mid)) {
                high = mid;
            } else {
                low = mid;
            }
        }
        cout << "! " << high << endl;
    }
    return 0;
}