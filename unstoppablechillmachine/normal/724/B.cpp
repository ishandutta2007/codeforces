#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<int> cnt(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] != j + 1) {
                cnt[i]++;
            }
        }
    }
    auto upd = [&](int row, int col1, int col2) {
        if (a[row][col1] != col1 + 1) {
            cnt[row]--;
        }
        if (a[row][col2] != col2 + 1) {
            cnt[row]--;
        }
        swap(a[row][col1], a[row][col2]);
        if (a[row][col1] != col1 + 1) {
            cnt[row]++;
        }
        if (a[row][col2] != col2 + 1) {
            cnt[row]++;
        }
    };
    bool can = false;
    for (int col1 = 0; col1 < m; col1++) {
        for (int col2 = col1; col2 < m; col2++) {
            bool ok = true;
            for (int row = 0; row < n; row++) {
                bool can_row = false;
                for (int col3 = 0; col3 < m; col3++) {
                    for (int col4 = col3; col4 < m; col4++) {
                        upd(row, col3, col4);
                        upd(row, col1, col2);
                        if (!cnt[row]) {
                            can_row = true;
                        }
                        upd(row, col1, col2);
                        upd(row, col3, col4);
                        upd(row, col1, col2);
                        upd(row, col3, col4);
                        if (!cnt[row]) {
                            can_row = true;
                        }
                        upd(row, col3, col4);
                        upd(row, col1, col2);
                    }
                }
                if (!can_row) {
                    ok = false;
                }
            }
            if (ok) {
                can = true;
            }
        }
    }
    cout << (can ? "YES\n" : "NO\n");
}