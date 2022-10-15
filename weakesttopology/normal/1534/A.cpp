#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    map<char, int> mp = {{'R', 0}, {'W', 1}};
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        for (int j = 1; j < m; ++j) {
            if (s[i][j] == '.' && s[i][j - 1] != '.') {
                s[i][j] = (s[i][j - 1] == 'W') ? 'R' : 'W';
            }
        }
        for (int j = m - 2; j >= 0; --j) {
            if (s[i][j] == '.' && s[i][j + 1] != '.') {
                s[i][j] = (s[i][j + 1] == 'W') ? 'R' : 'W';
            }
        }
    }
    for (int j = 0; j < m; ++j) {
        for (int i = 1; i < n; ++i) {
            if (s[i][j] == '.' && s[i - 1][j] != '.') {
                s[i][j] = (s[i - 1][j] == 'W') ? 'R' : 'W';
            }
        }
        for (int i = n - 2; i >= 0; --i) {
            if (s[i][j] == '.' && s[i + 1][j] != '.') {
                s[i][j] = (s[i + 1][j] == 'W') ? 'R' : 'W';
            }
        }
    }
    if (s[0][0] == '.') {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                s[i][j] = "RW"[(i + j) % 2];
            }
        }
    }
    bool good = true;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i + 1 < n && s[i][j] == s[i + 1][j]) good = false;
            if (j + 1 < m && s[i][j] == s[i][j + 1]) good = false;
        }
    }
    if (not good) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
        for (auto& t : s) cout << t << endl;
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    exit(0);
}