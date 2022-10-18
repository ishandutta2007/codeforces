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
        vector<vector<int>> a(n);
        vector<int> deg(n);
        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;
            for (int j = 0; j < k; j++) {
                int b;
                cin >> b;
                b--;
                a[b].emplace_back(i);
                deg[i]++;
            }
        }
        set<int> st;
        for (int i = 0; i < n; i++) {
            if (deg[i] == 0) {
                deg[i] = -1;
                st.emplace(i);
            }
        }
        int ans = 0;
        while (!st.empty()) {
            ans++;
            set<int> new_st;
            while (!st.empty()) {
                int i = *st.begin();
                st.erase(i);
                for (int j : a[i]) {
                    deg[j]--;
                    if (deg[j] == 0) {
                        deg[j] = -1;
                        if (i < j) {
                            st.emplace(j);
                        } else {
                            new_st.emplace(j);
                        }
                    }
                }
            }
            swap(st, new_st);
        }
        if (deg != vector<int>(n, -1)) {
            ans = -1;
        }
        cout << ans << '\n';
    }
    return 0;
}