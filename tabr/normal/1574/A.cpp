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
        set<string> s;
        int m = n;
        if (n >= 8) {
            m = 8;
        }
        for (int mask = 0; mask < (1 << (2 * m)); mask++) {
            if (__builtin_popcount(mask) != m) {
                continue;
            }
            string t;
            int d = 0;
            for (int i = 0; i < 2 * m; i++) {
                if (mask & (1 << i)) {
                    t += "(";
                    d++;
                } else {
                    t += ")";
                    d--;
                }
                if (d < 0) {
                    t.clear();
                    break;
                }
            }
            if (t.empty()) {
                continue;
            }
            s.emplace(t);
        }
        debug(s.size());
        int c = n;
        while (c--) {
            cout << *s.begin();
            for (int i = 0; i < n - m; i++) {
                cout << "()";
            }
            cout << '\n';
            s.erase(s.begin());
        }
    }
    return 0;
}