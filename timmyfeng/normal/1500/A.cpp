#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &i : a) {
        cin >> i;
    }

    int k = *max_element(a.begin(), a.end());
    vector<array<int, 2>> pairs(2 * k + 1);

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int k = a[i] + a[j];
            if (pairs[k] == array<int, 2>{0, 0}) {
                pairs[k] = {i + 1, j + 1};
            } else {
                bool disjoint = true;
                for (int u = 0; u < 2; ++u) {
                    for (int v = 0; v < 2; ++v) {
                        disjoint &= pairs[k][u] != array<int, 2>{i, j}[v] + 1;
                    }
                }

                if (disjoint) {
                    cout << "YES\n";
                    cout << pairs[k][0] << " " << pairs[k][1] << " " << i + 1 << " " << j + 1 << "\n";
                    exit(0);
                }
            }
        }
    }

    cout << "NO\n";
}