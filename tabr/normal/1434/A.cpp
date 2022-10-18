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
    int m = 6;
    vector<int> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    int n;
    cin >> n;
    vector<int> b(n);
    vector<vector<int>> c(n, vector<int>(m));
    sort(a.rbegin(), a.rend());
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    sort(b.begin(), b.end());
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            c[i][j] = b[i] - a[j];
        }
    }
    vector<int> st;
    debug(c);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (c[i][j] <= c[0][5]) {
                st.emplace_back(c[i][j]);
            }
        }
    }
    sort(st.begin(), st.end());
    st.resize(unique(st.begin(), st.end()) - st.begin());
    int ans = (int)1e9;
    st.emplace_back(ans);
    vector<int> t = st;
    for (int i = 0; i < n; i++) {
        t[0] = c[i][0];
        c[i].emplace_back(ans);
        for (int j = 0; j < m; j++) {
            int k = upper_bound(st.begin(), st.end(), c[i][j]) - st.begin();
            t[k] = max(t[k], c[i][j + 1]);
        }
    }
    ans = t[0] - st[0];
    for (int i = 1; i < (int)t.size() - 1; i++) {
        t[i] = max(t[i], t[i - 1]);
        ans = min(ans, t[i] - st[i]);
    }
    cout << ans << '\n';
    return 0;
}