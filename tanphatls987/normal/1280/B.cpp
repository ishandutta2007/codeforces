#include <bits/stdc++.h>

using namespace std;

int n, m;
string s[70];

void solve() {
    for(int i = 0; i <= n; i++) {
        if (i == n) {
            cout << "MORTAL\n";
            return;
        }
        if (count(s[i].begin(), s[i].end(), 'P') != m) break;
    }
    ///0
    for(int i = 0; i <= n; i++) {
        if (i == n) {
            cout << 0 << '\n';
            return;
        }
        if (count(s[i].begin(), s[i].end(), 'A') != m) break;
    }
    ///1

    for(int i = 0; i <= n; i++) {
        if (i == n) {
            cout << 1 << '\n';
            return;
        }
        if (s[i][0] != 'A') break;
    }
    for(int i = 0; i <= n; i++) {
        if (i == n) {
            cout << 1 << '\n';
            return;
        }
        if (s[i][m - 1] != 'A') break;
    }
    if (count(s[0].begin(), s[0].end(), 'A') == m) {
        cout << 1 << '\n';
        return;
    }
    if (count(s[n - 1].begin(), s[n - 1].end(), 'A') == m) {
        cout << 1 << '\n';
        return;
    }
    if (s[0][0] == 'A' || s[0][m - 1] == 'A' || s[n - 1][0] == 'A' || s[n - 1][m - 1] == 'A' ) {
        cout << 2 << '\n';
        return;
    }
    for(int j = 1; j < m - 1; j++) 
        for(int i = 0; i <= n; i++) {
            if (i == n) {
                cout << 2 << '\n';
                return;
            }
            if (s[i][j] != 'A') break;
        }
    for(int i = 0; i < n; i++)
        if (count(s[i].begin(), s[i].end(), 'A') == m) {
            cout << 2 << '\n';
            return;
        }
    for(int i = 0; i < n; i++) if (s[i][0] == 'A' || s[i][m - 1] == 'A') {
        cout << 3 << '\n';
        return;
    }
    for(int i = 0; i < m; i++) if (s[0][i] == 'A' || s[n - 1][i] == 'A') {
        cout << 3 << '\n';
        return;
    }
    cout << 4 << '\n';
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int test;
    cin >> test;
    while (test--) {
        cin >> n >> m;
        for(int i = 0; i < n; i++) 
            cin >> s[i];
        solve();
    } 
}