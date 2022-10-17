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
        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
        pair<int, int> sw = {-1, -1};
        bool bad = false;
        for (int i = 0; i < n; i++) {
            int mx = 0, pos = 0;
            for (int j = 0; j < m; j++) {
                if (a[i][j] < mx) {
                    pos = j;
                }
                mx = max(mx, a[i][j]);
            }
            if (pos != 0) {
                int pos2 = 0;
                for (int j = 0; j < pos; j++) {
                    if (a[i][pos] < a[i][j]) {
                        pos2 = j;
                        break;
                    }
                }
                if (sw.first == -1) {
                    sw = {pos2, pos};
                } else if (sw.first != pos2 || sw.second != pos) {
                    bad = true;
                }
            }
        }
        if (bad) {
            cout << -1 << '\n';
            continue;
        }
        if (sw.first == -1) {
            cout << 1 << ' ' << 1 << '\n';
            continue;
        }
        for (int i = 0; i < n; i++) {
            swap(a[i][sw.first], a[i][sw.second]);
            if (!is_sorted(a[i].begin(), a[i].end())) {
                bad = true;
            }
        }
        if (bad) {
            cout << -1 << '\n';
        } else {
            cout << sw.first + 1 << ' ' << sw.second + 1 << '\n';
        }
    }
    return 0;
}