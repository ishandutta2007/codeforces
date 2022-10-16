#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m; cin >> n >> m;

    vector<string> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    for (int i = 0; i < n; i += 3) {
        v[i] = string(m, 'X');
    }


    for (int i = 0; i+3 < n; i += 3) {
        if (m < 2 || v[i+1][1] == '.' && v[i+2][1] == '.') {
            v[i+1][0] = v[i+2][0] = 'X';
        } else {
            v[i+1][1] = v[i+2][1] = 'X';
        }
    }

    for (int i = n; i--; ) {
        if (i % 3 == 0) break;

        for (int j = 0; j < m; ++j) {
            if (v[i][j] == 'X') v[i-1][j] = 'X';
        }
    }

    for (auto s : v) cout << s << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while(t--) solve();
}