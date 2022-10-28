#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;

        if (a + b <= n - 2 && abs(a - b) <= 1) {
            vector<int> level_array;
            if (a > b) {
                for (int i = 0; i < a + b + 2; ++i) {
                    level_array.push_back(i % 2);
                }
                for (int i = a + b + 2; i < n; ++i) {
                    level_array.push_back(a + b - i);
                }
            } else if (a == b) {
                for (int i = 0; i < a + b + 2; ++i) {
                    level_array.push_back(i % 2);
                }
                for (int i = a + b + 2; i < n; ++i) {
                    level_array.push_back(i - a - b);
                }
            } else {
                for (int i = 0; i < a + b + 2; ++i) {
                    level_array.push_back(-i % 2);
                }
                for (int i = a + b + 2; i < n; ++i) {
                    level_array.push_back(i - a - b);
                }
            }

            vector<pair<int, int>> positions;
            for (int i = 0; i < n; ++i) {
                positions.push_back({level_array[i], i});
            }

            sort(positions.begin(), positions.end());

            vector<int> perm(n);
            for (int i = 0; i < n; ++i) {
                auto [x, y] = positions[i];
                perm[y] = i + 1;
            }

            for (auto i : perm) {
                cout << i << " ";
            }
            cout << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
}