#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    vector<int> a, mn;
    while (t--) {
        int n;
        cin >> n;
        int tgt = 0;
        a.resize(2 * n);
        for (auto& i : a) {
            cin >> i;
            if (i == 2) {
                ++tgt;
            } else {
                --tgt;
            }
        }

        mn.assign(4 * n + 1, 1e9);
        mn[2 * n] = 0;
        for (int i = 1, c = 0; i <= n; ++i) {
            if (a[n - i] == 2) {
                ++c;
            } else {
                --c;
            }
            if (mn[c + 2 * n] == 1e9) {
                mn[c + 2 * n] = i;
            }
        }

        int sol = mn[tgt + 2 * n];
        for (int i = 1, c = 0; i <= n; ++i) {
            if (a[n - 1 + i] == 2) {
                ++c;
            } else {
                --c;
            }
            sol = min(sol, i + mn[tgt - c + 2 * n]);
        }
        cout << sol << '\n';
    }
}