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
    auto ask = [&](int a, int bl, int br) {
        cout << "? " << 1 << " " << br - bl + 1 << endl;
        cout << a + 1 << endl;
        for (int i = bl + 1; i <= br + 1; i++) {
            cout << i << " ";
        }
        cout << endl;
        int x;
        cin >> x;
        return x;
    };
    while (tt--) {
        int n;
        cin >> n;
        int c = -1;
        vector<int> ans;
        int d = -1;
        for (int i = 0; i < n - 1; i++) {
            if (c == -1) {
                int x = ask(i, i + 1, n - 1);
                if (x) {
                    c = i;
                    d = x;
                }
            } else {
                int x = ask(c, i, i);
                d -= x;
                if (!x) {
                    ans.emplace_back(i);
                }
            }
        }
        debug(d);
        if (!d) {
            ans.emplace_back(n - 1);
        }
        if (c) {
            int lo = -1, hi = c;
            while (hi - lo > 1) {
                int mid = (hi + lo) / 2;
                if (ask(c, mid, c - 1)) {
                    lo = mid;
                } else {
                    hi = mid;
                }
            }
            debug(lo, hi);
            for (int i = 0; i < c; i++) {
                if (i != lo) {
                    ans.emplace_back(i);
                }
            }
        }
        cout << "! " << ans.size() << " ";
        for (int i : ans) {
            cout << i + 1 << " ";
        }
        cout << endl;
    }
    return 0;
}