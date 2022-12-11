#include <bits/stdc++.h>
//#define int long long

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    int b[n][m];
    int beg[n][m];
    vector <pair <int, pair <int, int>>> lengths;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> b[i][j];
            lengths.push_back({b[i][j], {i, j}});
            beg[i][j] = -1;
        }
    }
    sort(lengths.begin(), lengths.end());
    for (int i = 0; i < m; i++) {
        auto [x, y] = lengths[i].second;
        beg[x][y] = i;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            bool has = 0;
            for (int t = 0; t < m; t++) {
                if (beg[i][t] == j) {
                    has = 1;
                    break;
                }
            }
            if (has)
                continue;

            for (int t = 0; t < m; t++) {
                if (beg[i][t] == -1) {
                    beg[i][t] = j;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int cur = -1;
            for (int t = 0; t < m; t++) {
                if (beg[i][t] == j) {
                    cur = b[i][t];
                    break;
                }
            }
            assert(cur != -1);
            cout << cur << ' ';
        }
        cout << "\n";
    }
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        solve();
    return 0;
}