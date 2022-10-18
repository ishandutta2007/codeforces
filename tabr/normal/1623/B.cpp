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
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].first >> a[i].second;
            a[i].first--, a[i].second--;
        }
        sort(a.begin(), a.end(), [&](auto x, auto y) { return (x.second - x.first) < (y.second - y.first); });
        set<int> st;
        for (int i = 0; i < n; i++) {
            st.emplace(i);
        }
        for (auto [x, y] : a) {
            auto r = st.upper_bound(y);
            auto l = st.lower_bound(x);
            assert(l != r);
            cout << x + 1 << " " << y + 1 << " " << (*l) + 1 << '\n';
            st.erase(l);
        }
        cout << '\n';
    }
    return 0;
}