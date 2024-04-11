#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        if (n % 2 == 1) {
            if (k < m / 2 || k % 2 != m / 2 % 2) {
                cout << "NO\n";
            } else {
                cout << "YES\n";
            }
        } else {
            if (k > m / 2 * n || k % 2 == 1) {
                cout << "NO\n";
            } else {
                cout << "YES\n";
            }
        }
    }
}