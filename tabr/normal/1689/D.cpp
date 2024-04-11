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
        int h, w;
        cin >> h >> w;
        set<int> x, y;
        for (int i = 0; i < h; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < w; j++) {
                if (s[j] == 'B') {
                    x.emplace(i + j);
                    y.emplace(i - j);
                }
            }
        }
        int s = 0, t = 0;
        int best = (int) 1e9;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                int z = 0;
                z = max(z, abs(*x.rbegin() - (i + j)));
                z = max(z, abs(*x.begin() - (i + j)));
                z = max(z, abs(*y.rbegin() - (i - j)));
                z = max(z, abs(*y.begin() - (i - j)));
                if (best > z) {
                    best = z;
                    s = i + 1;
                    t = j + 1;
                }
            }
        }
        cout << s << " " << t << '\n';
    }
    return 0;
}