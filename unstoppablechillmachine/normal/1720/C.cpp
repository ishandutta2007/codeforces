#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef PC
    freopen("input.txt", "r", stdin);
#endif
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> a(n, vector<char>(m));
        bool have_zeros = false, have_adj_zeros = false;
        int cnt_ones = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
                if (a[i][j] == '0') {
                    have_zeros = true;
                } else {
                    cnt_ones++;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == '0') {
                    if (i + 1 < n && a[i + 1][j] == '0') {
                        have_adj_zeros = true;
                    }
                    if (j + 1 < m && a[i][j + 1] == '0') {
                        have_adj_zeros = true;
                    }
                    if (i + 1 < n && j + 1 < m && a[i + 1][j + 1] == '0') {
                        have_adj_zeros = true;
                    }
                    if (i + 1 < n && j > 0 && a[i + 1][j - 1] == '0') {
                        have_adj_zeros = true;
                    }
                }
            }
        }
        if (have_adj_zeros) {
            cout << cnt_ones << '\n';
        } else if (have_zeros) {
            cout << cnt_ones - 1 << '\n';
        } else {
            cout << cnt_ones - 2 << '\n';
        }
    }
    return 0;
}