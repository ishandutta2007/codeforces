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
        int p;
        cin >> p;
        vector<int> c(26);
        for (int i = 0; i < (int) s.size(); i++) {
            c[s[i] - 'a']++;
        }
        int q = 0;
        for (int i = 0; i < 26; i++) {
            q += (i + 1) * c[i];
        }
        while (p < q) {
            for (int i = 25; i >= 0; i--) {
                if (c[i] > 0) {
                    c[i]--;
                    q -= i + 1;
                    break;
                }
            }
        }
        string ans;
        for (int i = 0; i < (int) s.size(); i++) {
            if (c[s[i] - 'a'] > 0) {
                c[s[i] - 'a']--;
                ans += s[i];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}