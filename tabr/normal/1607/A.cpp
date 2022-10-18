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
        string s, t;
        cin >> s >> t;
        vector<int> a;
        for (int i = 0; i < (int) t.size(); i++) {
            for (int j = 0; j < 26; j++) {
                if (t[i] == s[j]) {
                    a.emplace_back(j);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < (int) a.size() - 1; i++) {
            ans += abs(a[i + 1] - a[i]);
        }
        cout << ans << '\n';
    }
    return 0;
}