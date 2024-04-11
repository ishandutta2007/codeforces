#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        vector<string> grid(n);
        for (auto &i : grid) cin >> i;

        int answer = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int zeroes = 0, ones = 0;
                int x = i, y = j;
                for (int d = 0; d < 4; ++d) {
                    if (grid[x][y] == '0') ++zeroes;
                    else ++ones;
                    tie(x, y) = make_pair(n - 1 - y, x);
                }
                answer += min(zeroes, ones);
            }
        }

        cout << answer / 4 << "\n";
    }
}