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
        int h, w, x, y;
        cin >> h >> w >> x >> y;
        x--, y--;
        vector<string> s(h);
        for (int i = 0; i < h; i++) {
            cin >> s[i];
        }
        if (all_of(s.begin(), s.end(), [&](string t) { return (t == string(w, 'W')); })) {
            cout << -1 << '\n';
            continue;
        }
        if (s[x][y] == 'B') {
            cout << 0 << '\n';
        } else if (count(s[x].begin(), s[x].end(), 'B')) {
            cout << 1 << '\n';
        } else if (any_of(s.begin(), s.end(), [&](string t) { return (t[y] == 'B'); })) {
            cout << 1 << '\n';
        } else {
            cout << 2 << '\n';
        }
    }
    return 0;
}