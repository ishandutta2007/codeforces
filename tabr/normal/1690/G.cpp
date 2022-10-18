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
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        set<int> st;
        st.emplace(0);
        for (int i = 1; i < n; i++) {
            if (a[*st.rbegin()] > a[i]) {
                st.emplace(i);
            }
        }
        while (m--) {
            int k, d;
            cin >> k >> d;
            k--;
            a[k] -= d;
            if (k != 0 && !st.count(k) && a[*prev(st.lower_bound(k))] > a[k]) {
                st.emplace(k);
            }
            while (true) {
                auto iter = st.upper_bound(k);
                if (iter == st.end()) {
                    break;
                } else if (a[k] <= a[*iter]) {
                    st.erase(iter);
                } else {
                    break;
                }
            }
            cout << st.size() << " \n"[m == 0];
        }
    }
    return 0;
}