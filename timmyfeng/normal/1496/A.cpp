#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        string s;
        cin >> n >> k >> s;

        bool ok = 2 * k < n;
        for (int i = 0; i < k; ++i) {
            ok &= s[i] == s[n - 1 - i];
        }

        cout << (ok ? "YES" : "NO") << "\n";
    }
}