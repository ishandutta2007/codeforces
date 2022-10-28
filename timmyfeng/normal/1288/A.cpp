#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, n, d;
    cin >> t;
    while (t--) {
        cin >> n >> d;
        bool ok = 0;
        for (int i = sqrt(d) - 1; i < sqrt(d); i++) {
            if (ceil(i + 1.0 * d / (i + 1)) <= n) {
                ok = 1;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}