#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> p(n), q(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }
    for (int i = 0; i < n; i++) {
        cin >> q[i];
        q[i]--;
    }
    set<int> st;
    vector<int> c;
    for (int i = 0; i < n; i++) {
        if (st.count(p[i])) {
            st.erase(p[i]);
        } else {
            st.emplace(p[i]);
        }
        if (st.count(q[i])) {
            st.erase(q[i]);
        } else {
            st.emplace(q[i]);
        }
        if (st.empty()) {
            c.emplace_back(i);
        }
    }
    if (c.size() < k) {
        cout << "NO" << '\n';
        return 0;
    }
    cout << "YES" << '\n';
    string ans(n, ' ');
    int l = 0;
    for (int i = 0; i < c.size(); i++) {
        for (int r = c[i]; l <= r; l++) {
            ans[p[l]] = 'a' + min(i, k - 1);
        }
        l = c[i] + 1;
    }
    cout << ans << '\n';
    return 0;
}