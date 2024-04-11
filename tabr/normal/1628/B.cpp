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
        string ans = "NO";
        for (int i = 0; i < n; i++) {
            if (s[i] == string(s[i].rbegin(), s[i].rend())) {
                ans = "YES";
            }
        }
        if (ans == "NO") {
            set<string> st;
            for (int i = 0; i < n; i++) {
                if (st.count(s[i])) {
                    ans = "YES";
                    break;
                }
                reverse(s[i].begin(), s[i].end());
                if (s[i].size() == 2) {
                    st.emplace(s[i]);
                    for (char c = 'a'; c <= 'z'; c++) {
                        st.emplace(c + s[i]);
                    }
                } else {
                    st.emplace(s[i]);
                    s[i].erase(s[i].begin());
                    st.emplace(s[i]);
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}