#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (auto &i : grid) {
        cin >> i;
    }

    int r0 = n - 1, c0 = m - 1, r1 = 0, c1 = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'B') {
                r0 = min(r0, i);
                r1 = max(r1, i);
                c0 = min(c0, j);
                c1 = max(c0, j);
            }
        }
    }

    cout << (r0 + r1) / 2 + 1 << " " << (c0 + c1) / 2 + 1 << "\n";
}