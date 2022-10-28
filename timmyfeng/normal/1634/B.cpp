#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        long long x, y; cin >> x >> y;

        long long parity_delta = 0;
        for (int i = 0; i < n; ++i) {
            long long a; cin >> a;
            parity_delta ^= a % 2;
        }

        cout << ((x ^ parity_delta) % 2 == y % 2 ? "Alice" : "Bob") << "\n";
    }
}