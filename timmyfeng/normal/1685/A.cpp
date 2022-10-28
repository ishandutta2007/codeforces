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

        if (n % 2) {
            cout << "NO\n";
            continue;
        }

        sort(a.begin(), a.end());

        bool exists = true;
        for (int i = 0; i < n / 2; ++i) {
            exists &= a[i] < a[i ? i + n / 2 - 1 : n / 2];
        }

        if (exists) {
            cout << "YES\n";
            for (int i = 0; i < n / 2; ++i) {
                cout << a[i] << " " << a[i + n / 2] << " ";
            }
            cout << "\n";
        } else {
            cout << "NO\n";
        }
    }
}