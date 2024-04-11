#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int n, m;
        cin >> n >> m;
        int cur = 0;
        int mn = m;
        int mx = m;
        bool ok = true;
        while (n--) {
            int t, l, h;
            cin >> t >> l >> h;
            mn -= t - cur;
            mx += t - cur;
            cur = t;
            if (mn > h || mx < l) {
                ok = false;
            } else {
                mn = max(l, mn);
                mx = min(h, mx);
            }
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
}