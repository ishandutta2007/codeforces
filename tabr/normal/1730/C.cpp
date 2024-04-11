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
        cin >> s;
        int n = (int) s.size();
        char c = '9';
        vector<int> d(10);
        for (int i = n - 1; i >= 0; i--) {
            if (c < s[i]) {
                d[min(9, s[i] - '0' + 1)]++;
            } else {
                d[s[i] - '0']++;
                c = min(c, s[i]);
            }
        }
        for (int i = 0; i < 10; i++) {
            cout << string(d[i], (char) ('0' + i));
        }
        cout << '\n';
    }
    return 0;
}