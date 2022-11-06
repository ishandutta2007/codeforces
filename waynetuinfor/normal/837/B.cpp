#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 10;
string s[maxn];

int main() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> s[i];
    int cnt = 0;
    vector<int> l;
    for (int i = 0; i < n - 1; ++i) {
        bool ok = true;
        for (int j = 0; j < m; ++j) if (s[i][j] != s[i][0]) ok = false;
        for (int j = 0; j < m; ++j) if (s[i + 1][j] != s[i + 1][0]) ok = false;
        if (s[i][0] == s[i + 1][0]) ok = false;
        if (ok) l.push_back(i);
    }
    if (l.size() == 2) {
        bool ok = true;
        char a = s[0][0], b = s[l[0] + 1][0], c = s[l[1] + 1][0];
        for (int i = 0; i <= l[0]; ++i) {
            for (int j = 0; j < m; ++j) if (s[i][j] != s[0][0]) ok = false;
        }
        for (int i = l[0] + 1; i <= l[1]; ++i) {
            for (int j = 0; j < m; ++j) if (s[i][j] != s[l[0] + 1][0]) ok = false;
        }
        for (int i = l[1] + 1; i < n; ++i) {
            for (int j = 0; j < m; ++j) if (s[i][j] != s[l[1] + 1][0]) ok = false;
        }
        if (ok && l[0] + 1 == l[1] - l[0] && l[1] - l[0] ==  n - l[1] - 1 && a != b && b != c && a != c) return cout << "YES" << endl, 0;
    }
    cnt = 0; l.clear();
    for (int j = 0; j < m - 1; ++j) {
        bool ok = true;
        for (int i = 0; i < n; ++i) if (s[i][j] != s[0][j]) ok = false;
        for (int i = 0; i < n; ++i) if (s[i][j + 1] != s[0][j + 1]) ok = false;
        if (s[0][j] == s[0][j + 1]) ok = false;
        if (ok) l.push_back(j);
    }
    if (l.size() == 2) {
        bool ok = true;
        char a = s[0][0], b = s[0][l[0] + 1], c = s[0][l[1] + 1];
        for (int j = 0; j <= l[0]; ++j) {
            for (int i = 0; i < n; ++i) if (s[i][j] != s[0][0]) ok = false;
        }
        for (int j = l[0] + 1; j <= l[1]; ++j) {
            for (int i = 0; i < n; ++i) if (s[i][j] != s[0][l[0] + 1]) ok = false;
        }
        for (int j = l[1] + 1; j < m; ++j) {
            for (int i = 0; i < n; ++i) if (s[i][j] != s[0][l[1] + 1]) ok = false;
        }
        if (ok && l[0] + 1 == l[1] - l[0] && l[1] - l[0] == m - l[1] - 1 && a != b && b != c && c != a) return cout << "YES" << endl, 0;
    }
    cout << "NO" << endl;
    return 0;
}