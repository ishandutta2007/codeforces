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
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        set<int> st;
        int last = b[0];
        st.emplace(b[0]);
        st.emplace((int) 2e9);
        st.emplace((int) -2e9);
        string ans = "YES";
        for (int i = 1; i < n; i++) {
            if (b[i] < last) {
                if (*st.upper_bound(b[i]) < last) {
                    ans = "NO";
                    break;
                }
            } else if (last < b[i]) {
                if (*st.upper_bound(last) < b[i]) {
                    ans = "NO";
                    break;
                }
            }
            st.emplace(b[i]);
            last = b[i];
        }
        cout << ans << '\n';
    }
    return 0;
}