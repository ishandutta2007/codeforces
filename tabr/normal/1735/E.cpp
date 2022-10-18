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
        vector<vector<long long>> d(2, vector<long long>(n));
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                cin >> d[i][j];
            }
            sort(d[i].begin(), d[i].end());
        }
        vector<long long> x(n), y(n);
        for (int i = 0; i < n; i++) {
            x[i] = abs(d[0][i] + d[1][i]);
            y[i] = abs(d[0][i] - d[1][i]);
        }
        vector<long long> qs;
        for (int i = 0; i < n; i++) {
            qs.emplace_back(d[0][0] + d[1][i]);
            qs.emplace_back(abs(d[0][0] - d[1][i]));
        }
        sort(qs.begin(), qs.end());
        qs.resize(unique(qs.begin(), qs.end()) - qs.begin());
        long long p1 = 0, p2;
        vector<long long> h;
        for (auto q : qs) {
            p2 = q;
            multiset<long long> st(d[1].begin(), d[1].end());
            for (int i = n - 1; i >= 0; i--) {
                if (st.count(d[0][i] + q)) {
                    h.emplace_back(-d[0][i]);
                    st.erase(st.find(d[0][i] + q));
                } else if (st.count(abs(d[0][i] - q))) {
                    h.emplace_back(d[0][i]);
                    st.erase(st.find(abs(d[0][i] - q)));
                } else {
                    h.clear();
                    break;
                }
            }
            if (!h.empty()) {
                break;
            }
        }
        if (h.empty()) {
            cout << "NO" << '\n';
        } else {
            cout << "YES" << '\n';
            long long mn = *min_element(h.begin(), h.end());
            mn = min(mn, 0LL);
            for (int i = 0; i < n; i++) {
                cout << h[i] - mn << " \n"[i == n - 1];
            }
            cout << p1 - mn << " " << p2 - mn << '\n';
        }
    }
    return 0;
}