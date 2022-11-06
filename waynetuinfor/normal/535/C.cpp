#include <bits/stdc++.h>
using namespace std;

const long long inf = 1e9 + 1;

int main() {
    int a, b, n; cin >> a >> b >> n;
    while (n--) {
        int l, t, m; cin >> l >> t >> m;
        long long r = l - 1;
        long long d = 1; while (d < inf) d <<= 1;
        while (d >>= 1) if (r + d >= l && r + d < inf) {
            long long c = (r + d) * (2ll * a + b * 1ll * (r + d - 1)) / 2 - (l - 1) * 1ll * (2ll * a + b * 1ll * (l - 2)) / 2;
            long long ar = a + b * 1ll * ((r + d) - 1);
            if (ar <= t && c <= m * 1ll * t) r += d;
        }
        if (r == l - 1) cout << "-1" << endl;
        else cout << r << endl;
    }
    return 0;
}