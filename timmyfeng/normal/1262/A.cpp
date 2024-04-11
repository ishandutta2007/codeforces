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
        int mn = 1e9, mx = 0;
        while (n--) {
            int l, r;
            cin >> l >> r;
            mn = min(mn, r);
            mx = max(mx, l);
        }
        cout << max(mx - mn, 0) << '\n';
    }
}