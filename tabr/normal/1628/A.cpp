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
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> b(n);
        set<int> st;
        for (int i = 0; i <= n + 1; i++) {
            st.emplace(i);
        }
        for (int i = n - 1; i >= 0; i--) {
            st.erase(a[i]);
            b[i] = *st.begin();
        }
        vector<int> ans;
        int beg = 0;
        while (beg < n) {
            ans.emplace_back(b[beg]);
            st.clear();
            for (int i = 0; i < b[beg]; i++) {
                st.emplace(i);
            }
            int end = beg;
            while (end < n && !st.empty()) {
                st.erase(a[end]);
                end++;
            }
            beg = max(beg + 1, end);
        }
        cout << ans.size() << '\n';
        for (int i = 0; i < (int) ans.size(); i++) {
            cout << ans[i] << " \n"[i == (int) ans.size() - 1];
        }
    }
    return 0;
}