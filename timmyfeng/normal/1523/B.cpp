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

        cout << 3 * n << "\n";
        for (int i = 1; i <= n; i += 2) {
            for (auto x : {1, 2, 1, 1, 2, 1}) {
                cout << x << " " << i << " " << i + 1 << "\n";
            }
        }
    }
}