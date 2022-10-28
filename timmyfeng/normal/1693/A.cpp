#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        vector<long long> a(n);
        for (auto &i : a) cin >> i;

        bool valid = a[0] >= 0;
        for (int i = 1; i < n; ++i) {
            a[i] += a[i - 1];
            valid &= !(!a[i - 1] && a[i]);
            valid &= a[i] >= 0;
        }
        valid &= a[n - 1] == 0;

        cout << (valid ? "Yes" : "No") << "\n";
    }
}