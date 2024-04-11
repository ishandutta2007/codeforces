#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    vector<int> row(n);
    vector<int> col(m);
    for (int i = 0; i < n; i++) {
        row[i] = i;
    }
    for (int i = 0; i < m; i++) {
        col[i] = i;
    }
    for (int i = 0; i < q; i++) {
        string foo;
        cin >> foo;
        int x, y;
        cin >> x >> y;
        --x; --y;
        if (foo == "g") {
            cout << a[row[x]][col[y]] << '\n';
        } else {
            if (foo == "r") {
                swap(row[x], row[y]);
            } else {
                swap(col[x], col[y]);
            }
        }
    }
    return 0;
}