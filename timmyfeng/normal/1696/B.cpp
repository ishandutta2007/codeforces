#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        vector<int> a(n);
        for (auto &i : a) cin >> i;

        if (count(a.begin(), a.end(), 0) == n) {
            cout << 0 << "\n";
        } else {
            int prefix = 0, suffix = 0;
            while (a[prefix] == 0) ++prefix;
            while (a[n - 1 - suffix] == 0) ++suffix;
            if (count(a.begin(), a.end(), 0) == prefix + suffix) {
                cout << 1 << "\n";
            } else {
                cout << 2 << "\n";
            }
        }
    }
}