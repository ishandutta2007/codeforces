#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        vector<int> a(n);
        for (auto &i : a) cin >> i;

        if (n == 3 && a[1] % 2 == 1) {
            cout << -1 << "\n";
            continue;
        }

        bool valid = false;
        long long moves = 0;
        for (int i = 1; i < n - 1; ++i) {
            valid |= a[i] > 1;
            moves += (a[i] + 1) / 2;
        }

        cout << (valid ? moves : -1) << "\n";
    }
}