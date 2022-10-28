#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n, m; cin >> n >> m;

        vector a(m, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[j][i];
            }
        }

        vector b = a;
        sort(b.begin(), b.end());

        bool sorted = true;
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                sorted &= b[j][i] >= b[j - 1][i];
            }
        }

        vector<int> wrong;
        for (int i = 0; i < m; ++i) {
            if (a[i] != b[i]) wrong.push_back(i);
        }

        if (!sorted || wrong.size() > 2) {
            cout << -1 << "\n";
        } else if (wrong.empty()) {
            cout << 1 << " " << 1 << "\n";
        } else {
            cout << wrong[0] + 1 << " " << wrong[1] + 1 << "\n";
        }
    }
}