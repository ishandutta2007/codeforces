#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        bool kraj = false;
        vector<vector<int> > v(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int a;
                cin >> a;
                int tr = 4;
                if (i == 0 || i == n - 1) tr--;
                if (j == 0 || j == m - 1) tr--;
                if (a > tr) {
                    kraj = true;
                }
                v[i][j] = tr;
            }
        }
        if (kraj == true) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
    }
}