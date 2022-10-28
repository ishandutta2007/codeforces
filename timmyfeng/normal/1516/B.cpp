#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            a[i] ^= a[i - 1];
        }

        if (a[n] == 0) {
            cout << "YES\n";
            continue;
        }

        bool ok = false;
        for (int i = 1; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                ok |= a[i] == (a[j] ^ a[i]) && a[i] == (a[n] ^ a[j]);
            }
        }

        cout << (ok ? "YES" : "NO") << "\n";
    }
}