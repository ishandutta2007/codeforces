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
        vector<string> s(n);
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }
        set<string> st;
        for (int i = 0; i < n; i++) {
            st.emplace(s[i]);
        }
        string ans(n, '0');
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < (int) s[i].size(); j++) {
                if (st.count(s[i].substr(0, j)) && st.count(s[i].substr(j))) {
                    ans[i] = '1';
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}