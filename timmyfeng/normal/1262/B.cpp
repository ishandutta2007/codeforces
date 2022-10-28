#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<bool> used(n + 1);
        int mn = 1, prev = 0;
        vector<int> ans(n);
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            int q;
            cin >> q;
            if (q > prev) {
                ans[i] = q;
                used[q] = true;
            } else {
                while (used[mn]) {
                    ++mn;
                }
                if (mn > q) {
                    ok = false;
                }
                ans[i] = mn;
                used[mn] = true;
            }
            prev = q;
        }
        if (ok) {
            for (auto i : ans) {
                cout << i << ' ';
            }
            cout << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
}