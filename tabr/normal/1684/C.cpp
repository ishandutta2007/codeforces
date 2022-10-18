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
        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
        auto d = a;
        set<int> st;
        for (int i = 0; i < n; i++) {
            sort(d[i].begin(), d[i].end());
            for (int j = 0; j < m; j++) {
                if (a[i][j] != d[i][j]) {
                    st.emplace(j);
                }
            }
        }
        if (st.size() > 10) {
            cout << -1 << '\n';
        } else if (st.empty()) {
            cout << 1 << " " << 1 << '\n';
        } else {
            vector<int> b(st.begin(), st.end());
            int sz = (int) b.size();
            int x = -1, y = -1;
            for (int i = 0; i < sz; i++) {
                for (int j = i + 1; j < sz; j++) {
                    auto c = a;
                    for (int k = 0; k < n; k++) {
                        swap(c[k][b[i]], c[k][b[j]]);
                    }
                    bool ok = true;
                    for (int ii = 0; ii < n; ii++) {
                        for (int jj = 0; jj < m - 1; jj++) {
                            if (c[ii][jj] > c[ii][jj + 1]) {
                                ok = false;
                                break;
                            }
                        }
                    }
                    if (ok) {
                        x = b[i];
                        y = b[j];
                    }
                }
            }
            if (x == -1) {
                cout << -1 << '\n';
            } else {
                cout << x + 1 << " " << y + 1 << '\n';
            }
        }
    }
    return 0;
}