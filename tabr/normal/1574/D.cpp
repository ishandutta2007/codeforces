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
    int n;
    cin >> n;
    vector<vector<int>> a(n);
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        vector<int> b(c);
        for (int j = 0; j < c; j++) {
            cin >> b[j];
        }
        swap(a[i], b);
    }
    int m;
    cin >> m;
    set<vector<int>> st;
    for (int i = 0; i < m; i++) {
        vector<int> b(n);
        for (int j = 0; j < n; j++) {
            cin >> b[j];
        }
        st.emplace(b);
    }
    vector<vector<int>> c;
    c.emplace_back(vector<int>(n + 1));
    for (int i = 0; i < n; i++) {
        int lo = 0;
        int hi = (int) 1e9 + 10;
        while (hi - lo > 1) {
            int mid = (hi + lo) / 2;
            long long cnt = 0;
            for (int j = 0; j < (int) c.size(); j++) {
                int d = mid + c[j][0];
                cnt += (int) (a[i].end() - lower_bound(a[i].begin(), a[i].end(), d));
            }
            if (cnt >= m + 1) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
        vector<vector<int>> new_c;
        for (auto v : c) {
            auto u = v;
            for (int j = (int) a[i].size() - 1; j >= 0; j--) {
                u[0] = v[0] - a[i][j];
                if (u[0] > -lo) {
                    break;
                }
                u[i + 1] = 1 + j;
                new_c.emplace_back(u);
            }
        }
        sort(new_c.begin(), new_c.end());
        if ((int) new_c.size() > m + 1) {
            new_c.resize(m + 1);
        }
        swap(c, new_c);
    }
    for (auto v : c) {
        vector<int> u = v;
        u.erase(u.begin());
        if (!st.count(u)) {
            for (int i = 0; i < n; i++) {
                cout << u[i] << " ";
            }
            cout << '\n';
            return 0;
        }
    }
    assert(false);
    return 0;
}