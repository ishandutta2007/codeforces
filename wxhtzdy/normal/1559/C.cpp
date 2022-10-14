#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto& i : a) cin >> i;

    if (a[0] == 1) {
        cout << n + 1 << " ";
        for (int i = 1; i <= n; i++) {
            cout << i << " ";
        }
        return;
    }

    if (a[n - 1] == 0) {
        for (int i = 1; i <= n + 1; i++) {
            cout << i << " ";
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < n; i++) {
        if (a[i] == 0 && a[i + 1] == 1) {
            for (int j = 0; j <= i; j++) {
                cout << j + 1 << " ";
            }
            cout << n + 1 << " ";
            for (int j = i + 1; j < n; j++) {
                cout << j + 1 << " ";
            }
            cout << '\n';
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}