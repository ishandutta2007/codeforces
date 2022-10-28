#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int p;
        cin >> p;
        p %= 2;
        bool ok = true;
        for (int i = 1; i < n; ++i) {
            int a;
            cin >> a;
            if (a % 2 != p) {
                ok = false;
            }
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
}