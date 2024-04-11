#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    long long s = 0;
    int l = n / 2, r = n - 1 - l;
    for (int i = 0; i < m; ++i) {
        int x, d; cin >> x >> d;
        s += n * 1ll * x;
        if (d > 0) s += n * 1ll * (n - 1) / 2 * 1ll * d;
        else s += (l * 1ll * (l + 1) / 2 + r * 1ll * (r + 1) / 2) * 1ll * d;
    }
    long double ans = 1.0 * s / n;
    printf("%.20Lf\n", ans);
    return 0;
}