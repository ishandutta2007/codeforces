#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        vector s(n, vector<int>(n));

        for (auto &i : s) {
            for (auto &j : i) cin >> j;
        }

        int xor_sum = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((i + j) % 4 == 0 && (((i + j) < n && i % 2 == 0) || ((i + j) >= n && i % 2 == 1))) {
                    xor_sum ^= s[i][j];
                    xor_sum ^= s[n - 1 - i][j];
                }
            }
        }

        cout << xor_sum << "\n";
    }
}