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
        int n, q;
        cin >> n >> q;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        set<long long> st;
        auto solve = [&](auto &&self, const vector<long long> &x) -> void {
            if (x.empty()) {
                return;
            }
            st.emplace(accumulate(x.begin(), x.end(), 0LL));
            long long mx = *max_element(x.begin(), x.end());
            long long mn = *min_element(x.begin(), x.end());
            if (mx == mn) {
                return;
            }
            long long mid = (mx + mn) / 2;
            vector<long long> l, r;
            for (auto i : x) {
                if (i <= mid) {
                    l.emplace_back(i);
                } else {
                    r.emplace_back(i);
                }
            }
            self(self, l);
            self(self, r);
        };
        solve(solve, a);
        while (q--) {
            int s;
            cin >> s;
            if (st.count(s)) {
                cout << "Yes" << '\n';
            } else {
                cout << "No" << '\n';
            }
        }
    }
    return 0;
}