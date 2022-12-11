#include <bits/stdc++.h>
//#define int long long

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    char ans1[n][m], ans2[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int t = (i + j) & 1;
            if (t == 0) {
                ans1[i][j] = 'R';
                ans2[i][j] = 'W';
            } else {
                ans1[i][j] = 'W';
                ans2[i][j] = 'R';
            }
        }
    }
    bool sim_1 = 1, sim_2 = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char x;
            cin >> x;
            if (x == '.')
                continue;
            if (x != ans1[i][j])
                sim_1 = 0;
            if (x != ans2[i][j])
                sim_2 = 0;
        }
    }
    if (!sim_1 && !sim_2) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    if (sim_1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << ans1[i][j];
            }
            cout << "\n";
        }
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << ans2[i][j];
            }
            cout << "\n";
        }
    }
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}