#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<string> grid(n);
        for (auto &i : grid) {
            cin >> i;
        }

        for (int i = n % 3 != 1; i < n; i += 3) {
            grid[i] = string(m, 'X');
            if (i + 3 < n) {
                int j = m > 1 && (grid[i + 1][1] == 'X' || grid[i + 2][1] == 'X');
                grid[i + 1][j] = grid[i + 2][j] = 'X';
            }
        }

        for (auto &i : grid) {
            cout << i << "\n";
        }
    }
}