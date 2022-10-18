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
        set<char> st;
        int ans = 0;
        for (int i = 0; i < (int) s.size(); i++) {
            st.emplace(s[i]);
            if (st.size() == 4) {
                st.clear();
                st.emplace(s[i]);
                ans++;
            }
        }
        if (st.size()) {
            ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}