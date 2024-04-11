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
    int n, q;
    cin >> n >> q;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    sort(p.begin(), p.end());
    set<int> st;
    multiset<int> d;
    for (int i = 0; i < n - 1; i++) {
        d.emplace(p[i + 1] - p[i]);
    }
    for (int i = 0; i < n; i++) {
        st.emplace(p[i]);
    }
    if (d.empty()) {
        cout << 0 << '\n';
    } else {
        cout << *st.rbegin() - *st.begin() - *d.rbegin() << '\n';
    }
    while (q--) {
        int t, x;
        cin >> t >> x;
        if (t == 0) {
            auto it = st.find(x);
            if (it != st.begin()) {
                auto jt = prev(st.find(x));
                d.erase(d.find(*it - *jt));
            }
            if (next(it) != st.end()) {
                auto jt = next(st.find(x));
                d.erase(d.find(*jt - *it));
            }
            if (it != st.begin() && next(it) != st.end()) {
                auto jt = prev(st.find(x));
                auto kt = next(st.find(x));
                d.emplace(*kt - *jt);
            }
            st.erase(x);
        } else {
            st.emplace(x);
            auto it = st.find(x);
            if (it != st.begin()) {
                auto jt = prev(st.find(x));
                d.emplace(*it - *jt);
            }
            if (next(it) != st.end()) {
                auto jt = next(st.find(x));
                d.emplace(*jt - *it);
            }
            if (it != st.begin() && next(it) != st.end()) {
                auto jt = prev(st.find(x));
                auto kt = next(st.find(x));
                d.erase(d.find(*kt - *jt));
            }
        }
        if (d.empty()) {
            cout << 0 << '\n';
            continue;
        }
        int ans = *st.rbegin() - *st.begin() - *d.rbegin();
        cout << ans << '\n';
    }
    return 0;
}