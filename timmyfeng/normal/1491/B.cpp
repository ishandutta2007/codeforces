#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, u, v;
        cin >> n >> u >> v;

        vector<int> a(n);
        for (auto &i : a) {
            cin >> i;
        }

        int delta = 0;
        for (int i = 1; i < n; ++i) {
            delta = max(delta, abs(a[i] - a[i - 1]));
        }

        if (delta == 0) {
            cout << v + min(u, v) << "\n";
        } else if (delta == 1) {
            cout << min(u, v) << "\n";
        } else {
            cout << 0 << "\n";
        }
    }
}