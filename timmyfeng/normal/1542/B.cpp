#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;

        bool ok = false;
        long long m = 1;
        do {
            ok |= (n - m) % b == 0;
            m *= a;
        } while (m <= n && a > 1);

        cout << (ok ? "Yes" : "No") << "\n";
    }
}