#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int k, n, m;
        cin >> k >> n >> m;

        vector<int> a(n), b(m);
        for (auto &i : a) {
            cin >> i;
        }
        for (auto &i : b) {
            cin >> i;
        }

        int i = 0, j = 0;
        vector<int> ans;

        while (i < n || j < m) {
            if (i < n && a[i] <= k) {
                k += a[i] == 0;
                ans.push_back(a[i]);
                ++i;
            } else if (j < m && b[j] <= k) {
                k += b[j] == 0;
                ans.push_back(b[j]);
                ++j;
            } else {
                ans.clear();
                break;
            }
        }

        if (ans.empty()) {
            cout << -1 << "\n";
        } else {
            for (auto i : ans) {
                cout << i << " ";
            }
            cout << "\n";
        }
    }
}