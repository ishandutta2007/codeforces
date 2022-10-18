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
        vector<vector<int>> b(n, vector<int>(m));
        vector<int> c(n * m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> b[i][j];
                c[i * m + j] = b[i][j];
            }
            sort(b[i].begin(), b[i].end());
        }
        sort(c.begin(), c.end());
        c.resize(m);
        multiset<int> st(c.begin(), c.end());
        debug(st);
        int t = 0;
        for (int i = 0; i < n; i++) {
            rotate(b[i].rbegin(), b[i].rbegin() + t, b[i].rend());
            for (int j = 0; j < m; j++) {
                cout << b[i][j] << " ";
            }
            cout << '\n';
            sort(b[i].begin(), b[i].end());
            for (int j = 0; j < m; j++) {
                if (st.count(b[i][j])) {
                    t++;
                    st.erase(st.lower_bound(b[i][j]));
                } else {
                    break;
                }
            }
        }
    }
    return 0;
}