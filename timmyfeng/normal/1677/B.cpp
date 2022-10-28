#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    string s; cin >> s;

    s = string(n * m, '0') + s;

    vector<int> row(2 * n * m), col(2 * n * m);
    for (int i = n * m; i < 2 * n * m; ++i) {
        row[i] = (s[i] - '0') + row[i - 1] - (s[i - m] - '0');
        col[i] = (s[i] - '0') + col[i - m] - (s[i - n * m] - '0');
    }

    vector<int> sum_rows(2 * n * m), sum_cols(2 * n * m);
    for (int i = n * m; i < 2 * n * m; ++i) {
        sum_rows[i] = (row[i] > 0) + sum_rows[i - m] - (row[i - n * m] > 0);
        sum_cols[i] = (col[i] > 0) + sum_cols[i - 1] - (col[i - m] > 0);
    }

    for (int i = n * m; i < 2 * n * m; ++i) {
        cout << sum_rows[i] + sum_cols[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(true);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) solve();
}