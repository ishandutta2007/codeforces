#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n, k; cin >> n >> k;

        if (k == 1) {
            cout << "YES\n";
            for (int i = 1; i <= n; ++i) cout << i << "\n";
        } else if (n % 2 == 0) {
            cout << "YES\n";
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= k; ++j) {
                    cout << i + (j - 1) * n << " ";
                }
                cout << "\n";
            }
        } else {
            cout << "NO\n";
        }
    }
}