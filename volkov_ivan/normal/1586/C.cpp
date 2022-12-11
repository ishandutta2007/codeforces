#include <bits/stdc++.h>
//#define int long long

using namespace std;

signed main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("Desktop/input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    vector <vector <char>> f(n + 1, vector<char>(m + 1));
    vector <vector <int>> c(n + 1, vector<int>(m + 1, m + 1));
    vector <int> pref_c(m + 2, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> f[i][j];
            if (i == 1 || j == 1) {
                c[i][j] = -1;
            } else {
                c[i][j] = j;
                if (f[i][j - 1] == '.')
                    c[i][j] = c[i][j - 1];
                    //ok[i][j] = (ok[i][j] | ok[i][j - 1]);
                if (f[i - 1][j] == '.' && c[i - 1][j] < c[i][j])
                    c[i][j] = c[i - 1][j];
                    //ok[i][j] = (ok[i][j] | ok[i - 1][j]);
            }
        }
    }
    for (int j = 1; j <= m; j++) {
        pref_c[j] = pref_c[j - 1];
        for (int i = 1; i <= n; i++) {
            pref_c[j] = max(pref_c[j], c[i][j]);
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        // cout << good[l] << ' ' << lst_bad[l] << endl;
        cout << (pref_c[r] <= l ? "YES" : "NO") << "\n";
    }
}