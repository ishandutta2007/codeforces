#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n, m; cin >> n >> m;

        vector<string> grid(n);
        for (auto &i : grid) cin >> i;

        int low = 0, high = n + m;
        pair<int, int> answer = {-1, -1};
        while (low <= high) {
            int mid = (low + high) / 2;

            int min_x = INT_MIN, max_x = INT_MAX;
            int min_y = INT_MIN, max_y = INT_MAX;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (grid[i][j] == 'B') {
                        int x = i + j, y = i - j;
                        min_x = max(min_x, x - mid);
                        max_x = min(max_x, x + mid);
                        min_y = max(min_y, y - mid);
                        max_y = min(max_y, y + mid);
                    }
                }
            }

            bool ok = false;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    int x = i + j, y = i - j;
                    if (min_x <= x && x <= max_x && min_y <= y && y <= max_y) {
                        ok = true;
                        answer = {i, j};
                    }
                }
            }

            if (ok) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        cout << answer.first  + 1<< " " << answer.second+ 1 << "\n";
    }
}