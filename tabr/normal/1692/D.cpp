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
        string s;
        int x;
        cin >> s >> x;
        int t = stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2));
        int orig_t = t;
        int ans = 0;
        do {
            int h = t / 60;
            int m = t % 60;
            if (h / 10 == m % 10 && h % 10 == m / 10) {
                ans++;
            }
            t += x;
            t %= 24 * 60;
        } while (t != orig_t);
        cout << ans << '\n';
    }
    return 0;
}