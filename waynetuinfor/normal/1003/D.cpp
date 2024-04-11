#include <bits/stdc++.h>
using namespace std;

int c[40];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q; cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        int j = 0;
        while ((1ll << j) < x) ++j;
        ++c[j];
    }
    while (q--) {
        int x; cin >> x;
        int ans = 0;
        for (int i = 39; i >= 0; --i) {
            int z = min(c[i], (int)(x / (1ll << i)));
            ans += z;
            x -= (1 << i) * z;
        }
        if (x) cout << -1 << endl;
        else cout << ans << endl;
    }
}