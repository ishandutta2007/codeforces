#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        long long n; cin >> n;

        long long k = 2 * (n & -n);
        if (__int128(k) * (k + 1) / 2 > n) {
            if (n == k / 2) {
                cout << -1 << "\n";
            } else {
                cout << n / (k / 2) << "\n";
            }
        } else {
            cout << k << "\n";
        }
    }
}