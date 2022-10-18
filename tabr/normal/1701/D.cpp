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
        vector<int> l(n), r(n);
        for (int i = 0; i < n; i++) {
            l[i] = (i + 1) / (b[i] + 1) + 1;
            r[i] = (b[i] == 0 ? n : (i + 1) / b[i]);
        }
        debug(l, r);
        set<pair<int, int>> st;
        vector<vector<int>> at(n + 1);
        for (int i = 0; i < n; i++) {
            at[l[i]].emplace_back(i);
        }
        vector<int> ans(n);
        for (int i = 1; i <= n; i++) {
            for (int j : at[i]) {
                st.emplace(r[j], j + 1);
            }
            int a = st.begin()->second;
            st.erase(st.begin());
            ans[a - 1] = i;
        }
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " \n"[i == n - 1];
        }
    }
    return 0;
}