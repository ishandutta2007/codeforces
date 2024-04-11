#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, d, h; cin >> n >> d >> h;
    if (h == d) {
        if (h >= 2) {
            for (int i = 2; i <= h + 1; ++i) cout << i - 1 << ' ' << i << endl;
            for (int i = h + 2; i <= n; ++i) cout << 2 << ' ' << i << endl;
            return 0;
        }
        if (n == 2) return cout << "1 2" << endl, 0;
        cout << "-1" << endl;
    } else {
        if (d > 2 * h) return cout << "-1" << endl, 0;
        for (int i = 2; i <= h + 1; ++i) cout << i - 1 << ' ' << i << endl;
        int now = h + 2, last = 1;
        for (int i = 0; i < d - h; ++i) {
            cout << last << ' ' << now << endl;
            last = now; ++now;
        }
        while (now <= n) cout << 1 << ' ' << now << endl, ++now;
    }
    return 0;
}