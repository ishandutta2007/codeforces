#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        if (n % 2 == 0) {
            cout << (k - 1) % n + 1 << '\n';
        } else {
            cout << (k + (k - 1) / (n / 2) - 1) % n + 1 << '\n';
        }
    }
}