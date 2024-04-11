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
        auto ask = [&](int x, int y, int z) {
            cout << "? " << x + 1 << " " << y + 1 << " " << z + 1 << endl;
            int w;
            cin >> w;
            return w;
        };
        int n;
        cin >> n;
        int a012 = ask(0, 1, 2);
        int a013 = ask(0, 1, 3);
        int a023 = ask(0, 2, 3);
        int a123 = ask(1, 2, 3);
        int mx = max({a012, a013, a023, a123});
        vector<int> ng(4);
        int cnt = 0;
        if (mx == a012 && cnt < 2) {
            ng[3] = 1;
            cnt++;
        }
        if (mx == a013 && cnt < 2) {
            ng[2] = 1;
            cnt++;
        }
        if (mx == a023 && cnt < 2) {
            ng[1] = 1;
            cnt++;
        }
        if (mx == a123 && cnt < 2) {
            ng[0] = 1;
            cnt++;
        }
        int big = -1;
        int small = -1;
        for (int i = 0; i < 4; i++) {
            if (!ng[i]) {
                if (big == -1) {
                    big = i;
                } else {
                    small = i;
                    break;
                }
            }
        }
        assert(small != -1);
        int mid = 0;
        while (mid == small || mid == big) {
            mid++;
        }
        for (int i = 4; i < n; i++) {
            int k0 = ask(big, mid, i);
            int k1 = ask(small, mid, i);
            if (k0 > mx && k1 <= mx) {
                mx = k0;
                small = i;
            } else if (k1 > mx && k0 <= mx) {
                mx = k1;
                big = i;
            } else if (min(k0, k1) > mx) {
                if (k0 > k1) {
                    mx = k0;
                    small = i;
                } else {
                    mx = k1;
                    big = i;
                }
            }
        }
        cout << "! " << big + 1 << " " << small + 1 << endl;
    }
    return 0;
}