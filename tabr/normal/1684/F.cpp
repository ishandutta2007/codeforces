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
        vector<int> b(n);
        iota(b.begin(), b.end(), 0);
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            b[x] = max(b[x], y);
        }
        for (int i = 1; i < n; i++) {
            b[i] = max(b[i], b[i - 1]);
        }
        map<int, int> pos;
        for (int i = 0; i < n; i++) {
            pos[a[i]] = -1;
        }
        vector<pair<int, int>> t;
        for (int i = 0; i < n; i++) {
            if (pos[a[i]] != -1) {
                int j = pos[a[i]];
                if (b[j] >= i) {
                    t.emplace_back(j, i);
                }
            }
            pos[a[i]] = i;
        }
        map<int, vector<int>> d;
        for (int i = 0; i < n; i++) {
            d[a[i]].emplace_back(i);
        }
        for (int i = 0; i < n; i++) {
            int j = *prev(upper_bound(d[a[i]].begin(), d[a[i]].end(), b[i]));
            debug(i, j);
            if (i < j) {
                t.emplace_back(i, j);
            }
        }
        multiset<int> st;
        int sz = (int) t.size();
        sort(t.begin(), t.end());
        for (int i = 0; i < sz; i++) {
            st.emplace(t[i].first);
        }
        int ans = 0;
        if (sz) {
            ans = *st.rbegin() - *st.begin() + 1;
        }
        for (int i = 0; i < sz; i++) {
            st.erase(st.find(t[i].first));
            st.emplace(t[i].second);
            ans = min(ans, *st.rbegin() - *st.begin() + 1);
        }
        cout << ans << '\n';
    }
    return 0;
}