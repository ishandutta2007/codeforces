#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        string a, b, c;
        cin >> a >> b >> c;
        bool ok = true;
        for (int i = 0; i < c.size(); i++) {
            if (c[i] != a[i] && c[i] != b[i]) {
                ok = false;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}