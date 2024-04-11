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

        vector<vector<int>> days(m);
        vector<int> used(n + 1);

        for (auto &i : days) {
            int k;
            cin >> k;

            i.resize(k);
            for (auto &j : i) {
                cin >> j;
            }

            if (k == 1) {
                ++used[i[0]];
            }
        }

        if (*max_element(used.begin(), used.end()) > (m + 1) / 2) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
        for (auto &j : days) {
            if (j.size() == 1) {
                cout << j[0] << " ";
            } else {
                for (auto k : j) {
                    if (used[k] < (m + 1) / 2) {
                        cout << k << " ";
                        ++used[k];
                        break;
                    }
                }
            }
        }
        cout << "\n";
    }
}