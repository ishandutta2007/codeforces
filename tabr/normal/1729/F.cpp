#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        string s;
        cin >> s;
        int w, m;
        cin >> w >> m;
        int n = (int) s.size();
        vector<int> pref(n + 1);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + (s[i] - '0');
        }
        vector a(9, vector < pair < int, int >> (9, make_pair(n + 1, n + 1)));
        vector <vector<int>> b(9);
        for (int i = 0; i <= n - w; i++) {
            b[(pref[i + w] - pref[i]) % 9].emplace_back(i + 1);
        }
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (i == j) {
                    continue;
                }
                if (b[i].empty() || b[j].empty()) {
                    continue;
                }
                for (int v = 0; v < 9; v++) {
                    int k = (i * v + j) % 9;
                    a[v][k] = min(a[v][k], make_pair(b[i][0], b[j][0]));
                }
            }
            if (b[i].size() > 1) {
                for (int v = 0; v < 9; v++) {
                    int k = (i * v + i) % 9;
                    a[v][k] = min(a[v][k], make_pair(b[i][0], b[i][1]));
                }
            }
        }
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (a[i][j].first == n + 1) {
                    a[i][j].first = a[i][j].second = -1;
                }
            }
        }
        while (m--) {
            int l, r, k;
            cin >> l >> r >> k;
            int v = (pref[r] - pref[l - 1]) % 9;
            cout << a[v][k].first << " " << a[v][k].second << "\n";
        }
    }
    return 0;
}