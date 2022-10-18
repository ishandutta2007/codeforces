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
        string ans;
        int now = 100;
        for (int i = 14; i < 1000; i += 7) {
            string t = to_string(i);
            if (s.size() == t.size()) {
                int k = 0;
                for (int j = 0; j < (int) s.size(); j++) {
                    if (s[j] != t[j]) {
                        k++;
                    }
                }
                if (now > k) {
                    now = k;
                    ans = t;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}