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
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.rbegin(), a.rend());
        a.resize(m);
        reverse(a.begin(), a.end());
        vector<vector<long long>> b(m);
        vector<pair<long long, int>> c(m);
        for (int i = 0; i < m; i++) {
            int k;
            cin >> k;
            b[i] = vector<long long>(k);
            for (int j = 0; j < k; j++) {
                cin >> b[i][j];
                c[i].first += b[i][j];
            }
            c[i].first = (c[i].first + k - 1) / k;
            c[i].second = i;
        }
        sort(c.begin(), c.end());
        vector<string> ans(m);
        int ng = -1;
        long long ang = -1;
        for (int i = 0; i < m; i++) {
            if (c[i].first > a[i]) {
                ng = i;
                ang = a[i];
                a.erase(a.begin() + i);
                break;
            }
        }
        vector<int> ok(m, 1);
        if (ng != -1) {
            for (int i = 0; i < ng; i++) {
                ok[c[i].second] = 0;
            }
            for (int i = ng; i < m - 1; i++) {
                if (c[i].first > a[i]) {
                    for (int j = i + 1; j < m; j++) {
                        ok[c[j].second] = 0;
                    }
                    break;
                }
            }
        }
        multiset<long long> st;
        for (auto x : a) {
            st.emplace(x);
        }
        reverse(c.begin(), c.end());
        for (auto [z, i] : c) {
            long long t;
            if (ng != -1) {
                t = ang;
                if (!ok[i]) {
                    continue;
                }
            } else {
                t = *st.rbegin();
            }
            long long s = accumulate(b[i].begin(), b[i].end(), 0LL);
            int k = (int) b[i].size();
            for (int j = 0; j < k; j++) {
                if (s - b[i][j] <= t * (k - 1)) {
                    ans[i] += "1";
                } else {
                    ans[i] += "0";
                }
            }
            auto it = st.lower_bound(z);
            if (it == st.end()) {
                break;
            }
            st.erase(it);
        }
        for (int i = 0; i < m; i++) {
            if (ans[i].empty()) {
                ans[i] = string(b[i].size(), '0');
            }
            cout << ans[i];
        }
        cout << '\n';
    }
    return 0;
}