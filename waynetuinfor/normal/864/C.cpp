#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    int a, b, f, k; cin >> a >> b >> f >> k;
    int cur = b, pos = 0, ans = 0;
    for (int i = 0; i < k; ++i) {
        // cout << "i = " << i << ' ' << pos << ' ' << cur <<endl;
        if (pos == 0) {
            if (cur < f) return cout << "-1" << endl, 0;
            if (cur < a) {
                ++ans; cur = b;
                pos = a;
                cur -= a - f;
                if (cur < 0) return cout << "-1" << endl, 0; 
                continue;
            }
            if (i != k - 1 && cur < a + a - f) {
                ++ans; cur = b;
                pos = a;
                cur -= a - f;
                if (cur < 0) return cout << "-1" << endl, 0;
                continue;
            }
            pos = a; cur -= a;
        } else {
            if (cur < a - f) return cout << "-1" << endl, 0;
            if (cur < a) {
                ++ans, cur = b;
                pos = 0;
                cur -= f;
                if (cur < 0) return cout << "-1" << endl, 0;
                continue;
            }
            if (i != k - 1 && cur < a + f) {
                ++ans; cur = b;
                pos = 0;
                cur -= f;
                if (cur < 0) return cout << "-1" << endl, 0;
                continue;
            }
            pos = 0; cur -= a;
        }
    }
    cout << ans << endl;
    return 0;
}